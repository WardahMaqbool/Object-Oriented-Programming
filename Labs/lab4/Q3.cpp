#include <iostream>
using namespace std;
void sort(float* p[], int n);
void print(float* p[], int n);

void main() 
{
	float a[8] = { 44.4, 77.7, 22.2, 88.8, 66.6, 33.3, 99.9, 55.5 };
	float* p[8];
	for (int i = 0; i < 8; i++)
		p[i] = new float(a[i]);// p[i] points to a[i]
	print(p, 8);
	cout << endl;
	sort(p, 8);
	cout << endl;
	print(p, 8);
}

void sort(float* p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (*p[j] > *p[j + 1])
			{
				float temp = *p[j];
				*p[j] = *p[j + 1];
				*p[j + 1] = temp;
			}
		}
	}
}

void print(float* p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p[i])<< " " ;
	}
}