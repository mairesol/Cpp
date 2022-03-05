#include <iostream>
#include <algorithm>

#define MAXROW 1000
#define MAXCOL 1000

using namespace std;

void input(float matrix[][MAXCOL], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
}
float sum_proper_value(float matrix[][MAXCOL], int n)
{
    float sum = matrix[0][0];
    for (int i = 1; i < n; i++)
        sum += matrix[i][i];
    return sum;
}

void swap_row(float matrix[][MAXCOL], int n, int dest, int source)
{
    for (int i = 0; i < n; i++)
        swap(matrix[dest][i], matrix[source][i]);
}
void trans_row(float matrix[][MAXCOL], int n, int dest, int source, float factor)
{
    for (int i = 0; i < n; i++)
        matrix[dest][i] -= factor * matrix[source][i];
}
void triangular(float matrix[][MAXCOL], int n, int dest, int source)
{
    if (dest < n)
    {
        int start = dest;
        while (start < n && matrix[source][source] == 0)
        {
            swap_row(matrix, n, start, source);
            start++;
        }
        for (int i = dest; i < n; i++)
        {
            if (matrix[source][source] == 0)
                break;
            trans_row(matrix, n, i, source, matrix[i][source] / matrix[source][source]);
        }
        triangular(matrix, n, dest + 1, source + 1);
    }
}
float det(float matrix[][MAXCOL], int n)
{
    int det = matrix[0][0];
    for (int i = 1; i < n; i++)
        det *= matrix[i][i];
    return det;
}
// void output(float matrix[][MAXCOL], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << matrix[i][j] << " ";
//         cout << endl;
//     }
// }

int main()
{
    int n;
    cin >> n;
    float matrix[MAXROW][MAXCOL];
    input(matrix, n);
    cout << sum_proper_value(matrix, n) << endl;
    triangular(matrix, n, 1, 0);
    cout << det(matrix, n);
    return 0;
}

/*
5
1 2 3 1 5
1 2 3 4 5
-2 9 1 3 5
-2 8 1 3 5
-2 9 6 3 5

4
1 2 3 1
1 3 4 5
2 6 7 8
-2 9 1 3

4
1 2 3 4
1 2 3 8
1 2 3 4
1 6 5 12

*/