#include"dijkstra.h"
#include <queue>

vector<int> Dijkstra(int start, const vector<vector<PII>>& graph)
{
	// ͼ�нڵ�ĸ���
	int n = graph.size();
	// ��¼���·����Ȩ�أ���������Ϊ dp table
	// ���壺distTo[i] ��ֵ���ǽڵ� start ����ڵ� i �����·��Ȩ��
	// ����Сֵ������ dp table ��ʼ��Ϊ������
	vector<int> distTo(n, INT_MAX);
	// base case��start �� start ����̾������ 0
	distTo[start] = 0;

	auto cmp = [&](const auto& a, const auto& b)
	{
		return a.second > b.second;
	};
	// С����
	priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
	// ����� start ��ʼ���� BFS
	pq.push({ start,0 });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int curNodeID = cur.first;
		int curDistFromStart = cur.second;

		if (curDistFromStart > distTo[curNodeID])
		{
			// �Ѿ���һ�����̵�·������ curNode �ڵ���
			continue;
		}
		// �� curNode �����ڽڵ�װ�����
		for (const pair<int, int>& neighbor : graph[curNodeID])
		{
			//auto&& [nextNodeID, weight] = neighbor;
			auto nextNodeID = neighbor.first;
			auto weight = neighbor.second;
			// ������ curNode �ﵽ nextNode �ľ����Ƿ�����
			int distToNextNode = distTo[curNodeID] + weight;
			if (distTo[nextNodeID] > distToNextNode)
			{
				// ���� dp table
				distTo[nextNodeID] = distToNextNode;
				// ������ڵ��Լ�����������
				pq.push({ nextNodeID, distToNextNode });
			}
		}
	}
	return distTo;
}
