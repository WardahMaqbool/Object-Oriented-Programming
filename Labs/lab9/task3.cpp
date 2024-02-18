#include <iostream>
#include "task3.h"
using namespace std;


shape::shape()
{
	char* name = nullptr;
}

shape::shape(const char* name)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

void shape::printName()
{
	cout << name;
}

rectangle::rectangle()
{
	width = 0;
	height = 0;
}
rectangle::rectangle(float h, float w, const char* s):shape(s)
{
	height = h;
	width = w;
}
void rectangle::area_calculator()
{
	float area = width * height;
	cout << "Area: " << area;
}

triangle::triangle()
{
	base = 0;
	height = 0;
}
triangle::triangle(float b, float h, const char* s) :shape(s)
{
	base = b;
	height = h;
}
void triangle::area_calculator()
{
	float area = 0.5 * base * height;
	cout << "Area: " << area;
}

circle::circle()
{
	radius = 0;
}
circle::circle(float r, const char* s) :shape(s)
{
	radius = r;
}
void circle::area_calculator()
{
	float area = 3.142 * radius * radius;
	cout << "Area: " << area;
}