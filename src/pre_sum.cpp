#include "pre_sum.h"

PreSum::PreSum(vector<int>& nums)
{
	int n = nums.size();
	pre_sum_.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		pre_sum_[i] = pre_sum_[i - 1] + nums[i - 1];
	}
}

int PreSum::Query(int left, int right)
{
	return pre_sum_[right + 1] - pre_sum_[left];
}
