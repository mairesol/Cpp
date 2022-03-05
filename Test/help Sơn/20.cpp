#include <bits/stdc++.h>

using namespace std;

void menu()
{
    cout << "       CHUONG TRINH TINH TONG VA TICH" << endl;
    cout << "0.- Nhap n" << endl;
    cout << "1.- Tinh S= 1 + 2 + 3 + . . . + n" << endl;
    cout << "2.- Tinh S= 1 + 3 + 5 + . . . + (2*n+1)" << endl;
    cout << "3.- Tinh S= 1 + 1/2 + 1/3 + . . . + 1/n" << endl;
    cout << "4.- Tinh S= 1/2 + 1/3 + 1/4 + . . . + 1/(n+1)" << endl;
    cout << "5.- Tinh S=  1 * 2 * 3 * . . . * n" << endl;
    cout << "6.- Tinh S= 1 * 3 * 5 * . . . * (2*n+1)" << endl;
    cout << "7.- Tinh S= P= 1 * 1/2 * 1/3 * . . . * 1/n" << endl;
    cout << "8.- Tinh S= 1/2 * 1/3 * 1/4 * . . . * 1/(n+1)" << endl;
    cout << "9.- Ket thuc chuong trinh." << endl;
}

int mode1(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += i;
    return s;
}
int mode2(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s += 2 * i + 1;
    return s;
}
float mode3(int n)
{
    float s = 0;
    for (int i = 1; i <= n; i++)
        s += 1.0 / (float)i;
    return s;
}
float mode4(int n)
{
    float s = 0;
    for (int i = 1; i <= n; i++)
        s += 1.0 / (float)(i + 1);
    return s;
}
long long mode5(int n)
{
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
long long mode6(int n)
{
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= 2 * i + 1;
    return s;
}
float mode7(int n)
{
    return 1.0 / float(mode5(n));
}
float mode8(int n)
{
    return 1.0 / float(mode5(n + 1));
}
int main()
{
    int choose;
    int n;
    menu();
    while (true)
    {
        cout << "    Ban chon (0-9): ";
        cin >> choose;
        if (choose > 0 && choose < 9)
            cout << "Ket qua: ";
        switch (choose)
        {
        case 0:
            cout << "Nhap n: ";
            cin >> n;
            break;
        case 1:
            cout << mode1(n) << endl;
            break;
        case 2:
            cout << mode2(n) << endl;
            break;
        case 3:
            cout << mode3(n) << endl;
            break;
        case 4:
            cout << mode4(n) << endl;
            break;
        case 5:
            cout << mode5(n) << endl;
            break;
        case 6:
            cout << mode6(n) << endl;
            break;
        case 7:
            cout << mode7(n) << endl;
            break;
        case 8:
            cout << mode8(n) << endl;
            break;
        case 9:
            return 0;
            break;

        default:
            break;
        }
    }
    return 0;
}