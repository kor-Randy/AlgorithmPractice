#include<stdio.h>

//��������
//�ʿ��� ���� ��ġ�� �ٲ۴�.
//O(n^2)�߿��� ���� ����
//i��° ���ڸ� i������ ���ڵ��� ���̻��̿� ����.
//�տ������� ������ �س�����.

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
