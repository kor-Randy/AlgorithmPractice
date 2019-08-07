#include<stdio.h>

int array[1000001];
int number;
int temp[1000001];

void merge(int data[],int m, int middle, int n)
{

	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle&&j <= n)
	{
		
		if (data[i] <= data[j])
		{
			temp[k] = data[i];
			i++;
		}
		else
		{
			temp[k] = data[j];
			j++;
		}

		k++;

	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			temp[k] = data[t];
			k++;
		}
	}

	if (j > n)
	{
		for (int t = i; t <= middle; t++)
		{
			temp[k] = data[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++)
	{
		data[t] = temp[t];
	}


	
}

void mergeSort(int data[], int m, int n)
{
	//2개 이상일 때
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(data, m, middle);
		mergeSort(data, middle + 1, n);
		merge(data, m, middle, n);
	}

}



int main()
{
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}

	mergeSort(array, 0, number - 1);


	for (int i = 0; i < number; i++)
	{
		printf("%d\n", array[i]);
	}


}