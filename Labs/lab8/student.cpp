#include <iostream>
#include "teacher.h"
#include "student.h"
using namespace std;

Student::Student(char* rnum = nullptr, const char* n = nullptr, Teacher* tl = nullptr, int cTlist = 0)
{
	rollnumber = rnum;
	name = nullptr;
	if (n != nullptr) {
		int s = strlen(n);
		name = new char[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			name[i] = n[i];
		}
	}
	countTList = cTlist;
	TeacherList = tl;
}

Student::~Student()
{
	if (rollnumber != nullptr)
		delete rollnumber;
	if (name != nullptr)
		delete[] name;
	if (TeacherList != nullptr)
		TeacherList = nullptr;
}

void Student::displayS()
{
	cout << "Student Roll Number: " << rollnumber << endl;
	cout << "Student Name: " << name << endl;
	cout << "Teachers List:" << endl;
	for (int i = 0; i < countTList; i++)
	{
		TeacherList[i].displayT();
	}
}