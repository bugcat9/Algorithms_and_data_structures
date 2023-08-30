#pragma once
#include<iostream>
#include<vector>
using namespace std;

using  PII = pair<int, int>;


/**
 * @brief ����һ��ͼ��һ����� start������ start �������ڵ����̾���
 *
 * @param start
 * @param graph ����pair first�����ڽڵ㣬second ��Ȩ��
 * @return vector<int>
 */
vector<int> Dijkstra(int start, const vector<vector<PII>>& graph);