#include"dijkstra.h"
#include <queue>
#include <limits.h>

vector<int> Dijkstra(int start, const vector<vector<PII>>& graph)
{
	// 图中节点的个数
	int n = graph.size();
	// 记录最短路径的权重，你可以理解为 dp table
	// 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
	// 求最小值，所以 dp table 初始化为正无穷
	vector<int> distTo(n, INT_MAX);
	// base case，start 到 start 的最短距离就是 0
	distTo[start] = 0;

	auto cmp = [&](const auto& a, const auto& b)
	{
		return a.second > b.second;
	};
	// 小根堆
	priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
	// 从起点 start 开始进行 BFS
	pq.push({ start,0 });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curNodeID = cur.first;
		int curDistFromStart = cur.second;

		if (curDistFromStart > distTo[curNodeID])
		{
			// 已经有一条更短的路径到达 curNode 节点了
			continue;
		}
		// 将 curNode 的相邻节点装入队列
		for (const pair<int, int>& neighbor : graph[curNodeID])
		{
			//auto&& [nextNodeID, weight] = neighbor;
			auto nextNodeID = neighbor.first;
			auto weight = neighbor.second;
			// 看看从 curNode 达到 nextNode 的距离是否会更短
			int distToNextNode = distTo[curNodeID] + weight;
			if (distTo[nextNodeID] > distToNextNode)
			{
				// 更新 dp table
				distTo[nextNodeID] = distToNextNode;
				// 将这个节点以及距离放入队列
				pq.push({ nextNodeID, distToNextNode });
			}
		}
	}
	return distTo;
}
