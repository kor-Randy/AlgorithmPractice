#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;

//위상정렬 -> 순서가 정해져있는 작업을 할때
//방향이 있는 사이클이없는 그래프에서만 사용
//스택 or 큐 사용 (보통 큐 사용)

//진입차수 = 현재 노드로 들어오는 노드의 갯수
//1. 진입차수가 0인 노드를 큐에 넣음
//2. 큐에서 원소를 꺼내 모든 간선을 제거
//3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 넣음
//4. 2~3번 반복 , 모든 원소를 방문하기 전에 큐에 비어지면 사이클이 존재한다는 것

int n, inDegree[MAX];
vector<int > a[MAX];

void topologySort()
{

	int result[MAX];
	queue<int> q;
	//진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i < n + 1; i++)
	{
	
		if (inDegree[i] == 0)
			q.push(i);

	}

	//위상정렬이 완전히 수행되려면 정확히 N개의 노드를 방문

	for (int i = 1; i < n + 1; i++)
	{
		if (q.empty())
		{
			return;
		}

		int x = q.front();
		q.pop();
		result[i] = x;

		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];

			if (--inDegree[y] == 0)
			{
				q.push(y);
			}
		}

	}

	for (int i = 1; i < n + 1; i++)
	{
		printf("%d ", result[i]);
	}

}

int main()
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;

	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();

	return 0;
}