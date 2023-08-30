#pragma once
#include<iostream>
#include<vector>
using namespace std;

using  PII = pair<int, int>;


/**
 * @brief 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
 *
 * @param start
 * @param graph 其中pair first是相邻节点，second 是权重
 * @return vector<int>
 */
vector<int> Dijkstra(int start, const vector<vector<PII>>& graph);