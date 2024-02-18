#include <iostream>
using namespace std;
class Employee
{
	int sal;
	int hours;

public:
	void getInfo(int s, int h)
	{
		sal = s;
		hours = h;
	}
	void AddSal()
	{
		if (sal < 500)
		{
			sal = sal + 10;
		}
	}
	void AddWork()
	{
		if (hours > 6)
		{
			sal = sal + 5;
		}
	}
	int print()
	{
		return sal;
	}
};

int main()
{
	Employee x;
	x.getInfo(490, 8);
	cout << "Initial Salary: " << x.print();
	cout << endl;
	x.AddSal();
	cout << "Salary after AddSal function: " << x.print();
	cout << endl;
	x.AddWork();
	cout<<"Salary after Addwork function: "<< x.print();
}
