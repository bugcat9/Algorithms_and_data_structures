#ifndef TINY_BINARY_SEARCH
#define TINY_BINARY_SEARCH

#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <assert.h>
using namespace std;

namespace tiny
{
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

	void test1()
	{
		binarySearch bs;
		vector<int> nums{1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8};
		assert(bs.search(nums, 5) == 4);
		assert(bs.left_bound(nums, 5) == 4);
		assert(bs.right_bound(nums, 6) == 8);
	}
}

#endif