#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of array: ";
	cin >> size;
	int* ptr = new int[size];
	cout << "Enter "<<size<<" values in the array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> ptr[i];
	}
	
	int max = *ptr;
	for (int j = 1; j < size-1; j++)
	{
		if ( max < ptr[j])
		{
			max = ptr[j];
		}
	}
	cout << "Maximum value is: "<<max;
}