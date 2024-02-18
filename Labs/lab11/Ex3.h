#pragma once
#include <iostream>
using namespace std;

class InvalidDay
{
public:
	int checkDay(int day)
};

class InvalidMonth
{
public:
	int checkMonth(int month)
};

class InvalidYear
{
public:
	int checkYear(int date, int year)
};

class Date : public InvalidDay, public InvalidMonth, public InvalidYear
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	void EnterDate();
	void PrintDate();
};

