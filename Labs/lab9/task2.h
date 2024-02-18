#pragma once
#include <iostream>
using namespace std;

class ship
{
private:
	char* year;
public:
	char* name;
	ship();
	ship(const char* n, const char* y);
	char* get_name();
	char* get_year();
	void set_name(const char* n);
	void set_year(const char* y);
	void print();
	~ship();
};

class CruiseShip : public ship
{
private:
	int maxp;
public:
	CruiseShip();
	CruiseShip(int maxNum, const char* n, const char* y);
	void Set_maxPassengers(int maxp);
	int Get_maxPassengers();
	void print();
};

class CargoShip :public ship
{
private:
	int CargoCapacity;
public:
	CargoShip();
	CargoShip(int CargoCapacity, const char* n, const char* y);
	void Set_CC(int CargoCapacity);
	int Get_CC();
	void print();
};