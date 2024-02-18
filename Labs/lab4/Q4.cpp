#include <iostream>
using namespace std;
char** AllocateMemory(int& rows, int& cols);
void InputMatrix(char** matrix, const int rows, const int cols);
void DisplayMatrix(char** matrix, const int& rows, const int& cols);
void separate(char** matrix, const int& rows, const int& cols);

int main()
{
	int r, c;
	char** a = AllocateMemory(r, c);
	InputMatrix(a, r, c);
	DisplayMatrix(a,r,c);
	cout << endl;
	separate(a, r, c);
	for (int i = 0; i < r; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = nullptr;
}
void separate(char** matrix, const int& rows, const int& cols)
{
	char alphabets[15];
	char numbers[15];
	char specialchar[15];
	
	int m=0, k=0, l=0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] >='a' && matrix[i][j] <= 'z')
			{
				alphabets[m] = matrix[i][j];
				m++;
			}
			else if (matrix[i][j] >= 'A' && (int)matrix[i][j] <= 'Z')
			{
				alphabets[m] = matrix[i][j];
				m++;
			}
			else if ((int)matrix[i][j] >= 48 && (int)matrix[i][j] <= 57)
			{
				numbers[k] = matrix[i][j];
				k++;
			}
			else
			{
				specialchar[l] = matrix[i][j];
				l++;
			}
		}
		alphabets[m] = '\0';
		numbers[k] = '\0';
		specialchar[l] = '\0';
	}
	cout <<"alphabets: "<< alphabets;
	cout << endl;
	cout << "numbers: " << numbers;
	cout << endl;
	cout << "specialchars: " << specialchar;

}
	

char** AllocateMemory(int& rows, int& cols)
{
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> cols;
	char** ptr = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new char[cols];
	}
	return ptr;
}

void InputMatrix(char** matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols ; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void DisplayMatrix(char** matrix, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols ; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
}