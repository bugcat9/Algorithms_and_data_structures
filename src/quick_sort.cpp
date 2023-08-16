#include"quick_sort.h"

void QuickSort(vector<int>& nums, int l, int r)
{
	if (l >= r)return;

	int i = l - 1, j = r + 1, x = nums[l + (r - l) >> 1];
	while (i < j)
	{
		do i++; while (nums[i] < x);
		do j--; while (nums[j] > x);
		if (i < j) swap(nums[i], nums[j]);
	}
	QuickSort(nums, l, j);
	QuickSort(nums, j + 1, r);
}