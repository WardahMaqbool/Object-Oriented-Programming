#include <iostream>
#include "Ex2.h"
using namespace std;

int main()
{
	TeachingAssistant TA;
	TA.id();
	TA.gpa();
	TA.enroll("course");
	TA.pay(1000);
	TA.grade();
	TA.teach("course");
	TA.getpaid();
}