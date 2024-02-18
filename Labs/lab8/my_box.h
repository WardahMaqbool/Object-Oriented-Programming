#pragma once
#include <iostream>
using namespace std;

class box
{
	int length;
	int breadth;
	int height;
public:
	static int objectCount;
	box();
	box(int length, int breadth, int height);
	void Set(int length, int breadth, int height);
	void Set(const box& a);
	void Get(int& l, int& b, int& h);
	static int getCount();
	double Volume();
	double Area();
	friend void print_surface_area(box& a);
	friend void double_data_members(box& a);
};