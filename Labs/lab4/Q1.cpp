#include <iostream>
#include <cstring>
using namespace std;
void reverse(char* s);

int main()
{
	char str[50];
	cout << "Enter String: ";
	cin.getline(str,50);
	reverse(str);
    cout << endl;
    cout << "Reversed String: ";
    cout << str;
}

void reverse(char* s)
{
    int l;
    l = strlen(s);
    char* start = s, *end = s;

    for (int i = 0; i < l - 1; i++)
    {
        end++;
    }

    for (int i = 0; i < l / 2; i++) 
    {
        char temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
}