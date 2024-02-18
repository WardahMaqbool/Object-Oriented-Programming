#include <iostream>
#include "task1.h"
using namespace std;

int main()
{
	Tyre tNew(12, 10, 13);
	tNew.PrintTyre();
	cout << endl;

	Car cNew(2016, "Honda", tNew);
	cNew.PrintCar();
}