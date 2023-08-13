#include "binary_search.h"

int BinarySearch::search(vector<int>& nums, int target)
{
	// 区间为左闭右开
	int left = 0;
	int right = nums.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			right = mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
	}
	if (left == nums.size())
		return -1;
	return nums[left] == target ? left : -1;
}

int BinarySearch::left_bound(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			right = mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
	}

	if (left == nums.size())
		return -1;
	return nums[left] == target ? left : -1;
}

int BinarySearch::right_bound(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			left = mid + 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
	}

	if (left - 1 < 0)
		return -1;
	return nums[left - 1] == target ? (left - 1) : -1;
}
