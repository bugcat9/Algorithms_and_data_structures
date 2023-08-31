#pragma once
#include<iostream>
#include<vector>
using namespace std;

/** 
* @brief  判断二分图 染色法
* @param graph graph[i] 表示点i的邻居
* @return 
*/
bool Bipartite(const vector<vector<int>>& graph);