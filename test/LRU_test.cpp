#define BOOST_TEST_MODULE lru
#include "../LRU.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);                     // 缓存是 {1=1}
    lRUCache.put(2, 2);                     // 缓存是 {1=1, 2=2}
    BOOST_CHECK_EQUAL(lRUCache.get(1), 1);  // 返回 1
    lRUCache.put(3, 3);                     // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    BOOST_CHECK_EQUAL(lRUCache.get(2), -1); // 返回 -1 (未找到)
    lRUCache.put(4, 4);                     // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    BOOST_CHECK_EQUAL(lRUCache.get(1), -1); // 返回 -1 (未找到)
    BOOST_CHECK_EQUAL(lRUCache.get(3), 3);  // 返回 3
    BOOST_CHECK_EQUAL(lRUCache.get(4), 4); // 返回 4
}