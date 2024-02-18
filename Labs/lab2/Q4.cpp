#include <iostream>
using namespace std;
int* InputArray(int& size);
void OutputArray(int* myArray, const int& size);
int* CompressArray(int* originalArr, int& size);

int main()
{
	int s = 0;
	int* q = InputArray(s);
	OutputArray(q, s);
	cout << endl;

	int* r = CompressArray(q, s);
	q = nullptr;
	cout << "Array after Compression: ";
	OutputArray(r, s);
}

int* InputArray(int& size)
{
	cout << "Enter size of Array: ";
	cin >> size;
	int* p = new int[size];

	cout << "Enter elements of Array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
	cout << endl;
	return p;
}

void OutputArray(int* myArray, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i] <<" ";
	}
}

int* CompressArray(int* originalArr, int& size)
{
	int newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (originalArr[i] != originalArr[i + 1])
		{
			newSize++;
		}
	}

	int* newArray = new int[newSize];
	
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (originalArr[i] != originalArr[i + 1])
		{
			newArray[j++] = originalArr[i];
		}
	}
	newArray[j-1] = originalArr[size-1];
	delete[] originalArr;
	originalArr = nullptr;
	size = newSize;
	return newArray;
}