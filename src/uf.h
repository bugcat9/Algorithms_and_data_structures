#ifndef _UF_H
#define _UF_H
#include <vector>

/**
 * @brief 并查集
 *
 */
class UF
{
private:
    // 连通分量个数
    int count_;
    // 存储每个节点的父节点
    std::vector<int> parent;

public:
    /**
     * @brief Construct a new UF object
     *
     * @param n 图中节点个数
     */
    UF(int n) : parent(n), count_(n)
    {
        for (size_t i = 0; i < count_; i++)
        {
            parent[i] = i;
        }
    }

    /**
     * @brief 将节点 p 和节点 q 连通
     *
     * @param p
     * @param q
     */
    void unionNode(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ)
            return;

        parent[rootQ] = rootP;
        // 两个连通分量合并成一个连通分量
        count_--;
    }

    /**
     * @brief 判断节点 p 和节点 q 是否连通
     *
     * @param p
     * @param q
     * @return true
     * @return false
     */
    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    /**
     * @brief 返回 x的父节点
     *  find中进行了路径压缩，保证任意树的高度保持在常数
     *
     * @param x
     * @return int
     */
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    /**
     * @brief 返回图中的连通分量个数
     *
     * @return int
     */
    int count()
    {
        return count_;
    }
};

#endif // _UF_H