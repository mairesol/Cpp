#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

void input(ll a[][1000], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}

ll box_blur(ll A[][1000], int a, int b)
{
    return (A[a + 1][b + 1] + A[a + 1][b] + A[a + 1][b - 1] + A[a][b + 1] + A[a][b] + A[a][b - 1] + A[a - 1][b + 1] + A[a - 1][b] + A[a - 1][b - 1]) / 9;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll A[1000][1000];
    input(A, n, m);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
            cout << box_blur(A, i, j) << " ";
        cout << endl;
    }
    return 0;
}
