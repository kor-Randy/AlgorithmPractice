#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;



// 유니온 파인드 = 합집합 찾기 = 서로소 집합 알고리즘
// 여러개의 노드가 존재할 때 두개의 노드를 선택해서 같은 그래프인지 판별하는 알고리즘
// 부모를 재귀함수로 사용하여 찾는다.
// 같은 부모를 갖고 있으면 같은 그래프이다.



//부모를 찾는 재귀함수
int getparent(vector<int> &parent,int a)
{
	

	if (parent[a] == a) return parent[a];
	else
	{
		return parent[a] = getparent(parent, parent[a]);
	}
	

}

//그래프를 잇는 함수 (부모를 합치는 함수)
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

//노드가 이어져있는지 확인하는 함수
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

	printf("%d와 %d는 이어져있습니까?\n%d\n", 1, 2,unionfind(parent,1,2));
	printf("%d와 %d는 이어져있습니까?\n%d\n", 1, 4, unionfind(parent, 1, 4));





	return 0;
}