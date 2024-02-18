#include <iostream>
#include "my_big_int.h"
using namespace std;

BiggerInt::BiggerInt()
{
	big_int_ = nullptr;
	size_int = 0;
}
BiggerInt::BiggerInt(const int* obj, int size)
{
	size_int = size;
	big_int_ = new int[size_int];
	for (int i = 0; i < size; i++)
	{
		big_int_[i] = obj[i];
	}
}
BiggerInt::BiggerInt(const BiggerInt& obj)
{
	cout << "Copy Constructor Called" << endl;;
	size_int = obj.size_int;
	big_int_ = new int[size_int];
	for (int i = 0; i < size_int; i++)
	{
		this->big_int_[i] = obj.big_int_[i];
	}
}
void BiggerInt::assign(const BiggerInt& obj)
{
	size_int = obj.size_int;
	int* temp = new int[size_int];
	for (int i = 0; i < obj.size_int; i++)
	{
		temp[i] = obj.big_int_[i];
	}
	delete[] big_int_;
	big_int_ = temp;

}
void BiggerInt::assign(const int* big_int, int size)
{
	size_int = size;
	int* temp = new int[size_int];
	for (int i = 0; i < size; i++)
	{
		temp[i] = big_int[i];
	}
	delete[] big_int_;
	big_int_ = temp;
}

void BiggerInt::append(const BiggerInt& obj)
{
	int s = size_int + obj.size_int;
	int* temp = new int[s];
	for (int i = 0; i < size_int; i++)
	{
		temp[i] = big_int_[i];
	}
	for (int i = size_int,j = 0; i < s; i++, j++)
	{
		temp[i] = obj.big_int_[j];
	}
	delete[] big_int_;
	big_int_ = temp;
	size_int = s;
}


void BiggerInt::append(const int* big_int, int size)
{
	int s = size_int + size;
	int* temp = new int[s];
	for (int i = 0; i < size_int; i++)
	{
		temp[i] = big_int_[i];
	}
	for (int i = size_int, j = 0; i < s; i++, j++)
	{
		temp[i] = big_int[j];
	}
	delete[] big_int_;
	big_int_ = temp;
	size_int = s;
}

int BiggerInt::compareTo(const BiggerInt& obj)
{
	for (int i = 0; i < size_int; i++)
	{
		if (size_int == obj.size_int)
		{
			if (this->big_int_[i] == obj.big_int_[i])
				return 0;

			else if (this->big_int_[i] < obj.big_int_[i])
				return 1;
		}
	}
	return 2;
}
int BiggerInt::compareTo(const int* big_int, int size)
{
	for (int i = 0; i < size_int; i++)
	{
		if (size_int == size)
		{
			if (this->big_int_[i] == big_int[i])
				return 0;
			if (this->big_int_[i] < big_int[i])
				return 1;
		}	
	}
	return 2;
}
void BiggerInt::display()
{
	if (big_int_ == nullptr)
		cout << "No Value Assigned";
	else
		for (int i = 0; i < size_int; i++)
		{
			cout << big_int_[i] << " ";
		}
	cout << endl;
}

BiggerInt::~BiggerInt()
{
	if (big_int_ != nullptr)
	{
		delete big_int_;
		big_int_ = nullptr;
	}
}