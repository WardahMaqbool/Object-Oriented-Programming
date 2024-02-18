#pragma once
#include <iostream>
#include "teacher.h"
using namespace std;

class Student
{
private:
	char* rollnumber;
	char* name;
	Teacher* TeacherList;
	int countTList;
public:
	Student(char* rnum, const char* n, Teacher* tl, int ctTlist);
	~Student();
	void displayS();
};