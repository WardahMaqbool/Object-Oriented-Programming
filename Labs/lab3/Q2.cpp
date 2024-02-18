#include <iostream>
using namespace std;
int** AddMatrix(int** A, int** B, const int& rows, const int& cols);

int main()
{
	int rows, cols;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;
	int** A = new int* [rows];
	for (int i = 0; i < rows; i++)
		A[i] = new int[cols];
	int** B = new int* [rows];
	for (int i = 0; i < rows; i++)
		B[i] = new int[cols];

	//matrix A
	cout << "Enter values for matrix A: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin>>A[i][j];
		}
	}

	//matrix B
	cout << "Enter values for matrix B: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin>>B[i][j];
		}
	}

	int** result = AddMatrix(A, B, rows, cols);
	cout << result << endl;
}

int** AddMatrix(int** A, int** B, const int& rows, const int& cols)
{
	
	int** ptr = new int* [rows];
	for (int i = 0; i < rows; i++)
		ptr[i] = new int[cols];

	int i;
	for (i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ptr[i][j]=A[i][j]+B[i][j];
		}
	}

	return ptr;
}