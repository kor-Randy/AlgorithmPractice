#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int > q;
	q.push(7);
	q.push(5);
	q.push(3);
	q.push(1);

	q.pop();

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}




	return 0;
}