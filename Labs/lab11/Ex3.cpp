#include <iostream>
#include <string>
#include "Ex3.h"
using namespace std;

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

void Date::EnterDate()
{
	cout << " Enter your Date of Birth(space separated values e.g 4 6 2021): " << endl;
	int d, m, y;
	cin >> d >> m >> y;
	day = d;
	month = m;
	year = y;
}

void Date::PrintDate()
{
	if (InvalidDay::checkDay(day) == 0 && InvalidMonth::checkMonth(month) == 0 && InvalidYear::checkYear(day, year) == 0)
	{
		string smonth;
		if (month == 1)
			smonth = "January";
		else if (month == 2)
			smonth = "February";
		else if (month == 3)
			smonth = "March";
		else if (month == 4)
			smonth = "April";
		else if (month == 5)
			smonth = "May";
		else if (month == 6)
			smonth = "June";
		else if (month == 7)
			smonth = "July";
		else if (month == 8)
			smonth = "August";
		else if (month == 9)
			smonth = "September";
		else if (month == 10)
			smonth = "October";
		else if (month == 11)
			smonth = "November";
		else if (month == 12)
			smonth = "December";

		cout << "Date:" << smonth << ", " << day <<" " << year << endl;
	}
}

int InvalidDay::checkDay(int day)
{
	try
	{
		if (day > 31 || day < 1)
		{
			throw 10;
		}
		else
			return 0;
	}
	catch (int e)
	{
		cout << "Invalid Date Entered!" << endl;
	}
}

int InvalidMonth::checkMonth(int month)
{
	try
	{
		if (month > 12 || month < 1)
		{
			throw 15;
		}
		else
			return 0;
	}
	catch (int e)
	{
		cout << "Invalid Month Entered!" << endl;
	}
}

int InvalidYear::checkYear(int date, int year)
{
	try
	{
		if (date > 28 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
		{
			throw 20;
		}
		else
			return 0;
	}
	catch (int e)
	{
		cout << "Invalid Year Entered!" << endl;
	}
}