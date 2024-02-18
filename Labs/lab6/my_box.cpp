#include <iostream>
#include "my_box.h"
using namespace std;

int box::objectCount = 0;

box::box()
{
	length = 0;
	breadth = 0;
	height = 0;
	objectCount++;
}

box::box(int length, int breadth, int height)
{
	this->length = length;
	this->breadth = breadth;
	this->height = height;
	objectCount++;
}

void box::Set(int length, int breadth, int height)
{
	this->length = length;
	this->breadth = breadth;
	this->height = height;
}

void box::Set(const box& a)
{
	length = a.length;
	breadth = a.breadth;
	height = a.height;
}

void box::Get(int& l, int& b, int& h)
{
	l = length;
	b = breadth;
	h = height;
}

int box::getCount()
{
	return objectCount;
}

double box::Volume()
{
	double v = length * breadth * height;
	return v;
}

double box::Area()
{
	double area = (2 * length * breadth) + (2 * length * height) + (2 * breadth * height);
	return area;
}