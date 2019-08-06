#include<stdio.h>

//선택정렬
//가장 작은것을 선택해서 제일 앞으로 보낸다.


int main()
{
	int N;
	int index, temp, min;
	scanf("%d", &N);

	int *array=new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &array[i]);


	for (int i = 0; i < N; i++)
	{

		min = 999;
		for (int j = i; j < N; j++)
		{
		
			if (array[j] < min)
			{
			
				min = array[j];
				index = j;
			
			}

		}

		temp = array[i];
		array[i] = min;
		array[index] = temp;

	}

	for (int i = 0; i < N; i++)
	{
		printf("%d", array[i]);
	}


	return 0;
}