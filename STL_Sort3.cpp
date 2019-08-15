#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//2���� �������� ���� pair
//3���� ���� 2�� pair ��밡��

bool compare(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b)
{
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	else
		return a.first.first > b.first.first;
}

int main()
{
	vector< pair<pair<int, int>, string>> v;

	v.push_back(pair<pair<int, int>, string> (pair<int,int>(90, 5),"������"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(92, 5), "������"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(96, 3), "�ٴٴ�"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(90, 4), "����"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(45, 2), "������"));

	sort(v.begin(), v.end(),compare);
		
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " ";
	}




	return 0;
}