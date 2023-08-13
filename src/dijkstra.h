#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

/**
 * @brief State 在C++中可以使用pair代替
 *
 */
struct State
{
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart)
    {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};

/**
 * @brief 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
 *
 * @param start
 * @param graph 其中pair first是相邻节点，second 是权重
 * @return vector<int>
 */
vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph)
{
    // 图中节点的个数
    int V = graph.size();
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    // 求最小值，所以 dp table 初始化为正无穷
    vector<int> distTo(V, INT_MAX);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    auto cmp = [&](const auto &a, const auto &b)
    {
        return a.distFromStart > b.distFromStart;
    };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    // 从起点 start 开始进行 BFS
    pq.push(State(start, 0));

    while (!pq.empty())
    {
        State curState = pq.top();
        pq.pop();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID])
        {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (pair<int, int> neighbor : graph[curNodeID])
        {
            auto &&[nextNodeID, weight] = neighbor;
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight;
            if (distTo[nextNodeID] > distToNextNode)
            {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}

/**
 * @brief 输入起点 start 和终点 end，计算起点到终点的最短距离
 *
 * @param start
 * @param end
 * @param graph
 * @return int
 */
int dijkstra(int start, int end, vector<vector<pair<int, int>>> &graph)
{
    // 图中节点的个数
    int V = graph.size();
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    // 求最小值，所以 dp table 初始化为正无穷
    vector<int> distTo(V, INT_MAX);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    auto cmp = [&](const auto &a, const auto &b)
    {
        return a.distFromStart > b.distFromStart;
    };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    // 从起点 start 开始进行 BFS
    pq.push(State(start, 0));

    while (!pq.empty())
    {
        State curState = pq.top();
        pq.pop();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        // 在这里加一个判断就行了，其他代码不用改
        if (curNodeID == end)
        {
            return curDistFromStart;
        }

        if (curDistFromStart > distTo[curNodeID])
        {
            continue;
        }

        // 将 curNode 的相邻节点装入队列
        for (pair<int, int> neighbor : graph[curNodeID])
        {
            auto &&[nextNodeID, weight] = neighbor;
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight;
            if (distTo[nextNodeID] > distToNextNode)
            {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    return INT_MAX;
}

#endif // _DIJKSTRA_H