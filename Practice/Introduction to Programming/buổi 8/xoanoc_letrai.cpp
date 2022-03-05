#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void helix(ll matrix[][100], ll n)
{
    ll num = 1;
    ll start_row = 0, start_col = 0, end_row = n - 1, end_col = n - 1;
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

void output(ll matrix[][100], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int index(int n)
{
    if (n >= -9 && n <= -1)
        return 1;
    else if (n >= 0 && n <= 9)
        return 0;
    else
        return (index(n / 10) + 1);
}

int max_index_in_col(ll matrix[][100], ll row, ll itscol)
{
    int maxindex = 0;
    for (int i = 0; i < row; i++)
    {
        maxindex = (index(matrix[i][itscol]) > maxindex) ? index(matrix[i][itscol]) : maxindex;
    }
    return maxindex;
}

int main()
{
    ll n;
    cin >> n;
    ll matrix[100][100];
    helix(matrix, n);

    // Tạo mảng chứa các độ rộng của cột
    int width_cols[10000];
    for (int i = 0; i < n; i++)
        width_cols[i] = max_index_in_col(matrix, n, i);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
            for (int k = 1; k <= width_cols[j] - index(matrix[i][j]); k++)
                cout << " ";
        }
        cout << endl;
    }
}