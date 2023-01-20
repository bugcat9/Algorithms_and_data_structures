#define BOOST_TEST_MODULE binary
#include "../preSum.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    tiny::NumArray numArray(v);
    BOOST_CHECK_EQUAL(numArray.sumRange(0, 0), 2);
    BOOST_CHECK_EQUAL(numArray.sumRange(0, 1), 4);
    BOOST_CHECK_EQUAL(numArray.sumRange(1, 4), 8);
    // 使用 partial_sum
    vector<int> v2;
    std::partial_sum(v.begin(), v.end(), back_inserter(v2));
    BOOST_CHECK_EQUAL(v2[0], 2);
    BOOST_CHECK_EQUAL(v2[1], 4);
    BOOST_CHECK_EQUAL(v2[2], 6);
}
