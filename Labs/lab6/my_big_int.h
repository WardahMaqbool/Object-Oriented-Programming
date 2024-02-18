#pragma once
#include <iostream>
using namespace std;

class BiggerInt
{
	int* big_int_;
	int size_int;
public:
	BiggerInt();
	BiggerInt(const int* obj, int size);
	BiggerInt(const BiggerInt& obj);
	void assign(const BiggerInt& obj);
	void assign(const int* big_int, int size);
	void append(const BiggerInt& obj);
	void append(const int* big_int, int size);
	int compareTo(const BiggerInt& obj);
	int compareTo(const int* big_int, int size);
	void display();
	~BiggerInt();
};