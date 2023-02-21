#ifndef _DIFFERENCE_H
#define _DIFFERENCE_H

#include <vector>

/**
 * @brief 差分数组，用来求区间加减
 * 
 */
class Difference
{
private:
    std::vector<int> diff;

public:
    Difference(std::vector<int> nums)
    {
        {
            diff.resize(nums.size());
            diff[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                diff[i] = nums[i] - nums[i - 1];
            }
        }
    }

    void increment(int i, int j, int val)
    {
        diff[i] += val;
        if (j + 1 < diff.size())
        {
            diff[j + 1] -= val;
        }
    }

    std::vector<int> result()
    {
        std::vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
        {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

#endif // _DIFFERENCE_H