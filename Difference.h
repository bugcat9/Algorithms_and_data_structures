#ifndef _DIFFERENCE_H
#define _DIFFERENCE_H

#include <vector>
namespace tiny
{
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

} // namespace tiny

#endif // _DIFFERENCE_H