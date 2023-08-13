#define BOOST_TEST_MODULE rabinkarp
#include "../rabinKarp.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    string txt = "sadbutsad";
    string pat = "sad";
    BOOST_CHECK_EQUAL(rabinKarp(txt, pat), 0);
    pat = "sadc";
    BOOST_CHECK_EQUAL(rabinKarp(txt, pat), -1);
}