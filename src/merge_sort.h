#ifndef _MERGESORT_H
#define _MERGESORT_H

#include <vector>
/**
 * @brief 归并排序
 *  归并排序其实就是树的后序遍历
 *
 */
class MergeSort
{
private:
    // 用于辅助合并有序数组
    std::vector<int> temp;

    void sort(std::vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
        {
            // 单个元素不用排序
            return;
        }
        // 这样写是为了防止溢出，效果等同于 (hi + lo) / 2
        int mid = lo + (hi - lo) / 2;
        // 先对左半部分数组 nums[lo..mid] 排序
        sort(nums, lo, mid);
        // 再对右半部分数组 nums[mid+1..hi] 排序
        sort(nums, mid + 1, hi);
        // 将两部分有序数组合并成一个有序数组
        merge(nums, lo, mid, hi);
    }

    void merge(std::vector<int> &nums, int lo, int mid, int hi)
    { // 先把 nums[lo..hi] 复制到辅助数组中
        // 以便合并后的结果能够直接存入 nums
        for (int i = lo; i <= hi; i++)
        {
            temp[i] = nums[i];
        }

        // 数组双指针技巧，合并两个有序数组
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++)
        {
            if (i == mid + 1)
            {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            }
            else if (j == hi + 1)
            {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
            }
            else if (temp[i] > temp[j])
            {
                nums[p] = temp[j++];
            }
            else
            {
                nums[p] = temp[i++];
            }
        }
    }

public:
    void sort(std::vector<int> &nums)
    {
        int n = nums.size();
        temp.resize(n);
        // 排序整个数组（原地修改）
        sort(nums, 0, n - 1);
    }
};

#endif // _MERGESORT_H