#include"bellman_ford.h"
#include <queue>

vector<int> BllmanFord(int start, const vector<vector<PII>>& graph)
{
	// ͼ�нڵ�ĸ���
	int n = graph.size();
	// ��¼���·����Ȩ�أ���������Ϊ dp table
	// ���壺distTo[i] ��ֵ���ǽڵ� start ����ڵ� i �����·��Ȩ��
	// ����Сֵ������ dp table ��ʼ��Ϊ������
	vector<int> dist(n, INT_MAX);
	// base case��start �� start ����̾������ 0
	dist[start] = 0;
	// �洢ÿ�����Ƿ��ڶ�����
	vector<bool> visit;
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		// �ѳ��ӣ���˶��в��ٰ�������t����Ҫ����Ϊfalse
		visit[cur] = false;

		for (const pair<int, int>& neighbor : graph[cur])
		{
			//auto&& [nextNodeID, weight] = neighbor;
			auto nextNodeID = neighbor.first;
			auto weight = neighbor.second;
			if (dist[nextNodeID] > dist[cur] + weight)
			{
				dist[nextNodeID] = dist[cur] + weight;
				if (!visit[nextNodeID])     // ����������Ѵ���nextNodeID������Ҫ��nextNodeID�ظ�����
				{
					q.push(nextNodeID);
					visit[nextNodeID] = true;
				}
			}
		}
	}

	return dist;
}
