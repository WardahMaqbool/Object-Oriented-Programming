#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Employee : public Person
{
private:
	string* Department;
	int ID;
public:
	Employee(string name, float height, string department, int id) : Person(name, height)
	{
		Department = new string(department);
		ID = id;
	}

	void printInfo()
	{
		cout << "Class: Employee" << endl;
		Person::printInfo();
		cout << "Department: " << *Department << endl;
		cout << "ID: " << ID << endl;
	}

	~Employee()
	{
		cout << "Employee Destructor" << endl;
	}
};

