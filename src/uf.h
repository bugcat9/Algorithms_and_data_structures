#pragma once
#include<iostream>
#include<vector>
using namespace std;

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