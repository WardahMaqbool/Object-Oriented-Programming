#include <iostream>
#include "teacher.h"
#include "student.h"
using namespace std;

int main()
{
	Teacher tl[3]=  { Teacher(1, "Mr.Dilawar"),
					  Teacher(2, "Ms.Abeeda"),
					  Teacher(3, "Ms.Abiha")
					};

	cout << "Display function called"<<endl;
	char rn[10] = "20L1074";
	char name[10] = "Wardah";
	Student S1(rn, name, tl, 3);
	S1.displayS();
	S1.~Student();
}