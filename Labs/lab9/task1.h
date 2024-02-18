#pragma once
#include <iostream>
using namespace std;

class Tyre
{
private:
	int* width;
	int* aspect_ratio;
	int* diameter;
public:
	//Constructors, Getters and Destructor
	Tyre();
	Tyre(int w, int a, int d);
	Tyre(const Tyre&);
	int Get_w();
	int Get_a();
	int Get_d();
	void PrintTyre();
	~Tyre();
};

class Car
{
private:
	int* model;
	char* company;
	Tyre* t1;
public:
	Car();
	Car(int m,const char* c, const Tyre&);
	void PrintCar();
	~Car();
};
