#include <iostream>
#include "month.h"
using namespace std;

int main()
{
	Month m1("April");
	!m1;

	cout << "Pre-increment: ";
	Month m2;
	m2 = ++m1;
	!m2;

	cout << "Post-increment: ";
	m2 = m1++;
	!m2;

	Month m3("December");
	!m3;
	Month m4;

	cout << "Pre-decrement: ";
	m4 = --m3;
	!m4;

	cout << "Post-decrement: ";
	m4 = m3--;
	!m4;
}