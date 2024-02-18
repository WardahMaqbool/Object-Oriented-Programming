#include <iostream>
#include "my_box.h"
using namespace std;

int main()
{
	box a;
	//using default constructor
	int l, b, h, count, vol, area;
	a.Get(l, b, h);
	cout << "box a" << endl;
	cout << "length: " << l << endl;
	cout << "breadth: " << b << endl;
	cout << "height: " << h << endl;
	count = a.getCount();
	cout << "Object Count: " << count << endl;
	cout << endl;

	//using parameterized constructor
	box a2(2, 2, 2);
	cout << "box a2" << endl;
	a2.Get(l, b, h);
	cout << "length: " << l << endl;
	cout << "breadth: " << b << endl;
	cout << "height: " << h << endl;
	count = a2.getCount();
	cout << "Object Count: " << count << endl;;
	vol = a2.Volume();
	cout << "Volume: " << vol << endl;;
	area = a2.Area();
	cout << "Area: " << area << endl;
	cout << endl;

	//resetting a2 using set function
	a2.Set(4, 4, 4);
	cout << "box a2 reset" << endl;
	a2.Get(l, b, h);
	cout << "length: " << l << endl;
	cout << "breadth: " << b << endl;
	cout << "height: " << h << endl;
	cout << endl;

	print_surface_area(a2);
	cout << endl;
	double_data_members(a2);
	cout << "Doubled Data Members of box a2:" << endl;
	a2.Get(l, b, h);
	cout << "length: " << l << endl;
	cout << "breadth: " << b << endl;
	cout << "height: " << h << endl;

}
