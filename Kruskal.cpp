#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
// 가장 적은 비용으로 모든 노드를 연결할 수 있다.
// 최소 비용 신장 트리를 만들기 위한 알고리즘
// 최소간선 개수 = 노드개수 - 1

// 간선을 짧은 순서대로 그래프에 포함시키면 어떨까?
// 사이클이 형성되면 안됨
// 간선을 정렬한 후에 간선을 포함시키면서 사이클 확인
// 사이클 확인은 unionfind와 같음
// 간선정보, 사이클테이블 로 그래프를 나타낼 수 있음.

int node = 7;
int edge = 11;
int cost;
class edges
{
public:
	int cost;
	int start;
	int end;

	edges(int cost, int start, int end)
	{
		this->cost = cost;
		this->start = start;
		this->end = end;

	}

	bool operator<(edges edges)
	{
		return this->cost < edges.cost;
	}


};

void kruskal(vector<edges> &vc,int parent[])
{
	int temp=0;

	for (int i = 0; i < vc.size(); i++)
	{
		if (temp == 6)
			return;

		int a = vc[i].start;
		int b = vc[i].end;
		int value = vc[i].cost;

		if (parent[a] != parent[b])
		{
			if (parent[a] < parent[b])
			{
				parent[b] = parent[a];
			}
			else
			{
				parent[a] = parent[b];
			}
			cost += value;
			temp++;
		}

		

	}

}


int main()
{
	
	vector<edges> vc;
	int parent[8];

	for (int i = 1; i < 8; i++)
	{
		parent[i] = i;
	}

	vc.push_back(edges(12, 1, 7));
	vc.push_back(edges(13, 4, 7));
	vc.push_back(edges(73, 5, 7));
	vc.push_back(edges(67, 1, 2));
	vc.push_back(edges(45, 5, 6));
	vc.push_back(edges(37, 3, 6));
	vc.push_back(edges(28, 1, 4));
	vc.push_back(edges(24, 2, 4));
	vc.push_back(edges(20, 3, 5));
	vc.push_back(edges(17, 1, 5));
	vc.push_back(edges(62, 2, 5));

	sort(vc.begin(), vc.end());


	kruskal(vc, parent);

	printf("%d", cost);
	




	return 0;
}