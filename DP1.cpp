#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;



// a(x) = a(x-1) + a(x-2)

int dp(int array[], int x)
{
	
	if (x == 1) return 1;
	if (x == 2) return 2;

	if (array[x] != 0) return array[x];

	return array[x] = (dp(array, x - 1) + dp(array, x - 2)) % 10007;

}



int main()
{
	int array[1001] = {0,};

	dp(array,30);

	printf("%d", array[30]);

	return 0;

}

