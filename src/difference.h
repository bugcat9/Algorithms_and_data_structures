#pragma once
#include<vector>
using namespace std;

class Difference
{
public:
	Difference(vector<int> nums);

	void Increment(int i, int j, int val);

	vector<int> Result();
private:
	vector<int> diff_;
};