#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

// �ϳ��� ������ �� �ѹ��� Ǯ���� �ϴ� �˰���
// 1�� ���� : ū ������ ���� ������ ���� �� �ִ�.
// 2�� ���� : ���� �������� ���� ���� ū ���������� �������������� ���� ����.
// �޸������̼� : Ǭ ���� ������ ���� �����س��´�.

int d[100];

int dp(int x)
{
	

	if (x == 1) return 1;

	if (x == 2) return 1;

	if (d[x] != 0) return d[x];

	return d[x] = dp(x - 1)+dp(x - 2);

}


int main()
{
	printf("%d ",dp(30));



	return 0;
}



