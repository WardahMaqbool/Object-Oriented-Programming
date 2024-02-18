#include <iostream>
using namespace std;
void input(int** arr, int m, int n);
void display(int** arr, int m, int n);
void sum(int** arr, int m, int n);
void rowSum(int** arr, int m, int n);
void colSum(int** arr, int m, int n);
int** transpose(int** arr, int m, int n);
void menu();

int main()
{
	menu();
}

void menu()
{
	int m, n;
	cout << "Enter number of rows: ";
	cin >> m;
	cout << "Enter number of columns: ";
	cin >> n;
	int** ptr = new int* [m];
	for (int i = 0; i < m; i++)
		ptr[i] = new int[n];
	int option=10;
	while (option != 0)
	{
		cout << endl;
		cout << "MENU" << endl;
		cout << "Please Enter: " << endl;
		cout << "0 to exit the program" << endl;
		cout << "1 to enter values in the matrix." << endl;
		cout << "2 to display the matrix." << endl;
		cout << "3 to display the sum of all elements of matrix." << endl;
		cout << "4 to display the row sum of matrix." << endl;
		cout << "5 to display the column sum of matrix." << endl;
		cout << "6 to transpose the matrix." << endl;
		cin >> option;

		cout << endl;

		switch (option)
		{
		case 1:
			input(ptr, m, n);
			break;

		case 2:
			display(ptr, m, n);
			break;

		case 3:
			sum(ptr, m, n);
			break;

		case 4:
			rowSum(ptr, m, n);
			break;

		case 5:
			colSum(ptr, m, n);;
			break;

		case 6:
			int** tmatrix = transpose(ptr, m, n);
			display(tmatrix, n, m);
			break;
		}
	}
}

void input(int** arr, int m, int n)
{
	cout << "Enter values to populate the 2-D array: ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>arr[i][j];
		}
	}
}

void display(int** arr, int m, int n)
{
	cout << "matrix: ";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void sum(int** arr, int m, int n)
{
	int sum=0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum = arr[i][j] + sum;
		}
	}
	cout << "Sum of all elements is : ";
	cout << sum;
	cout << endl;
}

void rowSum(int** arr, int m, int n)
{
	int rowSum,i;
	for ( i = 0; i < m; i++)
	{
		rowSum = 0;
		for (int j = 0; j < n; j++)
		{
			rowSum = arr[i][j] + rowSum;
		}
		cout<< "row sum of row "<<i+1<<" is : ";
		cout << rowSum;
		cout << endl;
	}
}

void colSum(int** arr, int m, int n)
{
	int colSum,j;
	for (int i = 0; i < m; i++)
	{
		colSum = 0;
		for ( j = 0; j < n; j++)
		{
			colSum = arr[j][i] + colSum;
		}
		cout << "column Sum of column " << j + 1 << " is : ";
		cout << colSum;
		cout << endl;
	}
}

int** transpose(int** arr, int m, int n)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = arr[j][i];
		}
	}
	return a;
}