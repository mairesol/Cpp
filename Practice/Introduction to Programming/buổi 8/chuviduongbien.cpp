#include <iostream>
#include <algorithm>

using namespace std;

void input(int a[][1000], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}
int line(int A[][1000], int a, int b)
{
    return 4 - (A[a][b + 1] == 1) - (A[a][b - 1] == 1) - (A[a + 1][b] == 1) - (A[a - 1][b] == 1);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int A[1000][1000];
    input(A, n, m);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
                sum += line(A, i, j);
        }
    }
    cout << sum;
    return 0;
}
