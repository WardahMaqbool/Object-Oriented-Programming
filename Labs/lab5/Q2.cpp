#include <iostream>
using namespace std;

class Rectangle
{
private:
	int length;
	int width;
	int area;

public:
	void set_length(int l)
	{
		if (l < 0)
		{
			cout << "length should be greater than zero" << endl;
		}
		else
			length = l;
	}

	void set_width(int w)
	{
		if(w < 0)
		{
			cout << "width should be greater than zero" << endl;
		}
		width = w;
	}
	void calculate_area()
	{
		int area = length * width;
	}
	
	int get_length()
	{
		return length;
	}

	int get_width()
	{
		return length;
	}

	int get_area()
	{
		return length;
	}

	bool is_square()
	{
		if (length == width)
		{
			return true;
		}
		return false;
	}

	void display()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};

/*int main()
{
	Rectangle A;
	A.set_length(5);
	cout << "Length: ";
	cout << A.get_length();
	cout << endl;

	A.set_width(5);
	cout << "width: ";
	cout << A.get_width();
	cout << endl;

	A.calculate_area();
	cout<<"Area: "<< A.get_area();
	cout << endl;

	cout<<"Square? "<<A.is_square();
	cout << endl;

	A.display();
}*/