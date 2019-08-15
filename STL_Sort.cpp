#include<iostream>
#include<algorithm>

using namespace std;


//sort(메모리첫주소,메모리마지막주소);
//sort(메모리첫주소,메모리마지막주소,규칙 함수명);

bool compare(int a, int b)
{
	
	return a > b;
	//a가 b보다 크면 트루(내림차순)
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
