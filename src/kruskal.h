#pragma once
#include<iostream>
#include<vector>
#include"uf.h"
using namespace std;

/**
 * @brief kruskal 最小生成树算法
 *
 * @param n
 * @param edges edges[i][j]表示i和j的距离
 * @return int
 */
int Kruskal(int n, vector<vector<int>>& edges);