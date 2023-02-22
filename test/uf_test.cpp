#define BOOST_TEST_MODULE uf
#include "../UF.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    UF uf(4);
    BOOST_CHECK_EQUAL(uf.connected(0, 1), false);
    BOOST_CHECK_EQUAL(uf.count(), 4);
    uf.unionNode(0, 1);
    BOOST_CHECK_EQUAL(uf.connected(0, 1), true);
    BOOST_CHECK_EQUAL(uf.count(), 3);
    uf.unionNode(1, 3);
    BOOST_CHECK_EQUAL(uf.connected(0, 2), false);
    BOOST_CHECK_EQUAL(uf.connected(0, 3), true);
    BOOST_CHECK_EQUAL(uf.count(), 2);
}