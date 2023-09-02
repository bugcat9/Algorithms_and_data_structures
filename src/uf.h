#pragma once
#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief ²¢²é¼¯
*/
class UF
{
public:
	UF(int n);
	~UF();

	int Find(int x);

	void Union(int p, int q);

	int Count();

	bool Connected(int p, int q);

private:
	vector<int> parent_;
	int count_ = 0;
};