#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//���� �켱���� ������ ���
//����Լ��� ���ÿ����� ����ص���
//���ÿ� �ְ� �湮ó���� �Ѵ�.(ó������ ��Ʈ)

int number = 7;
vector<int> v[8];
int checked[8];



void dfs(int index)
{
	

	printf("%d ", index);
	
	checked[index] = 1;



	for (int i = 0; i < v[index].size(); i++)
	{
		
		int temp = v[index][i];

		if (checked[temp] != 1)
		{
			
			dfs(temp);

		}
		

	}

	
	return;


}


int main()
{
	v[1].push_back(2);
	v[1].push_back(3);


	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);
	v[2].push_back(5);

	v[3].push_back(1);
	v[3].push_back(2);
	v[3].push_back(6);
	v[3].push_back(7);

	v[4].push_back(2);
	v[4].push_back(5);

	v[5].push_back(2);
	v[5].push_back(4);

	v[6].push_back(3);
	v[6].push_back(7);

	v[7].push_back(3);
	v[7].push_back(6);

	dfs(1);


	return 0;
}