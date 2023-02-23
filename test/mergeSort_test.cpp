#define BOOST_TEST_MODULE mergeSort
#include "../mergeSort.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{

    MergeSort mergesort;
    std::vector<int> nums({5, 3, 2, 1, 4, 0});
    mergesort.sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        BOOST_CHECK_EQUAL(nums[i], i);
    }
}