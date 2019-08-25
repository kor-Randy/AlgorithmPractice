#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>


using namespace std;
int INF = 2000001;
int V, E, K;

//최단경로 탐색 알고리즘 (프림알고리즘도 있음 -> 얘는 음의 간선 가능?)
//음의 간선은 사용할 수 없다.
//DP문제와 연관 -> 최단거리는 여러개의 최단거리로 이루어져있기 때문
//하나의 최단거리를 구할때 그전에 구했던 최단거리 정보를 그대로 사용한다.

//1. 출발노드 설정
//2. 출발 노드를 기준으로 각 노드의 최소 비용 저장
//3. 방문하지 않은 노드중 가장 비용이 적은 노드 선택
//4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 비교하여 최소 비용 갱신
//5. 3~4번 반복

vector<pair<int, int>> edges[20001];
//<거리, 노드번호>


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
