#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class Student
{
public:
	string name;
	int score;

	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	// 정렬 기준은 '점수가 작은 순서'

	bool operator <(Student &student)
	{
		return this->score > student.score;
		//this의 점수가 낮다면 우선순위가 높다
	}

};


int main()
{
	Student students[] =
	{
		Student("나 동 빈",90),
		Student("지 현 우",80),
		Student("ㅁ ㅁ ㅁ",70),
		Student("ㄴ ㄴ ㄴ",78),
		Student("ㅇ ㅇ ㅇ",98)
	};

	

	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << " ";
	}
		



	return 0;
}