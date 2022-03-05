#include <iostream>
#include <algorithm>

#define MAXROW 1000
#define MAXCOL 1000

using namespace std;

void horizontal_invert(int a[][MAXCOL], int n, int m)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m; j++)

            swap(a[i][j], a[n - i - 1][j]);
    }
}
void input(int a[][MAXCOL], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}
void output(int a[][MAXCOL], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[MAXROW][MAXCOL];
    input(a, n, m);
    horizontal_invert(a, n, m);
    output(a, n, m);
    return 0;
}
