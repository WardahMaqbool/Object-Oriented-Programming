#include <iostream>
using namespace std;
int main()
{
	double* CGPA = new double[10];
	cout << "Enter the CGPA of ten students: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> *(CGPA + i);
	}

	cout << "CGPA Array: ";
	for (int i = 0; i < 10; i++)
	{
		cout << *(CGPA + i)<<" ";
	}
	cout << endl;

	double max = *CGPA;
	for (int j = 1; j < 9; j++)
	{
		if (*(CGPA + j) > max)
		{
			max = *(CGPA + j);
		}
	}
	cout << "Maximum CGPA is: " << max;
	cout << endl;

	double min = *CGPA;
	for (int j = 1; j < 9; j++)
	{
		if (*(CGPA + j) < min)
		{
			min = *(CGPA + j);
		}
	}
	cout << "Minimum CGPA is: " << min;
	cout << endl;

	double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + *(CGPA + i);
	}
	double average = sum / 10.0;
	cout << "Average CGPA is: " << average;

	delete[] CGPA;
	CGPA = nullptr;
}