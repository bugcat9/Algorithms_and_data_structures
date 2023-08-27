#include"merge_sort.h"

vector<int> tmp(1000000);
void MergeSort(vector<int>& nums, int l, int r)
{
	if (l >= r) return;

	int mid = l + (r - l) >> 1;
	MergeSort(nums, l, mid);
	MergeSort(nums, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (nums[i] <= nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}


	while (i <= mid) tmp[k++] = nums[i++];
	while (j <= r) tmp[k++] = nums[j++];

	for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
}