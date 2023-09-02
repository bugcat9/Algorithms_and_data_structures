#include "bipartite.h"

// 参数：u表示当前节点，c表示当前点的颜色
bool dfs(int u, int c, const vector<vector<int>>& graph, vector<int>& color)
{
	color[u] = c;        // 染色
	for (auto& j : graph[u])
	{
		if (!color[j])
		{
			if (!dfs(j, 3 - c, graph, color)) return false;       // 用3-c实现交替染色
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
			if (!dfs(i, 1, graph, color))// 这里不需要3-c，因为这里进入的都是未染色的起点，换句话说是森林另一棵树的根
			{
				flag = false;
				break;
			}
	return flag;
}
