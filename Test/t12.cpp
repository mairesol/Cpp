#include <iostream>
#include <windows.h>
using namespace std;

void setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}
int main()
{
    for (int i = 0; i < 16; i++)
    {
        setcolor(i);
        cout << i;
    }
    int a;
    cin >> a;
}
