#include<iostream>
#include<algorithm>

using namespace std;


//sort(�޸�ù�ּ�,�޸𸮸������ּ�);
//sort(�޸�ù�ּ�,�޸𸮸������ּ�,��Ģ �Լ���);

bool compare(int a, int b)
{
	
	return a > b;
	//a�� b���� ũ�� Ʈ��(��������)
}


int main()
{

	int a[10] = { 9,1,2,4,6,3,7,10,5,8 };

	

	sort(a, a + 10,compare);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}



	return 0;
}
