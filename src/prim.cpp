#include "prim.h"

int Prim(const vector<vector<int>>& graph)
{
	int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> inMST(n);
	int weight_sum = 0;
	// ����һ���㿪ʼ�зֶ����ԣ����ǲ����ӽڵ� 0 ��ʼ
	dist[0] = 0;
	for (int k = 0; k < n; k++)//ÿ��ѭ��ѡ��һ������뵽������
	{
		int t = -1;
		for (int j = 0; j < n; j++)//ÿ���ڵ�һ���ж�
		{
			if (!inMST[j] && (t == -1 || dist[j] < dist[t]))//���û�������У��ҵ����ľ�����̣���ѡ��õ�
				t = j;
		}

		//��������㣬ֱ�ӷ���
		if (dist[t] == INT_MAX) {
			return INT_MAX;
		}


		inMST[t] = true;// ѡ��õ�
		weight_sum += dist[t];
		for (int i = 0; i < n; i++)//������������ĵ㵽�������ľ���
		{
			if (dist[i] > graph[t][i] && !inMST[i])//�� t ���ڵ� i �ľ���С��ԭ�����룬����¡�
			{
				dist[i] = graph[t][i];//���¾���
				// ������Լ�¼����������γ���
			}
		}
	}

	return weight_sum;
}
