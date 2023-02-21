#ifndef _BINARYSEARCH_H
#define _BINARYSEARCH_H

#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
using namespace std;

/**
 * @brief 二分查找
 * 
 */
class binarySearch
{
public:
	int search(vector<int> &nums, int target)
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

	int left_bound(vector<int> &nums, int target)
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

	int right_bound(vector<int> &nums, int target)
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
};

#endif // _BINARYSEARCH_H