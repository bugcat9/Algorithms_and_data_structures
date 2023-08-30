#pragma once
#include<iostream>
#include<vector>
using namespace std;

/** 
* @brief 多源最短路径  
* @param dist[i][j] 代表第i个点到第j个点的距离，如果无法到达距离为INT_MAX
*/
void Floyd(vector<vector<int>>& dist);