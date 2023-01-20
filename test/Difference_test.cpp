#define BOOST_TEST_MODULE difference
#include "../Difference.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    tiny::Difference df(nums);
    df.increment(1, 3, 1);
    BOOST_CHECK_EQUAL(df.result()[1], 3);
    BOOST_CHECK_EQUAL(df.result()[2], 4);
    BOOST_CHECK_EQUAL(df.result()[3], 5);
}