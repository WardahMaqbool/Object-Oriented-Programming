#include <iostream>
#include "month.h"
using namespace std;

Month::Month()
{
	strcpy(name,"Januray");
	monthNumber = 1;
}

Month::Month(const char* str)
{
	strcpy(name, str);
    monthNumber = 0;
    setMonthNumber(str);
}

void Month::setMonthNumber(const char* n)
{
    if (n == "January")
        monthNumber = 1;
    else if (n == "February")
        monthNumber = 2;
    else if (n == "March")
        monthNumber = 3;
    else if (n == "April")
        monthNumber = 4;
    else if (n == "May")
        monthNumber = 5;
    else if (n == "June")
        monthNumber = 6;
    else if (n == "July")
        monthNumber = 7;
    else if (n == "August")
        monthNumber = 8;
    else if (n == "September")
        monthNumber = 9;
    else if (n == "October")
        monthNumber = 10;
    else if (n == "November")
        monthNumber = 11;
    else if (n == "December")
        monthNumber = 12;
}

void Month::setMonthName(int Mnum)
{
    monthNumber = Mnum;
    switch (monthNumber)
    {
    case 1:
        strcpy(name, "January");
        break;
    case 2:
        strcpy(name, "Febrary");
        break;
    case 3:
        strcpy(name, "March");
        break;
    case 4:
        strcpy(name, "April");
        break;
    case 5:
        strcpy(name, "May");
        break;
    case 6:
        strcpy(name, "June");
        break;
    case 7:
        strcpy(name, "July");
        break;
    case 8:
        strcpy(name, "August");
        break;
    case 9:
        strcpy(name, "September");
        break;
    case 10:
        strcpy(name, "October");
        break;
    case 11:
        strcpy(name, "November");
        break;
    case 12:
        strcpy(name, "December");
        break;
    }
}

Month& Month::operator++()
{
    if (monthNumber == 12)
    {
        monthNumber = 1;
        setMonthName(monthNumber);
    }
    ++monthNumber;
    setMonthName(monthNumber);
    return *this;
}

Month Month::operator++(int)
{
    if (monthNumber == 12)
    {
        monthNumber = 1;
        setMonthName(monthNumber);
    }
    Month M(*this);
    monthNumber++;
    setMonthName(monthNumber);
    return M;
}

Month& Month::operator--()
{
    if (monthNumber == 1)
    {
        monthNumber = 12;
        setMonthName(monthNumber);
    }
    --monthNumber;
    setMonthName(monthNumber);
    return *this;
}

Month Month::operator--(int)
{
    if (monthNumber == 1)
    {
        monthNumber = 12;
        setMonthName(monthNumber);
    }
    Month M(*this);
    monthNumber--;
    setMonthName(monthNumber);
    return M;
}

void Month::operator!(void) const
{
    cout << "Month Number: " << monthNumber<<endl;
    cout << "Month Name: " << name<<endl;
    cout << endl;
}