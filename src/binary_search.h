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
class BinarySearch
{
public:
	int search(vector<int>& nums, int target);

	int left_bound(vector<int>& nums, int target);

	int right_bound(vector<int>& nums, int target);
};

#endif // _BINARYSEARCH_H