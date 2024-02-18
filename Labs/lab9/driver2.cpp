#include <iostream>
#include "task2.h"
using namespace std;

int main()
{
	int size = 2;
	ship** S = new ship * [size];
	S[0] = new CruiseShip(2435,"Titanic","1909");
	S[0]->print();
	cout << endl;
	S[1] = new CargoShip(214286,"Madrid Maersk","2017");
	S[1]->print();
	cout << endl;

	S[0]->set_name("FAST");
	S[0]->print();
	cout << endl;

	S[1]->set_year("2020");
	S[1]->print();
	cout << endl;
}