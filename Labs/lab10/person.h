#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string* fullName;
	float* height;
public:
	Person(string name, float h) //constructor
	{
		fullName = new string(name);
		height = new float(h);
	}
	virtual void printInfo()
	{
		cout << "Full name: " << *fullName << endl;
		cout << "Height: " << *height << endl;
	}
	virtual ~Person()
	{
		cout << "Person Destructor" << endl;
	}

};