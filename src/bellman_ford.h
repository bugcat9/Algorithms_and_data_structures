#pragma once
#include<iostream>
#include<vector>
using namespace std;

using  PII = pair<int, int>;
/**
* @brief  �����Ż�Bellman-Ford�㷨����SPFA�㷨
* 
* @param start
* @param graph ����pair first�����ڽڵ㣬second ��Ȩ��
* @return
*/
vector<int> BllmanFord(int start, const vector<vector<PII>>& graph);