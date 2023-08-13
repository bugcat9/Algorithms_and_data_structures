#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class TrieSet
{
public:
    TrieSet() : size_(0), root(nullptr)
    {
    }

    ~TrieSet()
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
    void put(const string &key)
    {
        if (!containsKey(key))
        {
            // 新增键值对
            size_++;
        }
        // 需要一个额外的辅助函数，并接收其返回值
        root = put(root, key, 0);
    }

    /***** 查 *****/

    /**
     * @brief 判断 key 是否存在在 Map 中
     *
     * @param key
     * @return true
     * @return false
     */
    bool containsKey(const string &key)
    {
        // 从 root 开始搜索 key
        TrieNode *x = getNode(root, key);
        if (x != nullptr && x->isEnd)
        {
            return true;
        }
        return false;
    }

    /**
     * @brief 在 Map 的所有键中搜索 query 的最短前缀
     *
     * @param query
     * @return bool
     */
    bool shortestPrefixOf(const string &query)
    {
        TrieNode *p = root;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < query.size(); i++)
        {
            if (p == nullptr)
            {
                // 无法向下搜索
                return false;
            }
            if (p->isEnd)
            {
                // 找到一个键是 query 的前缀
                return true;
            }
            // 向下搜索
            int c = query[i] - 'a';
            p = p->children[c];
        }

        if (p != nullptr && p->isEnd)
        {
            // 如果 query 本身就是一个键
            return true;
        }
        return false;
    }

private:
    TrieNode *put(TrieNode *node, const string &key, int i)
    {
        if (node == nullptr)
        {
            // 如果树枝不存在，新建
            node = new TrieNode();
        }
        if (i == key.size())
        {
            // key 的路径已插入完成，将值 val 存入节点
            // node->val = val;
            node->isEnd = true;
            return node;
        }
        int c = key[i] - 'a';
        // 递归插入子节点，并接收返回值
        node->children[c] = put(node->children[c], key, i + 1);
        return node;
    }

    /**
     * @brief 从节点 node 开始搜索 key，如果存在返回对应节点，否则返回 nullptr
     *
     * @param node
     * @param key
     * @return TrieNode<V>*
     */
    TrieNode *getNode(TrieNode *node, const string &key)
    {
        TrieNode *p = node;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < key.size(); i++)
        {
            if (p == nullptr)
            {
                // 无法向下搜索
                return nullptr;
            }
            // 向下搜索
            int c = key[i] - 'a';
            p = p->children[c];
        }
        return p;
    }

private:
    int size_;
    TrieNode *root;
};
