#include <iostream>
#include <algorithm>

using namespace std;

void horizontal_invert(int a[][100], int n, int m)
{
    // Đường xiên
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)

            swap(a[i][j], a[n - i - 1][m - j - 1]);
    }
    // Đường dọc
    if (m % 2 != 0)
    {
        int axis = m / 2;
        for (int i = 0; i < n / 2; i++)
            swap(a[i][axis], a[n - i - 1][axis]);
    }
}
void input(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}
void output(int a[][100], int n, int m)
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
    int a[100][100];
    input(a, n, m);
    horizontal_invert(a, n, m);
    output(a, n, m);
    return 0;
}
