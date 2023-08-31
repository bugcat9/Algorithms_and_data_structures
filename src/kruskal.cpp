#include "kruskal.h"
#include <algorithm>

int Kruskal(int n, vector<vector<int>>& edges)
{
	UF uf(n);
	sort(edges.begin(), edges.end(), [&](auto& a, auto& b)
		{ return a[2] < b[2]; });

	// ��¼��С��������Ȩ��֮��
	int mst = 0;
	for (auto& edge : edges)
	{
		int u = edge[0];
		int v = edge[1];
		int weight = edge[2];
		// �������߻�����������ܼ��� mst
		if (uf.Connected(u, v))
		{
			continue;
		}
		// �������߲������������������С������
		mst += weight;
		uf.Union(u, v);
	}
	// ��֤���нڵ㶼����ͨ
	// ˵�����нڵ㱻��ͨ
	return uf.Count() == 1 ? mst : -1;
}
