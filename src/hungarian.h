#pragma once
#include<iostream>
#include<vector>
using namespace std;

/** 
* @brief  二分图的最大匹配 匈牙利算法
* @param graph graph[i] 表示点i的邻居
* @return 
*/
int Hungarian(const vector<vector<int>>& graph);