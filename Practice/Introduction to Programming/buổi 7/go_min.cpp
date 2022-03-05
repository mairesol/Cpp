#include <iostream>
#include <algorithm>
using namespace std;
void input(long long matrix[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
}

int mine_count(long long matrix[][100], int itsrow, int itscol)
{
    return (matrix[itsrow + 1][itscol + 1] == 1) + (matrix[itsrow + 1][itscol] == 1) + (matrix[itsrow + 1][itscol - 1] == 1) +
           (matrix[itsrow][itscol + 1] == 1) + (matrix[itsrow][itscol - 1] == 1) +
           (matrix[itsrow - 1][itscol + 1] == 1) + (matrix[itsrow - 1][itscol] == 1) + (matrix[itsrow - 1][itscol - 1] == 1);
}

int main()
{
    int row, col;
    cin >> row >> col;
    long long matrix[100][100];
    input(matrix, row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << mine_count(matrix, i, j) << " ";
        cout << endl;
    }
}