#ifndef _PRESUM_H
#define _PRESUM_H

#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
using namespace std;

namespace tiny
{
	class NumArray
	{

	public:
		/* 输入一个数组，构造前缀和 */
		NumArray(vector<int> &nums)
		{
			int n = nums.size();
			preSum.resize(n + 1);
			for (int i = 1; i < n + 1; i++)
			{
				preSum[i] = preSum[i - 1] + nums[i - 1];
			}
		}

		/* 查询闭区间 [left, right] 的累加和 */
		int sumRange(int left, int right)
		{
			return preSum[right + 1] - preSum[left];
		}

	private:
		// 前缀和数组
		vector<int> preSum;
	};

	// NumMatrix二维前缀和
	class NumMatrix
	{
	public:
		NumMatrix(vector<vector<int>> &matrix)
		{
			int m = matrix.size();
			if (m > 0)
			{
				int n = matrix[0].size();
				preSum.resize(m + 1, vector<int>(n + 1));
				for (int i = 1; i <= m; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						// 计算每个矩阵 [0, 0, i, j] 的元素和
						preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + matrix[i - 1][j - 1] - preSum[i - 1][j - 1];
					}
				}
			}
		}

		// 计算子矩阵 [x1, y1, x2, y2] 的元素和
		int sumRegion(int row1, int col1, int row2, int col2)
		{
			// 目标矩阵之和由四个相邻矩阵运算获得
			return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
		}

	private:
		// 定义：preSum[i][j] 记录 matrix 中子矩阵 [0, 0, i-1, j-1] 的元素和
		vector<vector<int>> preSum;
	};
}

#endif // _PRESUM_H