#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Please enter size of array: ";
	cin >> size;
	float* ptr = new float[size];

	cout << "Please enter elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> ptr[i];
	}

	int maxIndex = 0;
	int SecondLI = 0;
	for (int j = 1; j < size; j++)
	{
		if (*(ptr + j) > *(ptr + maxIndex))
		{
			SecondLI = maxIndex;
			maxIndex = j;
			
		}
	}
	cout << "Second Largest element is: " << ptr[SecondLI];
	cout << endl;
	cout << "Index of Second Largest element is: " <<SecondLI;

}