#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>


using namespace std;
int INF = 2000001;
int V, E, K;

//�ִܰ�� Ž�� �˰��� (�����˰��� ���� -> ��� ���� ���� ����?)
//���� ������ ����� �� ����.
//DP������ ���� -> �ִܰŸ��� �������� �ִܰŸ��� �̷�����ֱ� ����
//�ϳ��� �ִܰŸ��� ���Ҷ� ������ ���ߴ� �ִܰŸ� ������ �״�� ����Ѵ�.

//1. ��߳�� ����
//2. ��� ��带 �������� �� ����� �ּ� ��� ����
//3. �湮���� ���� ����� ���� ����� ���� ��� ����
//4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ���Ͽ� �ּ� ��� ����
//5. 3~4�� �ݺ�

vector<pair<int, int>> edges[20001];
//<�Ÿ�, ����ȣ>


int d[20001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	d[start] = 0;
	pq.push(make_pair(d[start], start));

	while (!pq.empty())
	{
		int curdistance = -pq.top().first;

		int current = pq.top().second;

		pq.pop();
		
		if (d[current] < curdistance) continue;
		else
		{
			d[current] = curdistance;

			for (int i = 0; i < edges[current].size(); i++)
			{
			
			
				int nextdistance = curdistance+edges[current][i].first;

				int next = edges[current][i].second;

				if (d[next] > nextdistance)
				{
					
					d[next] = nextdistance;
					pq.push(make_pair(-nextdistance, next));

				}

			}

		}

	}
	




}


int main()
{
	
	scanf("%d %d", &V, &E);

	scanf("%d", &K);
	for (int i = 1; i < V + 1; i++)
	{
		d[i] = INF;
	}

	for (int i = 1; i < E + 1; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back(make_pair(w, v));

	}

	dijkstra(K);

	for (int i = 1; i < V + 1; i++)
	{
		if (d[i] != INF)
			printf("%d\n", d[i]);
		else
		{
			printf("INF\n");
		}
	}



	return 0;
}
