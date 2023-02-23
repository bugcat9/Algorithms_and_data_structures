#define BOOST_TEST_MODULE mergeSort
#include "../quickSort.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{

    QuickSort quikSort;
    std::vector<int> nums({5, 3, 2, 1, 4, 0});
    quikSort.sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        BOOST_CHECK_EQUAL(nums[i], i);
    }
}