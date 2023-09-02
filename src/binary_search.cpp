#include "binary_search.h"

int BinarySearch(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}

int LeftBound(vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (nums[mid] >= target)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}

int RightBound(vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (nums[mid] <= target)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	return l;
}