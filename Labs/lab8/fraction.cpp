#include <iostream>
#include "fraction.h"
using namespace std;

fraction::fraction(int num, int denum)
{
	this->num = num;
	this->denum = denum;
}

fraction::fraction(const fraction& f)
{
	num = f.num;
	denum = f.denum;
}

void fraction::operator!(void) const
{
	cout << num << "/" << denum;
	cout << endl;
}
fraction fraction::operator-(void) const
{
	fraction f(*this);
	f.num = -f.num;
	return f;
}
fraction fraction::operator*(void) const
{
	fraction f(*this);
	int temp;
	temp = f.num;
	f.num = f.denum;
	f.denum = temp;
	return f;
}
//ticTacToe::ticTacToe(const ticTacToe& a)
//{
//	N = a.N;
//	board = new char* [N];
//	for (int i = 0; i < N; i++)
//	{
//		board[i] = new char[N];
//	}
//}


fraction& fraction::operator+=(const fraction& f)
{
	num = (num * f.denum) + (denum * f.num);
	denum = denum * f.denum;
	return *this;
}
fraction& fraction::operator-=(const fraction& f)
{
	num = (num * f.denum) - (denum * f.num);
	denum = denum * f.denum;
	return *this;
}
fraction& fraction::operator*=(const fraction& f)
{
	num = num * f.num;
	denum = denum * f.denum;
	return *this;
}
fraction& fraction::operator/=(const fraction& f)
{
	num = num * f.denum;
	denum = denum * f.num;
	return *this;
}

bool fraction::operator>(const fraction& f) const
{
	float f1, f2;
	f1 = num / denum;
	f2 = f.num / f.denum;
	if (f1 > f2)
		return true;
	return false;
}

bool fraction::operator<(const fraction& f) const
{
	float f1, f2;
	f1 = num / denum;
	f2 = f.num / f.denum;
	if (f1 < f2)
		return true;
	return false;
}
bool fraction::operator==(const fraction& f) const
{
	if (num == f.num && denum == f.denum)
		return true;
	return false;
}
bool fraction::operator!=(const fraction& f) const
{
	if (num != f.num || denum != f.denum)
		return true;
	return false;
}

fraction& fraction::operator++()
{
	++num;
	++denum;
	return *this;
}
fraction fraction::operator++(int)
{
	fraction f(*this);
	num++;
	denum++;
	return f;
}

ostream& operator << (ostream& out, const fraction& p)
{
	out << "num:" << p.num << endl;
	out << "denum:" << p.denum << endl;
	return out;
}
istream& operator >> (istream& in, fraction& p) 
{
	cout << "Enter numerator: ";
	in >> p.num;
	cout << endl;
	cout << "Enter denominator: ";
	in >> p.denum;
	cout << endl;
	return in;
}