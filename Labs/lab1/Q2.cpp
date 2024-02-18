#include <iostream>
using namespace std;
int main()
{
	char str[] = "Randomtext";
	cout << "String: " << str << endl;
	cout << "Reversed String: ";
	int l = strlen(str);
	for (int i = l - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	cout << endl;
}