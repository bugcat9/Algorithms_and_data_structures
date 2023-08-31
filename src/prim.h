#pragma once
#include<iostream>
#include<vector>
using namespace std;

/** 
* @brief 最小生成树  
* @param graph  graph[i][j]代表第i个点到第j个点的距离
* @return 最小生成树的距离
*/
int Prim(const vector<vector<int>>& graph);