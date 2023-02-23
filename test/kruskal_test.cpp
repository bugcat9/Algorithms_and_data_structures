#define BOOST_TEST_MODULE mergeSort
#include "../kruskal.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    // leetcode 1584
    std::vector<std::vector<int>> points({{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}});
    int n = points.size();
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int xi = points[i][0], yi = points[i][1];
            int xj = points[j][0], yj = points[j][1];
            // 用坐标点在 points 中的索引表示坐标点
            edges.push_back({i, j, abs(xi - xj) + abs(yi - yj)});
        }
    }
    int res = kruskal(n, edges);
    BOOST_CHECK_EQUAL(res, 20);
}