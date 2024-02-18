#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class shape
{
public:
	virtual void Area() = 0;
	virtual void Perimeter() = 0;
	virtual void GetDiagonal() = 0;
	virtual void print() {}
	virtual ~shape()
	{
		cout << "shape Destructor." << endl;
	}
};

class Rectangle : public shape
{
private:
	int length;
	int width;
public:
	Rectangle(int l, int w)
	{
		length = l;
		width = w;
	}
	void print()
	{
		cout << endl;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
	virtual ~Rectangle()
	{
		cout << "Rectangle Distructor." << endl;
	}
	void Area()
	{
		int area = length * width;
		cout << "Area: " << area << endl;
	}
	void Perimeter()
	{
		int p = (2 * length) + (2 * width);
		cout << "Perimeter: " << p << endl;
	}
	void GetDiagonal()
	{
		float d2;
		d2 = (length * length) + (width * width);
		cout << "Diagonal: " << sqrt(d2) << endl;
	}
};