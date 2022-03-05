#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX 205

using namespace std;

void reverse_word(char str[MAX], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(str[i], str[size - i - 1]);
    }
}

int main()
{
    char str[MAX];
    cin.getline(str, MAX);

    char *ch1 = str;
    char *ch2 = strchr(str, ' ');
    while (true)
    {
        if (ch2 == NULL)
        {
            reverse_word(ch1, strlen(str) - (ch1 - str));
            break;
        }
        else
            reverse_word(ch1, ch2 - ch1);
        ch1 = ch2 + 1;
        ch2 = strchr(ch1, ' ');
    }

    cout << str;
    return 0;
}
