#include<stdio.h>

//삽입정렬
//필요할 때만 위치를 바꾼다.
//O(n^2)중에는 가장 빠름
//i번째 숫자를 i이전의 숫자들의 사이사이에 들어간다.
//앞에서부터 정렬을 해나간다.

int main()
{
	int N;
	int key,temp,j;

	scanf("%d", &N);

	int* array = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < N-1; i++)
	{
		j = i;

		while (array[j] > array[j + 1])
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}

		/*for (int j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}*/

		

	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", array[i]);
	}



	return 0;
}
