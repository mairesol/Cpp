#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[10000];
    cin.getline(str, 10000);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cout << char(toupper(str[i]));
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cout << char(tolower(str[i]));
        }
        else
            cout << str[i];
    }
    return 0;
}