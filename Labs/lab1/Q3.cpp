#include <iostream>
using namespace std;
int main()
{
	int x = 5, y = 10, z = 15;
	int* p = &x, * q = &y, * r = &z;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;
	cout << "*p: " << *p << endl;
	cout << "*q: " << *q << endl;
	cout << "*r: " << *r << endl;

	cout << "Swapping Values" << endl;
	int temp = *p;
	*p = *q;
	*q = *r;
	*r = temp;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;
	cout << "*p: " << *p << endl;
	cout << "*q: " << *q << endl;
	cout << "*r: " << *r << endl;

	cout << "Swapping Values" << endl;
	int *temp2 = p;
	p = q;
	q = r;
	r = temp2;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;
	cout << "*p: " << *p << endl;
	cout << "*q: " << *q << endl;
	cout << "*r: " << *r << endl;
}
