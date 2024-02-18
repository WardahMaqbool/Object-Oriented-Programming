#include <iostream>
#include "task1.h"
using namespace std;


Tyre::Tyre()
{
	width = nullptr;
	aspect_ratio = nullptr;
	diameter = nullptr;
}

Tyre::Tyre(int w, int a, int d)
{
	width = new int;
	aspect_ratio = new int;
	diameter = new int;
	*width = w;
	*aspect_ratio = a;
	*diameter = d;
}
Tyre::Tyre(const Tyre& a)
{
	width = new int;
	aspect_ratio = new int;
	diameter = new int;
	*width = a.width[0];
	*aspect_ratio = a.aspect_ratio[0];
	*diameter = a.diameter[0];
}
int Tyre::Get_w()
{
	return *width;
}
int Tyre::Get_a()
{
	return *aspect_ratio;
}
int Tyre::Get_d()
{
	return *diameter;
}

void Tyre::PrintTyre()
{
	cout << "Tyre Information:" << endl;
	cout <<"Width: "<< *width << endl;
	cout << "Aspect_ratio: " << *aspect_ratio << endl;
	cout << "Diameter: " << *diameter << endl;
}
Tyre::~Tyre()
{
	if (width != nullptr)
	{
		delete width;
		width = nullptr;
	}
	if (aspect_ratio != nullptr)
	{
		delete aspect_ratio;
		aspect_ratio = nullptr;
	}
	if (diameter != nullptr)
	{
		delete diameter;
		diameter = nullptr;
	}
}

Car::Car()
{
	model = nullptr;
	company = nullptr;
	t1 = nullptr;
}
Car::Car(int m, const char* c, const Tyre& x)
{
	model = nullptr;
	company = nullptr;
	t1 = nullptr;
	model = new int;
	*model = m;
	company = new char[strlen(c) + 1];
	strcpy(company, c);
	t1 = new Tyre(x);
}

void Car::PrintCar()
{
	cout << "Car Details:"<<endl;
	cout << "Model: " << *model << endl;
	cout << "Company: " << company << endl;
	cout << "Tyre width: " << t1->Get_w() << endl;
	cout << "Tyre aspect_ratio: " << t1->Get_a() << endl;
	cout << "Tyre diameter: " << t1->Get_d() << endl;

}
Car::~Car()
{
	if (model != nullptr)
		delete model;
	if (company != nullptr)
		delete company;
	if (t1 != nullptr)
		t1->~Tyre();
}

