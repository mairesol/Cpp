#include <iostream>
#include <math.h>
using namespace std;
int index(int n)
{
    if (n >= -9 && n <= -1)
        return 1;
    else if (n >= 0 && n <= 9)
        return 0;
    else
        return (index(n / 10) + 1);
}
void input(int a[][1000], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> a[i][j];
}
int max_index_in_col(int matrix[][1000], int row, int itscol)
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
    int matrix[1000][1000];
    int row, col;
    cin >> row >> col;
    input(matrix, row, col);

    // Tạo mảng chứa các độ rộng của cột
    int width_cols[1000];
    for (int i = 0; i < col; i++)
        width_cols[i] = max_index_in_col(matrix, row, i);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 1; k <= width_cols[j] - index(matrix[i][j]); k++)
            {
                cout << " ";
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
