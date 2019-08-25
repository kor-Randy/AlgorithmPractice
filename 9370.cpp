#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;

int tk;
int n, m, t;
int s, g, h;
int a, b, d;
int x;
int gh;
int INF = 187654321;
vector<int> des[101];
vector<pair<int, int>> edges[2001];
int dis[2001];
int dish[2001];
int disg[2001];
vector<int> ans[101];

void dijkstra(int start)
{

	dis[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int currentdis = -pq.top().first;

		int current = pq.top().second;

		pq.pop();

		if (dis[current] < currentdis) continue;
		else
		{
			
			for (int i = 0; i < edges[current].size(); i++)
			{
				dis[current] = currentdis;
				
				int nextdis = currentdis + edges[current][i].first;

				int next = edges[current][i].second;

				if (dis[next] > nextdis)
				{
					dis[next] = nextdis;
					pq.push(make_pair(-nextdis, next));
				}

			}

		}
		
	}

}
void dijkstrah(int start)
{

	dish[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int currentdis = -pq.top().first;

		int current = pq.top().second;

		pq.pop();

		if (dish[current] < currentdis) continue;
		else
		{

			for (int i = 0; i < edges[current].size(); i++)
			{
				dish[current] = currentdis;
				
				int nextdis = currentdis + edges[current][i].first;

				int next = edges[current][i].second;

				
				if (dish[next] > nextdis)
				{
					dish[next] = nextdis;
					pq.push(make_pair(-nextdis, next));
				}

			}

		}

	}


}
void dijkstrag(int start)
{

	disg[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int currentdis = -pq.top().first;

		int current = pq.top().second;

		pq.pop();

		if (disg[current] < currentdis) continue;
		else
		{

			for (int i = 0; i < edges[current].size(); i++)
			{
				

				int nextdis = currentdis + edges[current][i].first;

				int next = edges[current][i].second;

				
				if (disg[next] > nextdis)
				{
					disg[next] = nextdis;
					pq.push(make_pair(-nextdis, next));
				}

			}

		}

	}


}

void find(int time)
{
	for(int i=0;i<des[time].size();i++)
	{
		
		
		int destination = des[time][i];
			//다익스트라로 구한 s->목적지 거리 > s -> g -> h -> 목적지 가 더 작으면
		if (dis[destination] == (dis[g] + dish[destination]+gh) || dis[destination] == (dis[h] + disg[destination] + gh))
		{
			ans[time].push_back(destination);
		}
		

	}

	
	sort(ans[time].begin(), ans[time].end());

	
	
	
}


int main()
{
	scanf("%d", &tk);

	for (int i = 0; i < tk; i++)
	{
		

		for (int j = 1; j < 2001; j++)
		{
			dis[j] = INF;
			dish[j] = INF;
			disg[j] = INF;
		}

		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		
		
		for (int j = 0; j < m; j++)
		{
			scanf("%d %d %d", &a, &b, &d);
			if ((a == g&&b == h) || (a == h&&b == g))
			{
				gh = d;
			}
			

			

			edges[a].push_back(make_pair(d, b));
			edges[b].push_back(make_pair(d, a));

			
			
			
		}

		for (int k = 0; k < t; k++)
		{
			scanf("%d", &x);
			des[i].push_back(x);
		}


		dijkstra(s);

		dijkstrah(h);

		dijkstrag(g);
		


		find(i);
		
		for (int j = 1; j < n + 1; j++)
		{
			edges[j].clear();
		}

	}
	

	for (int i = 0; i < tk; i++)
	{
		for(int j=0;j<ans[i].size();j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}



	return 0;
}