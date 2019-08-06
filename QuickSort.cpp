#include<stdio.h>

//퀵정렬
//분할정복 알고리즘
//O(n^logn)
//특정한 값을 기준으로 큰 숫자와 작은 숫자를 나눈다.
//엇갈린 상황에서는 pivot과 작은 수를 바꿔준다.
//일반적으로 가장 빠르다.
//But, 이미 정렬이 되어있는 경우, 모두 비교를 하기 때문에 시간복잡도가 O(n^2)
// -> 분할 정복의 이점을 사용하지 못함.

void QuickSort(int* data, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	
	int left, right, pivot, temp;

	pivot = start;
	left = start + 1;
	right = end;

	while (left <= right)
	{
		
		while (data[pivot] >= data[left])
		{
			left++;
		}
		while (data[pivot] <= data[right] && right>pivot)
		{
			right--;
		}

		if (left > right)
		{
			temp = data[pivot];
			data[pivot] = data[right];
			data[right] = temp;
		}
		else
		{
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;
		}


	}

	QuickSort(data, start, right - 1);
	QuickSort(data, right + 1, end);

}

int main()
{
	int N;
	scanf("%d", &N);
	int *array = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}

	QuickSort(array, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", array[i]);
	}


	return 0;
}


