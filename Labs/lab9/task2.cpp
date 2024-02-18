#include <iostream>
#include "task2.h"
using namespace std;

 //Ship class definition

ship::ship()
{
	name = nullptr;
	year = nullptr;
}
ship::ship(const char* n,const char* y)
{
	name = nullptr;
	year = nullptr;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	year = new char[strlen(y) + 1];
	strcpy(year, y);
}
char* ship::get_name()
{
	return name;
}

char* ship::get_year()
{
	return year;
}

void ship::set_name(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void ship::set_year(const char* y)
{
	year = new char[strlen(y) + 1];
	strcpy(year, y);
}

ship::~ship()
{
	if (name!=nullptr)
		delete name;
	if (year != nullptr)
		delete year;
}

void ship::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Ship year: " << year << endl;
}

//CruiseShip class definition

CruiseShip::CruiseShip()
{
	maxp = 0;
}

CruiseShip::CruiseShip(int maxNum, const char* n, const char* y) : ship (n, y)
{
	maxp = maxNum;
}

void CruiseShip::Set_maxPassengers(int maxp)
{
	this->maxp = maxp;
}

int CruiseShip::Get_maxPassengers()
{
	return maxp;
}

void CruiseShip::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Maximum Passengers: " << maxp << endl;
}

//CargoShip class definition

CargoShip::CargoShip()
{
	CargoCapacity = 0;
}

CargoShip::CargoShip(int CargoCapacity, const char* n, const char* y) : ship(n, y)
{
	this->CargoCapacity = CargoCapacity;
}

void CargoShip::Set_CC(int CargoCapacity)
{
	this->CargoCapacity = CargoCapacity;
}

int CargoShip::Get_CC()
{
	return CargoCapacity;
}

void CargoShip::print()
{
	cout << "Ship Name: " << name << endl;
	cout << "Cargo Capacity: " << CargoCapacity << " tonnes" << endl;
}