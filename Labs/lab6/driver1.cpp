#include <iostream>
#include "my_big_int.h"
using namespace std;

int main()
{
	BiggerInt i;
	cout << "Object i: " << endl;
	i.display();
	cout << endl;

	const int s = 5, s2 = 8;
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	int arr2[8] = {6,7,8,9,10,11,12,13};
	int* ptr2 = arr2;

	cout << "Object i1: " << endl;
	BiggerInt i1(ptr, s);
	i1.display();
	cout << endl;
	
	cout << "Object i2: " << endl;
	BiggerInt i2(i1);
	i2.display();
	cout << endl;
	cout << "Comparing Object i2 and i: ";
	cout << i2.compareTo(i) << endl;
	cout << endl;

	i2.assign(i1);
	cout << "Object i2 after assigning: " << endl;
	i2.display();
	cout << endl;

	BiggerInt i3;
	i3.assign(ptr2, s2);
	cout << "Object i3 after assigning: " << endl;
	i3.display();
	cout << endl;
	cout << "Comparing Object i3 and ptr2: ";
	cout << i3.compareTo(ptr2,s2) << endl;
	cout << endl;

	cout << "Appending i3 at the end of i2:" << endl;
	i2.append(i3);
	i2.display();
	cout << endl;
	cout << "Appending ptr2 at the end of i2:" << endl;
	i2.append(ptr2, s2);
	i2.display();

	i.~BiggerInt();
	i1.~BiggerInt();
	i2.~BiggerInt();
	i3.~BiggerInt();

}