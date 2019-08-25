#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000001];
int n, m;
int aa[100001];
int bb[100001];
int cc[100001];

int goparent(int num)
{

	if (num == a[num])
		return num;
	else
	{
		return a[num] = goparent(a[num]);
	}

}

void search(int now)
{

	while (now != m)
	{
		++now;

		if (aa[now] == 0)
		{
			int left = goparent(bb[now]);
			int right = goparent(cc[now]);
			if (left != right)
			{
				a[left] = right;
			}
		}
		else
		{
			int left = goparent(bb[now]);
			int right = goparent(cc[now]);

			if (left == right)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}


	}

}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n + 1; i++)
	{
		a[i] = i;
	}
	for (int i = 1; i < m + 1; i++)
	{

		scanf("%d %d %d", &aa[i], &bb[i], &cc[i]);

		

	}
	search(0);



	return 0;
}