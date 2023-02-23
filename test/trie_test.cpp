#define BOOST_TEST_MODULE trie
#include "../trie.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    TrieMap<int> map;
    map.put("apple", 10);
    BOOST_CHECK_EQUAL(map.containsKey("apple"), true);
    BOOST_CHECK_EQUAL(map.containsKey("app"), false);
    BOOST_CHECK_EQUAL(map.get("apple"), 10);
    BOOST_CHECK_EQUAL(map.get("app"), 0);
    BOOST_CHECK_EQUAL(map.hasKeyWithPrefix("app"), true);
    map.put("app", 5);
    BOOST_CHECK_EQUAL(map.hasKeyWithPattern("appl."), true);
    BOOST_CHECK_EQUAL(map.hasKeyWithPrefix("appl"), true);
    BOOST_CHECK_EQUAL(map.longestPrefixOf("apple10"), "apple");
    BOOST_CHECK_EQUAL(map.shortestPrefixOf("apple10"), "app");
    string prefix = "ap";
    vector<string> x = map.keysWithPrefix(prefix);
    BOOST_CHECK_EQUAL(x[0], "app");
    BOOST_CHECK_EQUAL(x[1], "apple");
}