#include <iostream>
#include <cmath>
using namespace std;

class POINT
{
private:
	float X;
	float Y;
	float Z;
public:
	void setPoint(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float Z);

	void getPoint(float& x, float& y, float& z) const;
	float getX()const;
	float getY()const;
	float getZ()const;

	void Input();
	void output();

	float Calculate_Distance(const POINT& p1);

	void printPoint(const POINT& p);
	POINT find_closest(const POINT& p1, const POINT& p2);
};

void POINT::setPoint(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

void POINT::setX(float x)
{
	X = x;
}

void POINT::setY(float y)
{
	Y = y;
}

void POINT::setZ(float z)
{
	Z = z;
}

void POINT:: getPoint(float& x, float& y, float& z) const
{
	x = X;
	y = Y;
	z = Z;
}

float POINT::getX() const
{
	return X;
}

float POINT::getY() const
{
	return Y;
}

float POINT::getZ() const
{
	return Z;
}

void POINT::Input()
{
	cout << "Enter value for X:";
	cin >> X;
	cout << endl;
	cout << "Enter value for Y:";
	cin >> Y;
	cout << endl;
	cout << "Enter value for Z:";
	cin >> Z;
	cout << endl;
}

void POINT::output()
{
	cout << "X: " << X << endl;
	cout << "Y: " << Y << endl;
	cout << "Z: " << Z << endl;
}

float POINT::Calculate_Distance(const POINT& P)
{
	float d1 = P.X - X;
	float d2 = P.Y - Y;
	float d3 = P.Z - Z;

	float a = ((d1 * d1) + (d2 * d2) + (d3 * d3));
	return sqrt(a);
}

void POINT::printPoint(const POINT& p)
{
	cout << "X: " << p.X << endl;
	cout << "Y: " << p.Y << endl;
	cout << "Z: " << p.Z << endl;

}

POINT POINT::find_closest(const POINT& p1, const POINT& p2)
{
	float d1 = Calculate_Distance(p1);
	float d2 = Calculate_Distance(p2);
	if (d2 <= d1)
		return p2;
	else
		return p1;
}

int main()
{
	POINT p;
	p.setPoint(7, 4, 3);
	cout << "Point p: " << endl;
	p.printPoint(p);

	POINT q;
	q.Input();
	cout << "Point q: " << endl;
	q.output();

	POINT r;
	r.setX(10);
	r.setY(5);
	r.setZ(7);
	cout << "Point r: " << endl;
	cout << "X: " << r.getX() << endl;
	cout << "Y: " << r.getY() << endl;
	cout << "Z: " << r.getZ() << endl;

	cout << "Distance between p and q: " << p.Calculate_Distance(q);
	cout << endl;
	cout << "Distance between p and r: " << p.Calculate_Distance(r);
	cout << endl;

	cout << "Closer point is: ";
	p.find_closest(q, r).output();
	
}