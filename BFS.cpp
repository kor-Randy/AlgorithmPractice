#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start)
{
	queue<int> q;

	q.push(start);
	c[start] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		printf("%d ", x);

		for (int i = 0; i < a[x].size(); i++)
		{

			int temp = a[x][i];

			if (c[temp] != 1)
			{
				q.push(temp);
				c[temp] = 1;
			}

		}

	}

}


//BFS -> 너비우선탐색
//'최단 경로'를 찾아준다는 점에서 최단길이를 보장해야 할 때 많이 사용
//자료구조는 'Queue'
//a큐에 노드를 넣으면서 방문처리 해야함(맨처음에는 루트)
//a큐에서 노드를 차례대로 뽑으면서 인접한 노드들을 b큐에 넣는다.
// -> 순서 a push -> a pop -> b push 



int main()
{
	a[1].push_back(2);
	a[1].push_back(3);


	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(4);
	a[2].push_back(5);

	a[3].push_back(1);
	a[3].push_back(2);
	a[3].push_back(6);
	a[3].push_back(7);

	a[4].push_back(2);
	a[4].push_back(5);

	a[5].push_back(2);
	a[5].push_back(4);

	a[6].push_back(3);
	a[6].push_back(7);

	a[7].push_back(3);
	a[7].push_back(6);

	bfs(1);


	return 0;
}