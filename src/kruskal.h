#pragma once
#include<iostream>
#include<vector>
#include"uf.h"
using namespace std;

/**
 * @brief kruskal ��С�������㷨
 *
 * @param n
 * @param edges edges[i][j]��ʾi��j�ľ���
 * @return int
 */
int Kruskal(int n, vector<vector<int>>& edges);