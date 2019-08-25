#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;

int number = 100000;
int a[100001];

//소수 판별 알고리즘

bool isPrimeNumber(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0) return false;
	}
	return true;
}

bool isPrimeNumber2(int x)
{
	
	int end = (int)sqrt(x);
	for (int i = 2; i < end; i++)
	{
		if (x%i == 0) return false;
	}
	return true;
}

//에라토스테네스의 체
//미리 소수인지 표시해놓는다.

void primeNumberSieve()
{
	
	for (int i = 1; i < number + 1; i++)
	{
		a[i] = i;
	}

	for (int i = 2; i < number + 1; i++)
	{
		
		if (a[i] == 0)	continue;

		for (int j = 2 * i; j < number + 1; j+=i)
		{
			a[j] = 0;
		}

	}

	for (int i = 2; i < number + 1; i++)
	{
		if (a[i] != 0) printf("%d ", a[i]);
	}
	

}


int main()
{
	primeNumberSieve();


	return 0;
}