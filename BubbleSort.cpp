#include<stdio.h>

//버블정렬
//옆에 있는 값과 비교해서 작은 수를 앞으로 보낸다

int main()
{
	int N;
	int temp;

	scanf("%d", &N);

	int* array = new int[N];

	for(int i = 0 ; i<N ; i++)
		scanf("%d", &array[i]);

	for (int i = 0; i < N; i++)
	{
		
		for (int j = i; j < N; j++)
		{
		
			if (array[j] < array[i])
			{
				
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}

		}

	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", array[i]);
	}


	return 0;
}