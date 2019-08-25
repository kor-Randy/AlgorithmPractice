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


//BFS -> �ʺ�켱Ž��
//'�ִ� ���'�� ã���شٴ� ������ �ִܱ��̸� �����ؾ� �� �� ���� ���
//�ڷᱸ���� 'Queue'
//ať�� ��带 �����鼭 �湮ó�� �ؾ���(��ó������ ��Ʈ)
//ať���� ��带 ���ʴ�� �����鼭 ������ ������ bť�� �ִ´�.
// -> ���� a push -> a pop -> b push 



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