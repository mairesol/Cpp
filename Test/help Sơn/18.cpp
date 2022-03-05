#include <bits/stdc++.h>

using namespace std;

void shapeA(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}
void shapeC(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j > n - i; j--)
            cout << i;
        cout << endl;
    }
}
void shapeE(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;

    // Chon A, C, E
    char type;
    cin >> type;
    switch (type)
    {
    case 'A':
    case 'a':
        shapeA(n);
        break;
    case 'C':
    case 'c':
        shapeC(n);
        break;
    case 'E':
    case 'e':
        shapeE(n);
        break;
    default:
        break;
    }
    return 0;
}