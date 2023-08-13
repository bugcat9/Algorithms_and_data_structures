#ifndef _LRU_H
#define _LRU_H
#include <unordered_map>
#include <list>
using namespace std;

/**
 * @brief Least Recently Used
 * 
 */
class LRUCache
{
public:
    LRUCache(int capacity) : cap(capacity)
    {
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;
        auto key_value = *map[key];
        cache.erase(map[key]);
        cache.push_front(key_value);
        map[key] = cache.begin();
        return key_value.second;
    }

    void put(int key, int value)
    {
        if (map.find(key) == map.end())
        {
            if (cache.size() == cap)
            {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else
        {
            cache.erase(map[key]);
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }

private:
    int cap;
    // 链表存储数据，链表头部是最近访问的数据
    // pair中first是key，second是value
    list<pair<int, int>> cache;
    // map中存储的是 key对应的链表位置的迭代器
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

#endif // _LRU_H