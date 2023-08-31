#include "kruskal.h"
#include <algorithm>

int Kruskal(int n, vector<vector<int>>& edges)
{
	UF uf(n);
	sort(edges.begin(), edges.end(), [&](auto& a, auto& b)
		{ return a[2] < b[2]; });

	// 记录最小生成树的权重之和
	int mst = 0;
	for (auto& edge : edges)
	{
		int u = edge[0];
		int v = edge[1];
		int weight = edge[2];
		// 若这条边会产生环，则不能加入 mst
		if (uf.Connected(u, v))
		{
			continue;
		}
		// 若这条边不会产生环，则属于最小生成树
		mst += weight;
		uf.Union(u, v);
	}
	// 保证所有节点都被连通
	// 说明所有节点被连通
	return uf.Count() == 1 ? mst : -1;
}
