#include <iostream>
#include <cstring>
using namespace std;

int max_length(char str[][1000], int row)
{
    int max = 0;
    for (int i = 0; i <= row; i++)
        max = (strlen(str[i]) > max) ? strlen(str[i]) : max;
    return max;
}
void middle(char str[][1000], int itsrow, int maxlength)
{
    int length = strlen(str[itsrow]);
    int diff = maxlength - length;
    for (int i = length - 1; i >= 0; i--)
    {
        str[itsrow][i + diff] = str[itsrow][i]; // Cac ki tu ve ben phai
    }
    for (int i = 0; i < diff; i++)
        str[itsrow][i] = ' '; // Them cac khoang trang
}
void input(char A[][1000], int &n)
{
    n = 0;
    while (true)
    {
        cin >> A[n];
        if (A[n][0] == '.')
            break;
        n++;
    }
}
void output(char A[][1000], int &n)
{
    // Tim chuoi dai nhat
    int maxlength = max_length(A, n);
    // Chuyen ve ben phai
    for (int i = 0; i < n; i++)
    {
        middle(A, i, maxlength);
    }
    // Xuat ket qua
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

int main()
{
    char A[1000][1000];
    int n;
    input(A, n);
    output(A, n);
}