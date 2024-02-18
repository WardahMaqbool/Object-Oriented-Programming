#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Student : public Person
{
private:
	string* schoolName;
public:
	Student(string name, float height, string SchoolName) : Person(name, height)
	{
		schoolName = new string(SchoolName);
	}

	void printInfo()
	{
		cout << "class: Student" << endl;
		Person::printInfo();
		cout << "School Name: " << *schoolName << endl;
	}

	~Student()
	{
		cout << "Student Destructor." << endl;
	}
};

