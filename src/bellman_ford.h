#pragma once
#include<iostream>
#include<vector>
using namespace std;

using  PII = pair<int, int>;
/**
* @brief  队列优化Bellman-Ford算法——SPFA算法
* 
* @param start
* @param graph 其中pair first是相邻节点，second 是权重
* @return
*/
vector<int> BllmanFord(int start, const vector<vector<PII>>& graph);