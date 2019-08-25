#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

// ������ Ž�� �ӵ� ������ ���� ����ϴ� ����
// 3���� ��� (����, ����, ���� ��ȸ)
// �����ʹ� ȭ��ǥ

int number = 15;


typedef struct node
{

	int data;
	node* leftChild;
	node* rightChild;

};


void preorder(node* ptr)
{

	if (ptr != NULL)
	{
		cout << ptr->data << " ";
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}

}

void inorder(node* ptr)
{

	if (ptr != NULL)
	{
		
		preorder(ptr->leftChild);
		cout << ptr->data << " ";
		preorder(ptr->rightChild);
	}

}

void postorder(node* ptr)
{

	if (ptr != NULL)
	{
		
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
		cout << ptr->data << " ";
	}

}


int main()
{
	
	node *nodes = new node[number+1];

	for (int i = 1; i < number + 1; i++)
	{
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i < number + 1; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].leftChild = &nodes[i];
		}
		else
		{
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]);
	cout << endl;

	inorder(&nodes[1]);
	cout << endl;

	postorder(&nodes[1]);



	return 0;
}