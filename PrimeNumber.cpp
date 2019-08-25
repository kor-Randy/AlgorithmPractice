#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;

int number = 100000;
int a[100001];

//�Ҽ� �Ǻ� �˰���

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

//�����佺�׳׽��� ü
//�̸� �Ҽ����� ǥ���س��´�.

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