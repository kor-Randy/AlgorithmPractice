#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define MAX 10001

using namespace std;


//SCC 알고리즘
//같은 SCC에 속하는 두 노드는 서로 도달이 가능하다.
//사이클이 발생하면 무조건 SCC에 해당
//SCC추출 알고리즘 -> 코사라주, 타잔 알고리즘
//타잔 알고리즘 = 모든 정점에 대해 DFS를 수행하여 SCC를 찾는다.
//스택에 DFS를 사용하면서 넣고 자신의 부모값이 나올때까지 pop한다.

int id, d[MAX];
bool finished[MAX];
vector<int> edges[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)
{
	
	d[x] = ++id;
	s.push(x);

	int parent = d[x];

	for (int i = 0; i < edges[x].size(); i++)
	{
		
		int  next = edges[x][i];
		//만약 next가 방문하지 않은 노드라면 
		if (d[next] == 0) parent = min(parent, dfs(next));
		//만약 next가 이미 스택에 존재하다면
		else if (!finished[next]) parent = min(parent, d[next]);

		if (parent == d[next])
		{
			
			vector<int> scc;
			while (1)
			{
				
				int t = s.top();
				s.pop();
				scc.push_back(t);
				finished[t] = true;
				if (x == t)
					break;

			}

		}




	}

	



}

void search(int now)
{
	s.push(now);
	while (!s.empty())
	{
		int current = s.top();
		
		for (int i = 0; i < edges[current].size(); i++)
		{
			
			search(edges[current][i]);

		}

	}

}


int main()
{
	int v = 11;
	edges[1].push_back(2);
	edges[2].push_back(3);
	edges[3].push_back(1);
	edges[4].push_back(2);
	edges[4].push_back(5);
	edges[5].push_back(7);
	edges[6].push_back(5);
	edges[7].push_back(6);
	edges[8].push_back(5);
	edges[8].push_back(9);
	edges[9].push_back(10);
	edges[10].push_back(11);
	edges[11].push_back(3);
	edges[11].push_back(8);


	return 0;
}