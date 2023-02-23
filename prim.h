#ifndef _PRIM_H
#define _PRIM_H
#include <queue>
#include <vector>
using namespace std;

struct cmp
{
    bool operator()(const vector<int> &edge1, const vector<int> &edge2)
    {
        // 按照边的权重从小到大排序
        return edge1[2] > edge2[2];
    }
};

class Prim
{
private:
    // 核心数据结构，存储「横切边」的优先级队列
    using PQ = priority_queue<vector<int>, vector<vector<int>>, cmp>;
    PQ pq;
    // 类似 visited 数组的作用，记录哪些节点已经成为最小生成树的一部分
    vector<bool> inMST;
    // 记录最小生成树的权重和
    int weightSum;
    // graph 是用邻接表表示的一幅图，
    // graph[s] 记录节点 s 所有相邻的边，
    // 三元组 int[]{from, to, weight} 表示一条边
    vector<vector<vector<int>>> graph;

    /**
     * @brief 将 s 的横切边加入优先队列
     *
     * @param s
     */
    void cut(int s)
    {
        for (auto &edge : graph[s])
        {
            int to = edge[1];
            if (inMST[to])
            {
                continue;
            }
            pq.push(edge);
        }
    }

public:
    Prim(const vector<vector<vector<int>>> &graph) : graph(graph)
    {
        int n = graph.size();
        inMST.resize(n);
        weightSum = 0;
        // 随便从一个点开始切分都可以，我们不妨从节点 0 开始
        inMST[0] = true;
        cut(0);
        // 不断进行切分，向最小生成树中添加边
        while (!pq.empty())
        {
            vector<int> edge = pq.top();
            pq.pop();
            int to = edge[1];
            int weight = edge[2];
            if (inMST[to])
            {
                // 节点 to 已经在最小生成树中，跳过
                // 否则这条边会产生环
                continue;
            }
            // 将边 edge 加入最小生成树
            weightSum += weight;
            inMST[to] = true;
            // 节点 to 加入后，进行新一轮切分，会产生更多横切边
            cut(to);
        }
    }

    /**
     * @brief 最小生成树的权重和
     * 
     * @return int 
     */
    int getWeightSum()
    {
        return weightSum;
    }

    /**
     * @brief 判断最小生成树是否包含图中的所有节点
     * 
     * @return true 
     * @return false 
     */
    bool allConnected()
    {
        for (int i = 0; i < inMST.size(); i++)
        {
            if (!inMST[i])
            {
                return false;
            }
        }
        return true;
    }
};

#endif // _PRIM_H