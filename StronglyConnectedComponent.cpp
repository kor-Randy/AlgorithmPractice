#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define MAX 10001

using namespace std;


//SCC �˰���
//���� SCC�� ���ϴ� �� ���� ���� ������ �����ϴ�.
//����Ŭ�� �߻��ϸ� ������ SCC�� �ش�
//SCC���� �˰��� -> �ڻ����, Ÿ�� �˰���
//Ÿ�� �˰��� = ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�´�.
//���ÿ� DFS�� ����ϸ鼭 �ְ� �ڽ��� �θ��� ���ö����� pop�Ѵ�.

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
		//���� next�� �湮���� ���� ����� 
		if (d[next] == 0) parent = min(parent, dfs(next));
		//���� next�� �̹� ���ÿ� �����ϴٸ�
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