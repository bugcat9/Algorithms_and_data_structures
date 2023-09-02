#include"hungarian.h"

bool find(const vector<vector<int>>& graph, int x, vector<int>& match, vector<bool> visit)
{
	for (auto& j : graph[x])
	{
		if (!visit[j])
		{
			visit[j] = true;                           // 标记已遍历
			if (!match[j] || find(graph, match[j], match, visit))          // j未被匹配，或j已经匹配但其配对对象可选其它的匹配
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int Hungarian(const vector<vector<int>>& graph)
{
	int res = 0;
	int n = graph.size();
	// 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
	vector<int> match(n);
	for (int i = 0; i < n; i++)
	{
		vector<bool> visit(n);
		if (find(graph, i, match, visit)) res++;
	}
	return res;
}
