#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>
using namespace std;

constexpr int R = 256;

/**
 * @brief Trie 树节点实现
 *
 * @tparam V
 */
template <class V>
struct TrieNode
{
    V val;
    vector<TrieNode<V> *> children;
    bool isEnd;
    TrieNode() : children(R, nullptr), isEnd(false)
    {
    }
};

/**
 * @brief 底层用 Trie 树实现的键值映射
 *
 * @tparam V 键为 String 类型，值为类型 V
 */
template <class V>
class TrieMap
{
private:
    int size_;
    TrieNode<V> *root;

    /**
     * @brief 从节点 node 开始搜索 key，如果存在返回对应节点，否则返回 nullptr
     *
     * @param node
     * @param key
     * @return TrieNode<V>*
     */
    TrieNode<V> *getNode(TrieNode<V> *node, const string &key)
    {
        TrieNode<V> *p = node;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < key.size(); i++)
        {
            if (p == nullptr)
            {
                // 无法向下搜索
                return nullptr;
            }
            // 向下搜索
            char c = key[i];
            p = p->children[c];
        }
        return p;
    }

    /**
     * @brief 遍历以 node 节点为根的 Trie 树，找到所有键
     *
     * @param node
     * @param path
     * @param res
     */
    void traverse(TrieNode<V> *node, string &path, vector<string> &res)
    {
        if (node == nullptr)
        {
            // 到达 Trie 树底部叶子结点
            return;
        }

        if (node->isEnd)
        {
            // 找到一个 key，添加到结果列表中
            res.push_back(path);
        }

        // 回溯算法遍历框架
        for (int c = 0; c < R; c++)
        {
            // 做选择
            path.push_back(c);
            traverse(node->children[c], path, res);
            // 撤销选择
            path.pop_back();
        }
    }

    /**
     * @brief 遍历函数，尝试在「以 node 为根的 Trie 树中」匹配 pattern[i..]
     *
     * @param node
     * @param path
     * @param pattern
     * @param i
     * @param res
     */
    void traverse(TrieNode<V> *node, string &path, const string &pattern, int i, vector<string> &res)
    {
        if (node == nullptr)
        {
            // 树枝不存在，即匹配失败
            return;
        }
        if (i == pattern.size())
        {
            // pattern 匹配完成
            if (node->val != nullptr)
            {
                // 如果这个节点存储着 val，则找到一个匹配的键
                res.push_back(path);
            }
            return;
        }
        char c = pattern[i];
        if (c == '.')
        {
            // pattern[i] 是通配符，可以变化成任意字符
            // 多叉树（回溯算法）遍历框架
            for (int j = 0; j < R; j++)
            {
                path.push_back(j);
                traverse(node->children[j], path, pattern, i + 1, res);
                path.pop_back();
            }
        }
        else
        {
            // pattern[i] 是普通字符 c
            path.push_back(c);
            traverse(node->children[c], path, pattern, i + 1, res);
            path.pop_back();
        }
    }

    /**
     * @brief 从 node 节点开始匹配 pattern[i..]，返回是否成功匹配
     *
     * @param node
     * @param pattern
     * @param i
     * @return true
     * @return false
     */
    bool hasKeyWithPattern(TrieNode<V> *node, const string &pattern, int i)
    {
        if (node == nullptr)
        {
            // 树枝不存在，即匹配失败
            return false;
        }
        if (i == pattern.size())
        {
            // 模式串走到头了，看看匹配到的是否是一个键
            return node->isEnd;
        }
        char c = pattern[i];
        // 没有遇到通配符
        if (c != '.')
        {
            // 从 node.children[c] 节点开始匹配 pattern[i+1..]
            return hasKeyWithPattern(node->children[c], pattern, i + 1);
        }
        // 遇到通配符
        for (int j = 0; j < R; j++)
        {
            // pattern[i] 可以变化成任意字符，尝试所有可能，只要遇到一个匹配成功就返回
            if (hasKeyWithPattern(node->children[j], pattern, i + 1))
            {
                return true;
            }
        }
        // 都没有匹配
        return false;
    }

    TrieNode<V> *put(TrieNode<V> *node, const string &key, V val, int i)
    {
        if (node == nullptr)
        {
            // 如果树枝不存在，新建
            node = new TrieNode<V>();
        }
        if (i == key.size())
        {
            // key 的路径已插入完成，将值 val 存入节点
            node->val = val;
            node->isEnd = true;
            return node;
        }
        char c = key[i];
        // 递归插入子节点，并接收返回值
        node->children[c] = put(node->children[c], key, val, i + 1);
        return node;
    }

    TrieNode<V> *remove(TrieNode<V> *node, const string &key, int i)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (i == key.size())
        {
            // 找到了 key 对应的 TrieNode，删除 val
            node->val = V();
            node->isEnd = false;
        }
        else
        {
            char c = key[i];
            // 递归去子树进行删除
            node->children[c] = remove(node->children[c], key, i + 1);
        }
        // 后序位置，递归路径上的节点可能需要被清理
        if (node->isEnd)
        {
            // 如果该 TireNode isEnd 存储着 val，不需要被清理
            return node;
        }
        // 检查该 TrieNode 是否还有后缀
        for (int c = 0; c < R; c++)
        {
            if (node->children[c] != nullptr)
            {
                // 只要存在一个子节点（后缀树枝），就不需要被清理
                return node;
            }
        }
        // 既没有存储 val，也没有后缀树枝，则该节点需要被清理
        delete node;
        return nullptr;
    }

public:
    TrieMap() : size_(0), root(nullptr)
    {
    }
    ~TrieMap()
    {
        if (root != nullptr)
        {
            delete root;
        }
    }
    /***** 增/改 *****/
    /**
     * @brief 在 Map 中添加 key
     *
     * @param key
     * @param val
     */
    void put(const string &key, V val)
    {
        if (!containsKey(key))
        {
            // 新增键值对
            size_++;
        }
        // 需要一个额外的辅助函数，并接收其返回值
        root = put(root, key, val, 0);
    }

    /***** 删 *****/
    /**
     * @brief 删除键 key 以及对应的值
     *
     * @param key
     */
    void remove(const string &key)
    {
        if (!containsKey(key))
        {
            return;
        }
        // 递归修改数据结构要接收函数的返回值
        root = remove(root, key, 0);
        size_--;
    }

    /***** 查 *****/
    /**
     * @brief 搜索 key 对应的值，不存在则返回
     *
     * @param key
     * @return V
     */
    V get(const string &key)
    {
        // 从 root 开始搜索 key
        TrieNode<V> *x = getNode(root, key);
        if (x != nullptr && x->isEnd)
        {
            return x->val;
        }
        // x 为空或 x 的 isEnd 字段为false都说明 key 没有对应的值
        return V();
    }

    /**
     * @brief 判断 key 是否存在在 Map 中
     *
     * @param key
     * @return true
     * @return false
     */
    bool containsKey(const string &key)
    {
        return get(key) != V();
    }

    /**
     * @brief 在 Map 的所有键中搜索 query 的最短前缀
     *
     * @param query
     * @return string
     */
    string shortestPrefixOf(const string &query)
    {
        TrieNode<V> *p = root;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < query.size(); i++)
        {
            if (p == nullptr)
            {
                // 无法向下搜索
                return "";
            }
            if (p->isEnd)
            {
                // 找到一个键是 query 的前缀
                return query.substr(0, i);
            }
            // 向下搜索
            char c = query[i];
            p = p->children[c];
        }

        if (p != nullptr && p->isEnd)
        {
            // 如果 query 本身就是一个键
            return query;
        }
        return "";
    }

    /**
     * @brief 在 Map 的所有键中搜索 query 的最长前缀
     *
     * @param query
     * @return string
     */
    string longestPrefixOf(const string &query)
    {
        TrieNode<V> *p = root;
        // 记录前缀的最大长度
        int max_len = 0;

        // 从节点 node 开始搜索 key
        for (int i = 0; i < query.size(); i++)
        {
            if (p == nullptr)
            {
                // 无法向下搜索
                break;
            }
            if (p->isEnd)
            {
                // 找到一个键是 query 的前缀，更新前缀的最大长度
                max_len = i;
            }
            // 向下搜索
            char c = query[i];
            p = p->children[c];
        }

        if (p != nullptr && p->isEnd)
        {
            // 如果 query 本身就是一个键
            return query;
        }
        return query.substr(0, max_len);
    }

    /**
     * @brief 搜索所有前缀为 prefix 的键
     *
     * @param prefix
     * @return vector<string>
     */
    vector<string> keysWithPrefix(string &prefix)
    {
        vector<string> res;
        // 找到匹配 prefix 在 Trie 树中的那个节点
        TrieNode<V> *x = getNode(root, prefix);
        if (x == nullptr)
        {
            return res;
        }
        // DFS 遍历以 x 为根的这棵 Trie 树
        traverse(x, prefix, res);
        return res;
    }

    /**
     * @brief 判断是否存在前缀为 prefix 的键
     *
     * @param prefix
     * @return true
     * @return false
     */
    bool hasKeyWithPrefix(const string &prefix)
    {
        // 只要能找到 prefix 对应的节点，就是存在前缀
        return getNode(root, prefix) != nullptr;
    }

    /**
     * @brief 通配符 . 匹配任意字符，搜索所有匹配的键
     *
     * @param pattern
     * @return vector<string>
     */
    vector<string> keysWithPattern(const string &pattern)
    {
        vector<string> res;
        string path;
        traverse(root, path, pattern, 0, res);
        return res;
    }

    /**
     * @brief 通配符 . 匹配任意字符，判断是否存在匹配的键
     *
     * @param pattern
     * @return true
     * @return false
     */
    bool hasKeyWithPattern(const string &pattern)
    {
        return hasKeyWithPattern(root, pattern, 0);
    }

    /**
     * @brief 返回 Map 中键值对的数量
     *
     */
    int size()
    {
        return size_;
    }
};
#endif // _TRIE_H