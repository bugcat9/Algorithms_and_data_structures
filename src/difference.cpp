#include "difference.h"

Difference::Difference(vector<int> nums)
{
	int size = nums.size();
	diff_.resize(size);

	for (int i = 1; i < size; i++)
	{
		diff_[i] = nums[i] - nums[i - 1];
	}
}

void Difference::Increment(int i, int j, int val)
{
	diff_[i] += val;
	if (j + 1 < diff_.size()) {
		diff_[j + 1] -= val;
	}
}

vector<int> Difference::Result()
{
	vector<int> res(diff_.size());
	res[0] = diff_[0];
	for (int i = 1; i < diff_.size(); i++) {
		res[i] = res[i - 1] + diff_[i];
	}
	return res;
}
