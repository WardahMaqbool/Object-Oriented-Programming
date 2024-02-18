#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char str[50];
    cout << "Enter string with comma separated words: ";
    cin >> str;
    int l = strlen(str);
    int count = 1;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == ',')
        {
            count++;
        }
    }

    char** list_tokens = new char* [count];
    int j = 0 ,k = 0;
    cout << "Tokens are: ";
    cout << endl;
    for (int x = 0; x < count; x++)
    {
        int count2 = 0;
        if (x == count - 1)
        {
            while (str[j] != '\0')
            {
                count2++;
                j++;
            }
        }
        else
        {
            while (str[j] != ',')
            {
                count2++;
                j++;
            }
        }
        j = j + 1;

        list_tokens[x] = new char[count2];
        for (int i = 0; i < count2; i++)
        {
            list_tokens[x][i] = str[k];
            k++;
            cout << list_tokens[x][i];
        }
        cout << endl;
        k = k + 1;
    }

    for (int i = 0; i < count; i++)
    {
        delete[] list_tokens[i];
    }
    delete[] list_tokens;
    list_tokens = nullptr;

}
