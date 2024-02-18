#include<iostream>
using namespace std;
void allocate(char*& str, int s);
void deallocate(char*& str);
void StringConcatenate(char* str1, char* &str2);
void CompressString(char* &str);
char* ReverseSentence(char* str);
void pluralWords(char** &s, int wordCount);
void allocate2D(char** &ptr,int& rows, int& cols);
void input(char** a, int rows);
void print2D(char** a, int rows);
void deallocate2D(char** a, int rows);
void menu();


int main()
{
	menu();
}
void allocate(char* &str, int s)
{
	str = new char[s];
}
void deallocate(char* &str)
{
	delete[] str;
	str = nullptr;
}
void StringConcatenate(char* str1, char* &str2)
{
	//appending str1 at the end of str2
	int s1 = strlen(str1);
	int s2 = strlen(str2);
	str2[s2] = ' ';
	int i, j;
	for (i = s2+1,j = 0; i < s2+s1+1 && j<s1; i++,j++)
	{
		str2[i] = str1[j];
	}
	str2[i] = '\0';
	
	//reallocating string to new array of appropriate size
	int s3 = (strlen(str2)+1);
	char* str3 = new char[s3];
	for (int i = 0; i < s3; i++)
	{
		str3[i] = str2[i];
	}
	str3[i] = '\0';
	deallocate(str2);
	str2 = str3;
}

void CompressString(char* &str)
{
	int i = 0,j = 0,k = 0,s = 1;
	
	for (int k = 0; str[k]!='\0'; k++)
	{
		char ch = str[k];
		int l = strlen(str);
		for (i = k, j = k+1; i < l; i++)
		{
			if (str[i] != ch)
			{
				str[j] = str[i];
				j++;
			}
			if (i  == l - 1)
			{
				str[j] = '\0';
			}
		}
		str[j] = '\0';
	}

	// reallocating to new array of appropriate size
	int size = (strlen(str))+1;
	char* comp = new char[size];
	for (int i = 0; i < size; i++)
	{
		comp[i] = str[i];
	}
	deallocate(str);
	str = comp;
	cout << "Compressed String: " << comp << endl;
}

char* ReverseSentence(char* str)
{
	int l = strlen(str);
	char* r;
	allocate(r, l);
	int i, j,k = 0,x = l;
	for (i = x; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			j = i + 1;
			x = i - 1;
			for (; str[j] != '\0' && str[j] != ' '; j++)
			{
				r[k] = str[j];
				k++;
			}
			r[k++] = ' ';
		}
		
		else if (i == 0)
		{
			j = i;
			for (;str[j] != ' '; j++)
			{
				r[k] = str[j];
				k++;
			}
		}
	}
	r[l] = '\0';
	return r;
}

void pluralWords(char** &a, int wordCount)
{
	char** reallocate = new char* [wordCount];
	for (int i = 0; i < wordCount; i++)
	{
		int l = strlen(a[i]);
		int j = l - 2;
		if (a[i][j] == 'f' && a[i][j + 1] == 'f')
		{
			a[i][j + 2] = 's';
			a[i][j + 3] = '\0';
		}
		else if (a[i][j] == 'o' && a[i][j + 1] == 'n')
		{
			a[i][j] = 'a';
			a[i][j + 1] = '\0';
		}
		else if (a[i][j] == 'u' && a[i][j + 1] == 's')
		{
			a[i][j] = 'i';
			a[i][j + 1] = '\0';
		}
		else if (((a[i][j] == 'c' || a[i][j] == 's') && a[i][j + 1] == 'h') || a[i][j + 1] == 'x' || (a[i][j - 1] == 'a' && a[i][j] == 't') && a[i][j + 1] == 'o' ||
			((a[i][j] != 'a' && a[i][j] != 'e' && a[i][j] != 'i' && a[i][j] != 'o' && a[i][j] != 'u') && a[i][j + 1] == 'z'))
		{
			a[i][j + 2] = 'e';
			a[i][j + 3] = 's';
			a[i][j + 4] = '\0';
		}
		else if (a[i][j] == 'i' && a[i][j + 1] == 's')
		{
			a[i][j] = 'e';
		}
		else if ((a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i') && a[i][j + 1] == 'z')
		{
			a[i][j + 2] = 'z';
			a[i][j + 3] = 'e';
			a[i][j + 4] = 's';
			a[i][j + 5] = '\0';
		}
		else if ((a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i') && a[i][j + 1] == 's')
		{
			a[i][j + 2] = 's';
			a[i][j + 3] = 'e';
			a[i][j + 4] = 's';
			a[i][j + 5] = '\0';
		}
		else if (a[i][j] == 's' && a[i][j + 1] == 's')
		{
			a[i][j + 2] = 'e';
			a[i][j + 3] = 's';
			a[i][j + 4] = '\0';
		}
		else if (a[i][j] == 'f' && a[i][j + 1] == 'e')
		{
			a[i][j] = 'v';
			a[i][j + 1] = 'e';
			a[i][j + 2] = 's';
			a[i][j + 3] = '\0';
		}
		else if (a[i][j + 1] == 'f')
		{
			a[i][j + 1] = 'v';
			a[i][j + 2] = 'e';
			a[i][j + 3] = 's';
			a[i][j + 4] = '\0';
		}
		else if (a[i][j + 1] == 'y')
		{
			if (a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i' || a[i][j] == 'o' || a[i][j] == 'u')
			{
				a[i][j + 2] = 's';
				a[i][j + 3] = '\0';
			}
			else
			{
				a[i][j + 1] = 'i';
				a[i][j + 2] = 'e';
				a[i][j + 3] = 's';
				a[i][j + 4] = '\0';
			}
		}
		else
		{
			a[i][j + 2] = 's';
			a[i][j + 3] = '\0';
		}

		int l2 = strlen(a[i]);
		reallocate[i] = new char[l2+1];
		for (int k = 0; k < l2+1; k++)
		{
			reallocate[i][k] = a[i][k];
		}

	}
	deallocate2D(a,wordCount);
	a = reallocate;
	print2D(reallocate, wordCount);
}

void allocate2D(char** &ptr, int& rows, int& cols)
{
	cout << "Enter number of words: ";
	cin >> rows;
	cols = 15;
	ptr = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new char[cols];
	}
	cout << endl;
}

void input(char** a,int rows)
{
	cout << "Enter " << rows << " singular words: " << endl;
	for (int i = 0; i < rows; i++)
	{
		cin>>a[i];
	}
	cout << endl;
}

void print2D(char** a, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; a[i][j] != '\0'; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

void deallocate2D(char** a, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = nullptr;
}

void menu()
{
	cout << "MENU" << endl;
	cout << "Please Enter: " << endl;
	cout << "0 - to exit the program." << endl;
	cout << "1 - to concatenate two strings." << endl;
	cout << "2 - to compress string." << endl;
	cout << "3 - to reverse words in a string." << endl;
	cout << "4 - to view plural of entered words." << endl;
	
	int option;
	cin >> option;
	cout << endl;
	while (option != 0)
	{
		char* str;
		switch (option)
		{
		case 1:
		{
			char* str, *str2;
			int s = 25, s2 = 50;
			allocate(str, s);
			allocate(str2, s2);
			cin.ignore();
			cout << "Enter first string: " << endl;
			cin.getline(str,s);
			cout << "Enter second string: " << endl;
			cin.getline(str2, s2);
			StringConcatenate(str, str2);
			cout <<"Concatenated string: "<< str2;
			cout << endl;
			deallocate(str);
			deallocate(str2);

			break;
		}
		case 2:
		{
			int s = 15;
			allocate(str, s);
			cin.ignore();
			cout << "Enter string: ";	
			cin.getline(str, s);
			CompressString(str);
			deallocate(str);
			break;
		}
		case 3:
		{
			int s = 25;
			allocate(str, s);
			cin.ignore();
			cout << "Enter string: ";
			cin.getline(str, s);
			cout << ReverseSentence(str);
			cout << endl;
			deallocate(str);
			break;
		}
		case 4:
		{
			int r, c;
			char** s;
			allocate2D(s, r, c);
			input(s, r);
			pluralWords(s, r);
			cout << endl;
			deallocate2D(s, r);
			break;
		}
		}
		cout << endl;
		cout << "MENU" << endl;
		cout << "Please Enter: " << endl;
		cout << "0 - to exit the program." << endl;
		cout << "1 - to concatenate two strings." << endl;
		cout << "2 - to compress string." << endl;
		cout << "3 - to reverse words in a string." << endl;
		cout << "4 - to view plural of entered words." << endl;
		cin >> option;
	}
}