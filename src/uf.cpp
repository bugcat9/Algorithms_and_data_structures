#include"uf.h"

UF::UF(int n) : parent_(n), count_(n)
{
	for (size_t i = 0; i < count_; i++)
	{
		parent_[i] = i;
	}
}

UF::~UF()
{
}

int UF::Find(int x)
{
	if (parent_[x] != x) {
		parent_[x] = Find(parent_[x]);
	}
	return parent_[x];
}

void UF::Union(int p, int q)
{
	int rootP = Find(p);
	int rootQ = Find(q);

	if (rootP == rootQ)
		return;

	parent_[rootQ] = rootP;
	// 两个连通分量合并成一个连通分量
	count_--;
}

int UF::Count()
{
	return count_;
}

bool UF::Connected(int p, int q)
{
	int rootP = Find(p);
	int rootQ = Find(q);
	return rootP == rootQ;
}
