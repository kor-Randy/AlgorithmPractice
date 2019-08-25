#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int INF = 100000000;

//���ͽ�Ʈ�� = �ϳ��� �������� �ٸ� ��� ���������� �ִ� ���
//�÷��̵� �ͼ� = ��� �������� ��������� �ִ� ���
//���İ��� ��带 ����
// (2->3) vs (2->1 + 1->3)

int a[4][4] = 
{
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

int ans[4][4];

void floydwarshall()
{

	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			if (j == i) continue;
			
			for (int k = 0; k < 4; k++)
			{
				
				if (k == j) continue;

				if (a[i][j] > (a[i][k] + a[k][j]))
				{
					
					a[i][j] = (a[i][k] + a[k][j]);



				}

			}

		}

	}

}

int main()
{

	floydwarshall();
	
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			if(a[i][j]!=INF)
			printf("%d ", a[i][j]);
			else
			{
				printf("INF ");
			}

		}
		printf("\n");

	}


	return 0;
}

