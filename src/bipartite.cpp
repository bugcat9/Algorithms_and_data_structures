#include "bipartite.h"

// ������u��ʾ��ǰ�ڵ㣬c��ʾ��ǰ�����ɫ
bool dfs(int u, int c, const vector<vector<int>>& graph, vector<int>& color)
{
	color[u] = c;       // Ⱦɫ
	for (auto& j : graph[u])
	{
		if (!color[j])
		{
			if (!dfs(j, 3 - c, graph, color)) return false;       // ��3-cʵ�ֽ���Ⱦɫ
		}
		else if (color[j] == c) return false;
	}

	return true;
}

bool Bipartite(const vector<vector<int>>& graph)
{
	bool flag = true;
	int n = graph.size();
	vector<int> color(n);
	for (int i = 0; i < n; i++)
		if (!color[i])
			if (!dfs(i, 1, graph, color))     // ���ﲻ��Ҫ3-c����Ϊ�������Ķ���δȾɫ����㣬���仰˵��ɭ����һ�����ĸ�
			{
				flag = false;
				break;
			}
	return flag;
}
