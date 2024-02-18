#include <iostream>
#include "teacher.h"
using namespace std;

Teacher::Teacher(int t = 0, const char* n = nullptr)
{
	EmployeeID = t;
	Name = nullptr;
	if (n != nullptr) {
		int s = strlen(n);
		Name = new char[s + 1];
		for (int i = 0; i < s + 1; i++)
		{
			Name[i] = n[i];
		}
	}
}
Teacher::~Teacher()
{
	if (Name != nullptr)
		delete[] Name;
}

void Teacher::displayT()
{
	cout << "Teacher's ID: " << EmployeeID << endl;
	cout << "Teacher's Name: " << Name << endl;
}