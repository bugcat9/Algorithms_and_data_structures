#pragma once
#include<iostream>
#include<vector>
using namespace std;

// 一维前缀和
class PreSum {
public:
	PreSum(vector<int>& nums);

	/* 查询闭区间 [left, right] 的累加和 */
	int Query(int left, int right);
private:
	vector<int> pre_sum_;
};