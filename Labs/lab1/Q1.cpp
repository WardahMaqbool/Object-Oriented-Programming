#include <iostream>
using namespace std;
void swap(int* p, int* q);
int main()
{
	int x = 50, y = 100;
	int* p = &x;
	int* q = &y;
	cout << "Before Swapping";
	cout << " x: " << x << " " << "y: " << y <<endl;
	swap(p, q);
	cout << "After Swapping";
	cout << " x: " << x << " " << "y: " << y;
}

void swap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}