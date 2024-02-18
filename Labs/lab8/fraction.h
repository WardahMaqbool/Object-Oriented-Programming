#pragma once
#include <iostream>
using namespace std;

class fraction
{
	int num, denum;
public:
	fraction(int = 0, int = 1); //Constructor
	fraction(const fraction& f); //Copy constructor
	void operator!(void) const; // print the fraction
	fraction operator-(void) const; // negative of fraction
	fraction operator*(void) const; // reciprocal of fraction

	//Fraction’s Arithematic Operators
	fraction& operator+=(const fraction&); //frac1 +=frac2
	fraction& operator-=(const fraction&); //frac1 -=frac2
	fraction& operator*=(const fraction&); //frac1 *=frac2
	fraction& operator/=(const fraction&); //frac1 /=frac2

	// Fraction’s Relational Operators.
	bool operator> (const fraction&) const;
	bool operator< (const fraction&) const;
	bool operator==(const fraction&) const;
	bool operator!=(const fraction&) const;

	fraction& operator++(); // prefix operator returns by reference
	fraction operator++(int); // postix operator returns by value
	friend ostream& operator<< (ostream&, const fraction&);
	friend istream& operator>> (istream&, fraction&);
};
