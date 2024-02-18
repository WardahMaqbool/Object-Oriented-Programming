#include <iostream>
using namespace std;
void bubbleSort(int* a, int size);

int main()
{
	int size;
	cout << "Enter the size of scores array: ";
	cin >> size;
	int* scores = new int[size];

	cout << "Enter values for array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> scores[i];
	}

	bubbleSort(scores, size);

	cout << "Sorted Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout<< scores[i] <<" ";
	}

}

void bubbleSort(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(a + j) > *(a + j + 1))
			{
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}
