#include"precision_compute.h"

vector<int> Add(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() < nums2.size())return(nums2, nums1);
	vector<int> res;
	int t = 0;
	for (int i = 0; i < nums1.size(); i++)
	{
		t += nums1[i];
		if (i < nums2.size()) t += nums2[i];
		res.push_back(t % 10);
		t /= 10;
	}

	if (t) res.push_back(t);
	return res;
}

vector<int> Sub(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> res;
	for (int i = 0, t = 0; i < nums1.size(); i++)
	{
		t = nums1[i] - t;
		if (i < nums2.size()) t -= nums2[i];
		res.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}

	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

vector<int> Mul(vector<int>& nums, int num)
{
	vector<int> res;

	int t = 0;
	for (int i = 0; i < nums.size() || t; i++)
	{
		if (i < nums.size()) t += nums[i] * num;
		res.push_back(t % 10);
		t /= 10;
	}

	while (res.size() > 1 && res.back() == 0) res.pop_back();

	return res;
}

vector<int> Div(vector<int>& nums, int b, int& r)
{
	vector<int> res;
	r = 0;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		r = r * 10 + nums[i];
		res.push_back(r / b);
		r %= b;
	}
	reverse(res.begin(), res.end());
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}
