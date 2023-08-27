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
	 * @brief 26����26����ĸ
	*/
	TrieNode() : children(26, nullptr), is_end(false)
	{
	}
};

/**
 * @brief �ֵ���
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