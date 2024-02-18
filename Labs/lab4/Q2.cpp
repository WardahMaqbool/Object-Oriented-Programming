#include <iostream>
#include <string>
using namespace std;
int GetCharacterCount(char* myString, char c);
int GetCharacterCount2(char* myString, char c);

int main()
{
	//exercise 1
	char mystring[20];
	char ch ='a';
	cout << GetCharacterCount(mystring, ch);
	cout << " characters found ";
	cout << endl;

	// exercise 2
	cout << GetCharacterCount2(mystring, ch);
	cout << " characters found ";
	cout << endl;
}

int GetCharacterCount(char* myString, char c)
{
	cout << "Enter String: ";
	cin >> myString;
	cout << endl;
	cout << "Enter ch : ";
	cin >> c;
	cout << endl;
	int count = 0;
	int l = strlen(myString);
	for (int i = 0; i < l; i++)
	{
		if (myString[i] == c)
			count++;
	}
	return count;
}

int GetCharacterCount2(char* myString, char c)
{
	cin.ignore();
	cout << endl;
	cout << "Enter String: ";
	cin.getline(myString, 50);
	cout << endl;
	cout << "Enter ch : ";
	cin >> c;
	cout << endl;
	int count = 0;
	int l = strlen(myString);
	for (int i = 0; i < l; i++)
	{
		if (myString[i] == c)
			count++;
	}
	return count;
}