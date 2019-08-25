#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;



// ���Ͽ� ���ε� = ������ ã�� = ���μ� ���� �˰���
// �������� ��尡 ������ �� �ΰ��� ��带 �����ؼ� ���� �׷������� �Ǻ��ϴ� �˰���
// �θ� ����Լ��� ����Ͽ� ã�´�.
// ���� �θ� ���� ������ ���� �׷����̴�.



//�θ� ã�� ����Լ�
int getparent(vector<int> &parent,int a)
{
	

	if (parent[a] == a) return parent[a];
	else
	{
		return parent[a] = getparent(parent, parent[a]);
	}
	

}

//�׷����� �մ� �Լ� (�θ� ��ġ�� �Լ�)
int unionparent(vector<int> &parent, int a, int b)
{
	
	int x = getparent(parent, a);
	int y = getparent(parent, b);

	if (x > y)
	{
		return parent[a] = y;
	}
	else
	{
		return parent[b] = x;
	}

}

//��尡 �̾����ִ��� Ȯ���ϴ� �Լ�
int unionfind(vector<int> &parent, int a, int b)
{
	
	if (parent[a] == parent[b])
	{
		return 1;
	}
	else
	{
		return 0;
	}

}



int main()
{
	vector<int> parent;

	for (int i = 0; i < 11; i++)
	{
		parent.push_back(i);
	}

	unionparent(parent, 1, 2);

	unionparent(parent, 2, 3);
	unionparent(parent, 3, 4);

	unionparent(parent, 5, 6);
	unionparent(parent, 6, 7);
	unionparent(parent, 7, 8);

	printf("%d�� %d�� �̾����ֽ��ϱ�?\n%d\n", 1, 2,unionfind(parent,1,2));
	printf("%d�� %d�� �̾����ֽ��ϱ�?\n%d\n", 1, 4, unionfind(parent, 1, 4));





	return 0;
}