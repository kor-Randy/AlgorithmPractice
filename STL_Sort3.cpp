#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//2개의 데이터일 때는 pair
//3개일 때는 2중 pair 사용가능

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

	v.push_back(pair<pair<int, int>, string> (pair<int,int>(90, 5),"가가가"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(92, 5), "나나나"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(96, 3), "다다다"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(90, 4), "라라라"));
	v.push_back(pair<pair<int, int>, string>(pair<int, int>(45, 2), "마마마"));

	sort(v.begin(), v.end(),compare);
		
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " ";
	}




	return 0;
}