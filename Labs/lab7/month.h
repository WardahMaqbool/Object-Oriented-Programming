#pragma once
#include <iostream>
using namespace std;

class Month
{
    char name[15];
    int monthNumber;
public:
    Month();
    Month(const char*);
    void setMonthNumber(const char* name);
    void setMonthName(int Mnum);

    Month& operator++();
    Month operator++(int);

    Month& operator--();
    Month operator--(int);

    void operator!(void) const;

};
