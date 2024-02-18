#pragma once
#include <iostream>
using namespace std;

class shape
{
protected:
	char* name;
public:
	shape();
	shape(const char* name);
	virtual void area_calculator() {}
	void printName();
};

class rectangle : public shape
{
private:
	float height;
	float width;
public:
	rectangle();
	rectangle(float h, float w, const char* s);
	void area_calculator();
};

class triangle : public shape
{
private:
	float base;
	float height;
public:
	triangle();
	triangle(float b, float h, const char* s);
	void area_calculator();
};

class circle : public shape
{
private:
	float radius;
public:
	circle();
	circle(float r, const char* s);
	void area_calculator();
};
