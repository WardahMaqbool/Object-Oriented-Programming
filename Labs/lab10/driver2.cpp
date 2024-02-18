#include <iostream>
#include "person.h"
#include "student.h"
#include "Employee.h"
#include <string>
using namespace std;

int main()
{
    const int size = 2;
    Person** array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = new Person * [2];
    }

    for (int i = 0; i < size; i++)
    {
        array[i][0] = new Student("DK", 6.3, "Defence Public School");
        array[i][1] = new Employee("DK", 6.3, "Web", 1);

        array[i][0]->printInfo();
        cout << endl << endl;
        array[i][1]->printInfo();
        cout << endl << endl;

    }

    for (int i = 0; i < size; i++)
    {
        array[i][0] = new Student("dk", 6.3, "Defence Public School");
        array[i][1] = new Employee("dk", 6.3, "Web", 1);

        delete array[i][0];
        cout << endl << endl;
        delete array[i][1];
        cout << endl << endl;

        array[i][0] = nullptr;
        array[i][1] = nullptr;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = new Person * [2];

        delete array[i];
        cout << endl << endl;
        array[i] = nullptr;

    }
}