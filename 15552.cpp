#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{

	
	int num;
	
	int a, b;
	
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
	
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);

	}
	
	



	return 0;
}