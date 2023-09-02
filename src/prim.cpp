#include "prim.h"

int Prim(const vector<vector<int>>& graph)
{
	int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> inMST(n);
	int weight_sum = 0;
	// 随便从一个点开始切分都可以，我们不妨从节点 0 开始
	dist[0] = 0;
	for (int k = 0; k < n; k++)//每次循环选出一个点加入到生成树
	{
		int t = -1;
		for (int j = 0; j < n; j++)//每个节点一次判断
		{
			if (!inMST[j] && (t == -1 || dist[j] < dist[t]))//如果没有在树中，且到树的距离最短，则选择该点
				t = j;
		}

		//如果孤立点，直接返回
		if (dist[t] == INT_MAX) {
			return INT_MAX;
		}


		inMST[t] = true;// 选择该点
		weight_sum += dist[t];
		for (int i = 0; i < n; i++)//更新生成树外的点到生成树的距离
		{
			if (dist[i] > graph[t][i] && !inMST[i])//从 t 到节点 i 的距离小于原来距离，则更新。
			{
				dist[i] = graph[t][i];//更新距离
				// 这里可以记录各个点如何形成树
			}
		}
	}

	return weight_sum;
}
