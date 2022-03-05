#include<iostream>
#include<windows.h>
using namespace std;

void heart()
{
    int i, j;
    int n = 10;
    cout << "\n\n\n\n\n";
    for (i = n / 2; i <= n; i += 2)
    {
        cout << "\t\t\t\t";
        for (j = 1; j < n - i; j += 2)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (i = n; i >= 1; i--)
    {
        cout << "\t\t\t\t";
        for (j = i; j < n; j++)
        {
            cout << " ";
        }

        for (j = 1; j <= (i * 2) - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{
    system("cls");
    for (; ;)
    {
        heart();
        system("Color 0A");
        Sleep(500);
        system("Color 0B");
        Sleep(500);
        system("Color 0C");
        Sleep(500);
        system("Color 0D");
        Sleep(500);
        system("Color 0E");
        Sleep(500);
        system("cls");
    }
    heart();
    return 0;
}