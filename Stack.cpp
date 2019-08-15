#include<iostream>
#include<stack>

using namespace std;


int main()
{
	stack<int> s;

	s.push(1);
	s.push(5);
	s.push(4);
	s.push(7);
	s.push(2);
	s.pop();


	while (!s.empty())
	{
		
		cout << s.top() << endl;

		s.pop();

	}

}