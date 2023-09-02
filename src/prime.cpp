#include"prime.h"

bool IsPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i++)              // 注意循环条件
		if (x % i == 0)
			return false;
	return true;
}

int GetPrimes(int n)
{
	vector<bool> st(n + 1);
	vector<int> primes;
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;               // 用最小质因子去筛合数primes[j] * i
			if (i % primes[j] == 0) break;          // 若prime[j]是i的最小质因子，则prime[j+1] * i的最小质因子依旧是prime[j]
		}
	}
	return primes.size();
}
