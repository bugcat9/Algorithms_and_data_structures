#define BOOST_TEST_MODULE binary
#include "../binarySearch.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    binarySearch bs;
    vector<int> nums{1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8};
    BOOST_CHECK_EQUAL(bs.search(nums, 5), 4);
    BOOST_CHECK_EQUAL(bs.left_bound(nums, 5), 4);
    BOOST_CHECK_EQUAL(bs.right_bound(nums, 6), 8);
}