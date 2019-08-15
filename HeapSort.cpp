#include<iostream>

//힙 = 최대힙 or 최소힙
//Heapify -> 힙으로 만들어주는 알고리즘
//Heapify 한번에 logn
//힙 정렬은 O(nlogn)
int number = 9;
int heap[9] = { 6,5,4,7,3,8,2,9,1 };


int main()
{
	//최대 힙 구조로 바꾸는 과정
	for (int i = 1; i < number; i++)
	{
		int c = i;

		do 
		{
			int root = (c - 1) / 2;

			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}

			c = root;

		} while (c != 0);
	}

	for (int i = 0; i < number; i++)
	{
		printf("%d ", heap[i]);
	}

	//힙정렬하는 과정
	for (int i = number - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int  root = 0;
		int c = 1;

		do
		{
			c = 2 * root + 1;
			if (heap[c] < heap[c + 1] && c < i - 1)
			{
				c++;
			}

			if (heap[root] < heap[c] && c < i)
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;

		} while (c < i);

	}

	for (int i = 0; i < number; i++)
	{
		printf("%d ", heap[i]);
	}


	return 0;
}