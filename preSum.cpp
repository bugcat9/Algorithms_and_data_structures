#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <assert.h>
using namespace std;

namespace preSum
{
	class PreSum
	{

	public:
		/* 输入一个数组，构造前缀和 */
		PreSum(vector<int>& nums)
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

	void test()
	{
		vector<int> v = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
		PreSum preSum(v);
		assert(preSum.sumRange(0, 0) == 2);
		assert(preSum.sumRange(0, 1) == 4);
		assert(preSum.sumRange(1, 4) == 8);
		// 使用 partial_sum
		vector<int> v2;
		std::partial_sum(v.begin(), v.end(), back_inserter(v2));
		assert(v2[0] == 2);
		assert(v2[1] == 4);
		assert(v2[2] == 6);
	}
}

int main(int argc, char const* argv[])
{
	preSum::test();
	return 0;
}
