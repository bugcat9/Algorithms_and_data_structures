#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * @brief 高精度计算，大数加减乘除
 * @param nums1 
 * @param nums2 
 * @return 
*/

vector<int> Add(vector<int>& nums1, vector<int>& nums2);

vector<int> Sub(vector<int>& nums1, vector<int>& nums2);

vector<int> Mul(vector<int>& nums, int num);

vector<int> Div(vector<int>& nums, int b, int& r);



