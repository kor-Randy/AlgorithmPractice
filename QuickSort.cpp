#include<stdio.h>

//������
//�������� �˰���
//O(n^logn)
//Ư���� ���� �������� ū ���ڿ� ���� ���ڸ� ������.
//������ ��Ȳ������ pivot�� ���� ���� �ٲ��ش�.
//�Ϲ������� ���� ������.
//But, �̹� ������ �Ǿ��ִ� ���, ��� �񱳸� �ϱ� ������ �ð����⵵�� O(n^2)
// -> ���� ������ ������ ������� ����.

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


