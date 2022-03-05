#include <iostream>
#include <math.h>
#include <algorithm>

#define MAXROW 100
#define MAXCOL 100

using namespace std;

void input(int matrix[][MAXCOL], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
}

void light(int matrix[][MAXCOL], int row, int col, int i, int j)
{

    if (matrix[i - 1][j + 1] == 0)
        matrix[i - 1][j + 1] = 2;

    if (matrix[i - 1][j] == 0)
        matrix[i - 1][j] = 2;

    if (matrix[i - 1][j - 1] == 0)
        matrix[i - 1][j - 1] = 2;

    if (matrix[i][j + 1] == 0)
        matrix[i][j + 1] = 2;

    matrix[i][j] = 2;

    if (matrix[i][j - 1] == 0)
        matrix[i][j - 1] = 2;

    if (matrix[i + 1][j + 1] == 0)
        matrix[i + 1][j + 1] = 2;

    if (matrix[i + 1][j] == 0)
        matrix[i + 1][j] = 2;

    if (matrix[i + 1][j - 1] == 0)
        matrix[i + 1][j - 1] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int matrix[MAXROW][MAXCOL];
    input(matrix, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 1)
                light(matrix, n, m, i, j);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 2)
                cnt++;
    }
    cout << cnt;
    return 0;
}