#include <iostream>
#include "task3.h"
using namespace std;

int main()
{
	shape* S;
	triangle t(4,8,"Triangle ");
	S = &t;
	t.printName();
	S->area_calculator();
	cout << endl;

	rectangle r(2, 4, "Rectangle ");
	S = &r;
	r.printName();
	S->area_calculator();
	cout << endl;

	circle c(5, "Circle ");
	S = &c;
	c.printName();
	S->area_calculator();
	cout << endl;
}