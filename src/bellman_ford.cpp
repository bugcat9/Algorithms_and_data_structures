#include"bellman_ford.h"
#include <queue>

vector<int> BllmanFord(int start, const vector<vector<PII>>& graph)
{
	// 图中节点的个数
	int n = graph.size();
	// 记录最短路径的权重，你可以理解为 dp table
	// 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
	// 求最小值，所以 dp table 初始化为正无穷
	vector<int> dist(n, INT_MAX);
	// base case，start 到 start 的最短距离就是 0
	dist[start] = 0;
	// 存储每个点是否在队列中
	vector<bool> visit;
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		// 已出队，因此队列不再包含顶点t，需要重置为false
		visit[cur] = false;

		for (const pair<int, int>& neighbor : graph[cur])
		{
			//auto&& [nextNodeID, weight] = neighbor;
			auto nextNodeID = neighbor.first;
			auto weight = neighbor.second;
			if (dist[nextNodeID] > dist[cur] + weight)
			{
				dist[nextNodeID] = dist[cur] + weight;
				if (!visit[nextNodeID])     // 如果队列中已存在nextNodeID，则不需要将nextNodeID重复插入
				{
					q.push(nextNodeID);
					visit[nextNodeID] = true;
				}
			}
		}
	}

	return dist;
}