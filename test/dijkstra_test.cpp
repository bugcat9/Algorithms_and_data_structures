#include "dijkstra.h"
#include <gtest/gtest.h>

TEST(Dijkstra, case0) {
	vector<vector<int>> edges({ {1, 0, 1}, {1, 2, 1}, {2, 3, 1} });
	int n = 4;
	vector<vector<pair<int, int>>> graph(n);
	for (auto edge : edges)
	{
		int from = edge[0];
		int to = edge[1];
		int weight = edge[2];
		graph[from].push_back(make_pair(to, weight));
	}
	int start = 1;
	vector<int> distTo = Dijkstra(start, graph);
	EXPECT_EQ(distTo[0], 1);
	EXPECT_EQ(distTo[1], 0);
	EXPECT_EQ(distTo[2], 1);
	EXPECT_EQ(distTo[3], 2);
}
