#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TrieNode
{
	int val = 0;
	bool is_end = false;
	vector<TrieNode*> children;
	/**
	 * @brief 26代表26个字母
	*/
	TrieNode() : children(26, nullptr), is_end(false)
	{
	}
};

/**
 * @brief 字典树
*/
class Trie
{
public:
	Trie();
	~Trie();

	void Insert(const string& key, int val);

	bool ContainsKey(const string& key);

	int Query(const string& key);

private:
	TrieNode* root_ = nullptr;;

};