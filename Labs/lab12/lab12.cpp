#include <iostream>
#include <string>
using namespace std;

template <class type>
type surprise(type x, type y)
{
	return x + y;
}

template <class type>
type performOperation(type x, type y, char z)
{
	if (z == '*')
		return x * y;
	else if (z == '+')
		return x + y;
	else if (z == '-')
		return x - y;
	else if (z == '/')
		return x / y;
}

//template functons for ex2 first part
//template <class type>
//type GetMax(type x, type y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//template <class type>
//type GetMin(type x, type y)
//{
//	if (x < y)
//		return x;
//	else
//		return y;
//}

template <class type1, class type2>
type1 GetMax(type1 x, type2 y)
{
	if (x > y)
		return x;
	else
		return y;
}

template <class type1, class type2>
type1 GetMin(type1 x, type2 y)
{
	if (x < y)
		return x;
	else
		return y;
}

template <class type1, class type2, class type3>
type2 GetMax(type1 x, type2 y, type3 z)
{
	if (x > y && x > z)
		return x;
	else if (y > x && y > z)
		return y;
	else
		return z;
}

template <class type1, class type2, class type3>
type2 GetMin(type1 x, type2 y, type3 z)
{
	if (x < y && x < z)
		return x;
	else if(y<x && y < z)
		return y;
	else
		return z;
}

template <class type>
type increment(type x)
{
	return (x + 1);
}

template<>
char* increment<char *>(char* x)
{
	int l = strlen(x);
	cout << l << endl;
	for (int i = 0;i < l;i++)
	{
		if (x[i] >= 97 && x[i] <= 122)
		{
			x[i] = x[i] - 32;
		}
	}
	return x;
}

int main()
{
	//.................Ex0.................
	cout << "EX0:" << endl;
	cout << surprise(5, 7) << endl;
	cout << endl;
	string str1 = "Sunny";
	string str2 = " Day";
	cout << surprise(str1, str2) << endl;
	//.................Ex0..................

	//.................Ex1..................
	cout << "EX1:" << endl;
	int a, b; 
	char op;
	cout << "Enter first operand ";
	cin >> a;
	cout << "Enter second operand ";
	cin >> b;
	cout << "Enter operation ";
	cin >> op;
	if (op == '*' || op == '+' || op == '-' || op == '/')
	{
		cout<<performOperation(a, b, op)<<endl;
		float e = 5.5, f = 5.5;
		cout << "float:" <<performOperation(e, f, '+');
	}
	else
	{
		cout << "Wrong operation";
	}
	cout << endl;
	//.................Ex1..................


	//.................Ex2..................
	cout << "EX2:" << endl;
	//step 2
	/*int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax(i, j);
	n = GetMin(l, m);
	cout << k << endl;
	cout << n << endl;*/

	//step 4
	char i = 'Z';
	int  j = 6,k;
	long l = 10, m = 5,n;
	k = GetMax(i, m);
	n = GetMin(j, l);
	cout << k << endl;
	cout << n << endl;
	
	cout << GetMax(i, j, l) << endl;
	cout << GetMin(i, j, l) << endl;
	//.................Ex3..................


	//.................Ex4..................
	cout << "EX3:" << endl;
	cout << increment(i) << endl;
	cout << increment(j) << endl;
	cout << increment(l) << endl;
	
	const int s = 5;
	char arr[s] = { 'a','b','A','Z','\0' };
	cout << increment(arr) << endl;
	//.................Ex4..................

	system("pause");
}

//Exercise 1:
//1. Output: 12
//2. Output: Sunnay Day (concatenates the two strings)

//Exercise 2:
//3. Removing <int> and <long> makes no difference to the output
//5. removing makes no difference to output.