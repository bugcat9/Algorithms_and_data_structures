#include"trie.h"

Trie::Trie()
{
	root_ = new TrieNode;
}

Trie::~Trie()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

void Trie::Insert(const string& key, int val)
{
	TrieNode* node = root_;
	for (int i = 0; i < key.size(); i++)
	{
		int c = key[i] - 'a';
		if (node->children[c] == nullptr)
		{
			node->children[c] = new TrieNode;
		}
		node = node->children[c];
	}
	node->val = val;
	node->is_end = true;
}

bool Trie::ContainsKey(const string& key)
{
	TrieNode* node = root_;
	for (int i = 0; i < key.size(); i++)
	{
		int c = key[i] - 'a';
		if (node->children[c] == nullptr)
		{
			return false;
		}
		node = node->children[c];
	}

	if (node->is_end)
	{
		return true;
	}
	return false;
}

int Trie::Query(const string& key)
{
	TrieNode* node = root_;
	for (int i = 0; i < key.size(); i++)
	{
		int c = key[i] - 'a';
		if (node->children[c] == nullptr)
		{
			return false;
		}
		node = node->children[c];
	}

	return node->val;
}
