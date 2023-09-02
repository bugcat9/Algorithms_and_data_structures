#pragma once
#include<iostream>
#include<vector>
using namespace std;

/** 
* @brief 判断质数
* @param x  
* @return 
*/
bool IsPrime(int x);

/** 
* @brief 线性筛法，得到n以内(包括n)的所有质数
* @param n  
* @return 
*/
int GetPrimes(int n);