#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, V;
int check1[1001];
int check[1001];
queue<int> q;
vector<int> edges[1001];


void dfs(int now) 
{
	
	if (check[now] == 1)
		return;

	else
	{
		printf("%d ", now);
		check[now] = 1;
		for (int i = 0; i < edges[now].size(); i++)
		{
			
			dfs(edges[now][i]);

		}

	}

}

void bfs(int now)
{
	int next = now;
	check1[next] = 1;
	q.push(next);
	
	while (!q.empty())
	{
		 next = q.front();
		 printf("%d ", next);
		for (int i = 0; i < edges[next].size(); i++)
		{
			
			if (check1[edges[next][i]] == 1)
			{
				continue;
			}
			else
			{
				q.push(edges[next][i]);
				check1[edges[next][i]] = 1;
			}

		}

		q.pop();
		
	}

}



int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i < M + 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i < N + 1; i++)
	{
		sort(edges[i].begin(), edges[i].end());

	}

	dfs(V);
	printf("\n");
	bfs(V);



	return 0;
}