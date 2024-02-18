#include <iostream>
#include <fstream>
using namespace std;

void AllocateTriangularMatrix(int*** &arr, int n);
void Deallocate(int*** &arr, int n);
void readFromFile(int*** &arr, int*** &arr2, int& s, int& s2);
int checkUpperTriangular(int arr[10][10], int order);
void print(int*** arr, int r);
void input(int*** arr, int n);
bool AddMatrices(int*** A, int*** B, int***& C, int m, int n, int& r);
bool MultiplyMatrices(int*** A, int*** B, int***& C, int m, int n, int& r);
void deleteRow(int*** &a, int &s, int row);
void swap(int***& a, int s);
void menu();

int main()
{
	menu();
}

void AllocateTriangularMatrix(int*** &arr, int n)
{
	arr = new int**;
	for (int i = 0; i < n; i++)
	{
		*arr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			arr[0][i] = new int[n - i];
		}
	}
}

void Deallocate(int*** &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] arr[0][i];
	}
	delete[] *arr;
	delete arr;
	arr = nullptr;
}

void input(int*** arr, int n)
{
	cout << "Enter the contents of the square matrix: " << endl;;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i; j++)
		{
			cin >> arr[0][i][j];
		}
	}
}

void readFromFile(int*** &arr, int*** &arr2, int& s, int& s2)
{
	int order;
	ifstream fin;
	fin.open("sampleMatrices.txt");
	const int x = 10;
	int matrix[x][x];
	fin >> order;
	s = order;
	AllocateTriangularMatrix(arr, order);
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			fin >> matrix[i][j];
		}
	}
	if (checkUpperTriangular(matrix, order) == 0)
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = i, k = 0; j < order; j++)
			{
				arr[0][i][k] = matrix[i][j];
				k++;
			}
		}
	}
	cout << "Matrix A" << endl;
	print(arr, order);

	fin >> order;
	s2 = order;
	AllocateTriangularMatrix(arr2, order);
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			fin >> matrix[i][j];
		}
	}
	if (checkUpperTriangular(matrix, order) == 0)
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = i, k = 0; j < order; j++)
			{
				arr2[0][i][k] = matrix[i][j];
				k++;
			}
		}
	}
	cout << "Matrix B" << endl;
	print(arr2, order);
	fin.close();
}

int checkUpperTriangular(int arr[10][10], int order)
{
	for (int i = 1; i < order; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i][j] != 0)
			{
				cout << "Matrix is not upper triangular." << endl;
				return 1;
			}
		}
	}
	return 0;
}

void print(int*** arr, int r)
{
	for (int i = 0; i < r; i++)
	{
		if (i != 0)
		{
			for (int j = 0; j < i; j++)
			{
				cout << 0 <<" ";
			}
		}
		for (int k = 0; k < r - i; k++)
		{
			cout << arr[0][i][k] <<" ";
		}
		cout << endl;
	}
	cout << endl;
}

bool AddMatrices(int*** A, int*** B, int***& C, int m, int n, int &r)
{
	if (m == n)
	{
		r = m;
		AllocateTriangularMatrix(C, r);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r - i; j++)
			{
				C[0][i][j] = A[0][i][j] + B[0][i][j];
			}
		}
		return true;
	}
	return false;
}

bool MultiplyMatrices(int*** A, int*** B, int***& C, int m, int n, int& r)
{
	if (m == n)
	{
		r = m;
		AllocateTriangularMatrix(C, r);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0 ; j < r - i; j++)
			{
				C[0][i][j] = 0;
				for (int k = 0, l = j, m = i; k < r - l && l>=0; k++, l--, m++)
				{
					C[0][i][j] = C[0][i][j] + (A[0][i][k] * B[0][m][l]);
				}
			}
		}
		return true;
	}
	return false;
}

void deleteRow(int*** &a,int &s, int row)
{
	int*** b;
	int sb = s - 1;
	int del = row - 1;
	AllocateTriangularMatrix(b, sb);

	for (int i = 0,j = row - 1; j >= 0 && i < row - 1; i++, j--)
	{
		a[0][i][j] = -1;
	}
	int m, n,k,l;
	for ( m = 0, k = 0; m < sb; m++,k++)
	{
		for ( n = 0, l = 0; n < sb - m; n++,l++)
		{
			if (k != del)
			{
				if (a[0][k][l] != -1)
				{
					b[0][m][n] = a[0][k][l];
				}
				if (a[0][k][l] == -1)
				{
					l++;
					b[0][m][n] = a[0][k][l];
				}
			}
			else
			{
				k++;
				if (a[0][k][l] != -1)
				{
					b[0][m][n] = a[0][k][l];
				}
				if (a[0][k][l] == -1)
				{
					l++;
					b[0][m][n] = a[0][k][l];
				}
			}
		}
	}
	Deallocate(a, s);
	a = b;
	s = sb;
}

void swap(int*** &a, int s)
{
	int r1, r2;
	cout << "Enter row number: "<<endl;
	cin >> r1;
	cout << endl;
	cout << "Enter row number to swap with: " << endl;
	cin >> r2;
}

void menu()
{
	cout << "MENU" << endl;
	cout << "Please Enter: " << endl;
	cout << "0 - to exit the program." << endl;
	cout << "1 - to input a triangular matrix." << endl;
	cout << "2 - to print triangular matrix." << endl;
	cout << "3 - to input two triangular matrices." << endl;
	cout << "4 - to read two triangular matrices from file." << endl;
	cout << "5 - to add two triangular matrices." << endl;
	cout << "6 - to multiply two triangular matrices from file." << endl;
	cout << "7 - to delete a row from triangular matrix." << endl;
	cout << "8 - to swap two rows of a triangular matrix." << endl;

	int option;
	int*** a = nullptr, *** b = nullptr, *** c = nullptr;
	int sa = 0, sb = 0, sc = 0;
	cin >> option;
	cout << endl;
	while (option != 0)
	{
		switch (option)
		{
		case 1:
			cout << "Enter row size of square matrix: ";
			cin >> sa;
			AllocateTriangularMatrix(a, sa);
			input(a, sa);
			cout << endl;
			break;

		case 2:
			print(a,sa);
			break;

		case 3:
			cout << "Enter row size of square matrix A: ";
			cin >> sa;
			AllocateTriangularMatrix(a, sa);
			input(a, sa);
			cout << endl;

			cout << "Enter row size of square matrix B: ";
			cin >> sb;
			AllocateTriangularMatrix(b, sb);
			input(b, sb);
			cout << endl;

			cout << "Matrix A: " << endl;
			print(a, sa);
			cout << "Matrix B: " << endl;
			print(b, sb);
			break;

		case 4:
			readFromFile(a, b, sa, sb);
			break;

		case 5:
			if (AddMatrices(a, b, c, sa, sb, sc) == true)
			{
				print(c, sc);
			}
			else
				cout << "Matrix addition is undefined as dimensions vary." << endl;
			break;

		case 6:
			if (MultiplyMatrices(a, b, c, sa, sb, sc) == true)
			{
				print(c, sc);
			}
			
			else
				cout << "Matrix multiplication is undefined as dimensions vary." << endl;
			break;

		case 7:
			int row;
			cout << "Enter row to be deleted: "<<endl;
			cin >> row;
			deleteRow(a, sa, row);
			cout << "Updated matrix: "<<endl;
			print(a, sa);
			break;

		case 8:
			swap(a, sa);
			break;
		}
		
		cout << "MENU" << endl;
		cout << "Please Enter: " << endl;
		cout << "0 - to exit the program." << endl;
		cout << "1 - to input a triangular matrix." << endl;
		cout << "2 - to print triangular matrix." << endl;
		cout << "3 - to input two triangular matrices." << endl;
		cout << "4 - to read two triangular matrices from file." << endl;
		cout << "5 - to add two triangular matrices." << endl;
		cout << "6 - to multiply two triangular matrices from file." << endl;
		cout << "7 - to delete a row from triangular matrix." << endl;
		cout << "8 - to swap two rows of a triangular matrix." << endl;

		cin >> option;
		cout << endl;
	}
	Deallocate(a, sa);
	if (b != nullptr)
	{
		Deallocate(b, sb);
	}
	if (c != nullptr)
	{
		Deallocate(c, sc);
	}
}