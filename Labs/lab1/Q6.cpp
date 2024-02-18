#include <iostream>
using namespace std;
void allocate(float* &l, float* &w);
void input(float* w, float* l);
void print(float* w, float* l);
float area(float* w, float* l);
void deallocate(float* &w, float* &l);
int main()
{
	float* p = nullptr, * q = nullptr;
	allocate(p,q);
	input(p, q);
	print(p, q);
	cout<<"Area: "<< area(p, q);
	deallocate(p,q);
}

void allocate(float* &l, float* &w)
{
	l = new float;
	w = new float;
}

void input(float* w, float* l)
{
	cout << "Enter the length: ";
	cin >> *l;
	cout << "Enter the width: ";
	cin >> *w;
}

void print(float* w, float* l)
{
	cout << "Length = " << *l << endl;
	cout << "Width = " << *w<<endl;
}

float area(float* w, float* l)
{
	float area = *l * (*w);
	return area;
}

void deallocate(float* &w, float* &l)
{
	delete w;
	w = nullptr;
	delete l;
	l = nullptr;
}