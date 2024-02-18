#include <iostream>
#include <cmath>
#include "task3.h"
using namespace std;

int main()
{
	shape** s = new shape*[2];
	s[0] = new Rectangle(5, 8);
	s[1] = new Rectangle(8, 5);

	cout << "Rectangle 1:" << endl;
	s[0]->print();
	s[0]->Area();
	s[0]->Perimeter();
	s[0]->GetDiagonal();

	cout << endl;
	cout << "Rectangle 2:" << endl;
	s[1]->print();
	s[1]->Area();
	s[1]->Perimeter();
	s[1]->GetDiagonal();

	cout << endl;
	for (int i = 0; i < 2; i++)
		delete s[i];
	delete[] s;

}