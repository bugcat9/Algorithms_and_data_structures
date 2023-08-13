#ifndef _KRUSKAL_H
#define _KRUSKAL_H
#include "UF.h"
#include <algorithm>
using namespace std;

/**
 * @brief kruskal 最小生成树算法
 *
 * @param n
 * @param edges
 * @return int
 */
int kruskal(int n, vector<vector<int>> edges)
{
    // 城市编号为 0...n-1
    UF uf(n);
    // 对所有边按照权重从小到大排序
    sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
         { return a[2] < b[2]; });
    // 记录最小生成树的权重之和
    int mst = 0;
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        // 若这条边会产生环，则不能加入 mst
        if (uf.connected(u, v))
        {
            continue;
        }
        // 若这条边不会产生环，则属于最小生成树
        mst += weight;
        uf.unionNode(u, v);
    }
    // 保证所有节点都被连通
    // 说明所有节点被连通
    return uf.count() == 1 ? mst : -1;
}

#endif // _KRUSKAL_H