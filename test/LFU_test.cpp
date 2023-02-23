#define BOOST_TEST_MODULE lfu
#include "../LFU.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    // leetcode 460
    LFUCache lfu(2);
    lfu.put(1, 1);                     // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);                     // cache=[2,1], cnt(2)=1, cnt(1)=1
    BOOST_CHECK_EQUAL(lfu.get(1), 1);  // 返回 1
                                       // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);                     // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                                       // cache=[3,1], cnt(3)=1, cnt(1)=2
    BOOST_CHECK_EQUAL(lfu.get(2), -1); // 返回 -1（未找到）
    BOOST_CHECK_EQUAL(lfu.get(3), 3);  // 返回 3
                                       // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);                     // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                                       // cache=[4,3], cnt(4)=1, cnt(3)=2
    BOOST_CHECK_EQUAL(lfu.get(1), -1); // 返回 -1（未找到）
    BOOST_CHECK_EQUAL(lfu.get(3), 3);  // 返回 3
                                       // cache=[3,4], cnt(4)=1, cnt(3)=3
    BOOST_CHECK_EQUAL(lfu.get(4), 4);  // 返回 4
                                       // cache=[3,4], cnt(4)=2, cnt(3)=3
}