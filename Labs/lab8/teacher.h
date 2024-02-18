#pragma once
#include <iostream>
using namespace std;

class Teacher
{
private:
	int EmployeeID;
	char* Name;
public:
	Teacher(int t, const char* n);
	~Teacher();
	void displayT();
};
