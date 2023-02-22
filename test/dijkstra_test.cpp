#define BOOST_TEST_MODULE dijkstra
#include "../dijkstra.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    vector<vector<int>> edges({{1, 0, 1}, {1, 2, 1}, {2, 3, 1}});
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
    vector<int> distTo = dijkstra(start, graph);
    BOOST_CHECK_EQUAL(distTo[0], 1);
    BOOST_CHECK_EQUAL(distTo[1], 0);
    BOOST_CHECK_EQUAL(distTo[2], 1);
    BOOST_CHECK_EQUAL(distTo[3], 2);
}

BOOST_AUTO_TEST_CASE(case1)
{
    vector<vector<int>> edges({{1, 0, 1}, {1, 2, 1}, {2, 3, 1}});
    int n = 4;
    vector<vector<pair<int, int>>> graph(n);
    for (auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        graph[from].push_back(make_pair(to, weight));
    }
    int start = 1, end = 3;
    int res = dijkstra(start, end, graph);
    BOOST_CHECK_EQUAL(res, 2);
}