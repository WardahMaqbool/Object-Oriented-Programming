#pragma once
#include <iostream>
using namespace std;

class Academic
{
public:
	void id();
};

class Student : virtual public Academic
{
public:
	void gpa();
	void enroll(const char* course);
	void pay(int amount);
};

class Instructor : virtual public Academic
{
public:
	void grade();
	void teach(const char* course);
	void getpaid();
};

class TeachingAssistant : public Student, public Instructor
{
public:
	void advisor(char* instructor);
};

