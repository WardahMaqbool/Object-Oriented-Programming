#include <iostream>
using namespace std;

class Mamals
{
public:
	void printM()
	{
		cout << "I am a Mamal." << endl;
	}
};

class MarineAnimals
{
public:
	void printMA()
	{
		cout << "I am a Marine Animal." << endl;
	}
};

class BlueWhale: public Mamals, public MarineAnimals
{
public:
	void printBw()
	{
		cout << "I belong to both categories: Mamals as well as Marine Animals." << endl;
	}
};

int main()
{
	Mamals m;
	m.printM();

	MarineAnimals mA;
	mA.printMA();

	BlueWhale Bw;
	Bw.printBw();

	Bw.printM();
	Bw.printMA();
}