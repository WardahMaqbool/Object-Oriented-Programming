#include <iostream>
#include "Ex2.h"
using namespace std;


void Academic::id()
{
	cout << "ID function called " << endl;
}

void Student::gpa()
{
	cout << "Student gpa function " << endl;
}

void Student::enroll(const char* course)
{
	cout << "Student course function" << endl;
}

void Student::pay(int amount)
{
	cout << "Student pay function" << endl;
}

void Instructor::grade()
{
	cout << "Instructor grade function" << endl;
}

void Instructor::teach(const char* course)
{
	cout << "Instructor teach function" << endl;
}

void Instructor::getpaid()
{
	cout << "Instructor getPaid function" << endl;
}

void TeachingAssistant::advisor(char* instructor)
{
	cout << "TA advisor function" << endl;
}