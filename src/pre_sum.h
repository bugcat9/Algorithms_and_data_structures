#pragma once
#include<iostream>
#include<vector>
using namespace std;

// һάǰ׺��
class PreSum {
public:
	PreSum(vector<int>& nums);

	/* ��ѯ������ [left, right] ���ۼӺ� */
	int Query(int left, int right);
private:
	vector<int> pre_sum_;
};