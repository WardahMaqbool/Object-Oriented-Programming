#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	fraction f1(5, 2);
	fraction f2(1, 2);
	cout << "Fraction 1: ";
	!f1;
	cout << "Fraction 2: ";
	!f2;
	cout << "Negative of f1: ";
	f1 = -f1;
	!f1;
	f1 = -f1;
	cout << "Reciprocal of f1: ";
	f1 = *f1;
	!f1;
	f1 = *f1;

	fraction f3(f1);
	fraction f4(f1);
	fraction f5(f1);
	fraction f6(f1);
	fraction f7(f1);

	cout << "Sum of f1 and f2: ";
	f3.operator+=(f2);
	!f3;

	cout << "Subtracting of f2 from f1: ";
	f4.operator-=(f2);
	!f4;

	cout << "Multiplying f1 and f2: ";
	f5.operator*=(f2);
	!f5;

	cout << "Dividing f1 and f2: ";
	f6.operator/=(f2);
	!f6;

	cout << "f1 > f2: ";
	cout << f7.operator>(f2) <<endl;

	cout << "f1 < f2: ";
	cout << f7.operator<(f2) << endl;

	cout << "f1 == f2: ";
	cout << f7.operator==(f2) << endl;

	cout << "f1 != f2: ";
	cout << f7.operator!=(f2) << endl;

	cout << "f1 pre-increment: ";
	f7 = ++f7;
	!f7;
	cout << endl;

	cout << "f2 post-increment: ";
	f2 = f2++;
	!f2;
	cout << endl;

	fraction F1;
	cout << "Input a fraction:"<<endl;
	cin >> F1;
	cout << F1;
}
