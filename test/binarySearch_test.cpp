#define BOOST_TEST_MODULE binary
#include "../binarySearch.h"
#include <algorithm>
#include <iterator>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    binarySearch bs;
    vector<int> nums{1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8};
    BOOST_CHECK_EQUAL(bs.search(nums, 5), 4);
    BOOST_CHECK_EQUAL(binary_search(nums.begin(), nums.end(), 5), true);
    BOOST_CHECK_EQUAL(bs.left_bound(nums, 5), 4);
    BOOST_CHECK_EQUAL(bs.right_bound(nums, 5), 6);
    BOOST_CHECK_EQUAL(bs.right_bound(nums, 6), 8);

    // 指向范围 [first, last) 中首个不满足 element < value 或 comp(element, value) 的元素的迭代器，或者在找不到这种元素时返回 last。
    auto lower = lower_bound(nums.begin(), nums.end(), 5);
    BOOST_CHECK_EQUAL(std::distance(nums.begin(), lower), 4);
    // 指向首个大于 value 的元素的迭代器，或若找不到这种元素则为 last 。
    auto upper = upper_bound(nums.begin(), nums.end(), 5);
    BOOST_CHECK_EQUAL(std::distance(nums.begin(), upper), 7);
}