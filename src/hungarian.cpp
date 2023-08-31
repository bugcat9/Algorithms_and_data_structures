#include"hungarian.h"

bool find(const vector<vector<int>>& graph, int x, vector<int>& match, vector<bool> visit)
{
	for (auto& j : graph[x])
	{
		if (!visit[j])
		{
			visit[j] = true;                           // ����ѱ���
			if (!match[j] || find(graph, match[j], match, visit))          // jδ��ƥ�䣬��j�Ѿ�ƥ�䵫����Զ����ѡ������ƥ��
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int Hungarian(const vector<vector<int>>& graph)
{
	int res = 0;
	int n = graph.size();
	// �洢�ڶ��������е�ÿ���㵱ǰƥ��ĵ�һ�������еĵ����ĸ�
	vector<int> match(n);
	for (int i = 0; i < n; i++)
	{
		vector<bool> visit(n);
		if (find(graph, i, match, visit)) res++;
	}
	return res;
}
