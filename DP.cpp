#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

// 하나의 문제는 단 한번만 풀도록 하는 알고리즘
// 1번 가정 : 큰 문제를 작은 문제로 나눌 수 있다.
// 2번 가정 : 작은 문제에서 구한 답은 큰 문제에서의 작은문제에서도 답이 같다.
// 메모이제이션 : 푼 작은 문제의 답을 저장해놓는다.

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



