#include <iostream>
#include <algorithm>
using namespace std;

#define MAXROW 100
#define MAXCOL 100

typedef long long ll;

void helix(ll matrix[][MAXCOL], ll n, ll m)
{
    ll num = 1;
    ll start_row = 0, start_col = 0, end_row = n - 1, end_col = m - 1;
    while (true)
    {
        // Top
        if (start_col > end_col)
            break;
        for (ll i = start_col; i <= end_col; i++)
            matrix[start_row][i] = num++;
        ++start_row;
        // Right
        if (start_row > end_row)
            break;
        for (ll i = start_row; i <= end_row; i++)
            matrix[i][end_col] = num++;
        --end_col;
        // Bot
        if (start_col > end_col)
            break;
        for (ll i = end_col; i >= start_col; i--)
            matrix[end_row][i] = num++;
        --end_row;
        // Left
        if (start_row > end_row)
            break;
        for (ll i = end_row; i >= start_row; i--)
            matrix[i][start_col] = num++;
        ++start_col;
    }
}

void output(ll matrix[][MAXCOL], ll n, ll m)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll matrix[MAXROW][MAXCOL];
    helix(matrix, n, m);
    output(matrix, n, m);
}