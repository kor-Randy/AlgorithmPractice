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

	// ���� ������ '������ ���� ����'

	bool operator <(Student &student)
	{
		return this->score > student.score;
		//this�� ������ ���ٸ� �켱������ ����
	}

};


int main()
{
	Student students[] =
	{
		Student("�� �� ��",90),
		Student("�� �� ��",80),
		Student("�� �� ��",70),
		Student("�� �� ��",78),
		Student("�� �� ��",98)
	};

	

	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << " ";
	}
		



	return 0;
}