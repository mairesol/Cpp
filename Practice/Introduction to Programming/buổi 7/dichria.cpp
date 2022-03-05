#include <iostream>
#include <algorithm>
using namespace std;
void input(int matrix[][1000], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
}
void bot_to_top(int matrix[][1000], int toprow, int botrow, int itscol)
{
    for (int i = botrow; i > toprow; i--)
        swap(matrix[i][itscol], matrix[i - 1][itscol]);
}
void left_to_right(int matrix[][1000], int itsrow, int leftcol, int rightcol)
{
    for (int i = leftcol; i < rightcol; i++)
        swap(matrix[itsrow][i], matrix[itsrow][i + 1]);
}
void top_to_bot(int matrix[][1000], int toprow, int botrow, int itscol)
{
    for (int i = toprow; i < botrow; i++)
        swap(matrix[i][itscol], matrix[i + 1][itscol]);
}
void right_to_left(int matrix[][1000], int itsrow, int leftcol, int rightcol)
{
    for (int i = rightcol; i > leftcol; i--)
        swap(matrix[itsrow][i], matrix[itsrow][i - 1]);
}
void move_clockwise_border(int matrix[][1000], int toprow, int botrow, int leftcol, int rightcol)
{
    top_to_bot(matrix, toprow, botrow, leftcol);
    left_to_right(matrix, botrow, leftcol, rightcol);
    bot_to_top(matrix, toprow, botrow, rightcol);
    right_to_left(matrix, toprow, leftcol, rightcol);
    swap(matrix[toprow][leftcol], matrix[toprow][leftcol + 1]);
}
void move_anticlockwise_border(int matrix[][1000], int toprow, int botrow, int leftcol, int rightcol)
{
    left_to_right(matrix, toprow, leftcol, rightcol);
    top_to_bot(matrix, toprow, botrow, rightcol);
    right_to_left(matrix, botrow, leftcol, rightcol);
    bot_to_top(matrix, toprow, botrow, leftcol);
    swap(matrix[toprow][leftcol], matrix[toprow + 1][leftcol]);
}
void output(int matrix[][1000], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{

    int row, col;
    cin >> row >> col;
    int matrix[1000][1000];
    input(matrix, row, col);

    // Dịch rìa
    int row_index = row - 1;
    int col_index = col - 1;
    int Min = min(row, col);
    int covers = 0;
    if (Min % 2 == 0)
        covers = Min / 2;
    else
        covers = Min / 2 + 1;
    for (int i = 0; i < covers; i++)
    {
        if (i != row_index && i != col_index) // Rìa là viền
        {
            if (i % 2 == 0)
                move_clockwise_border(matrix, i, row_index, i, col_index);
            else
                move_anticlockwise_border(matrix, i, row_index, i, col_index);
        }
        else // Rìa là đuòng hay tâm
        {
            if (i == row_index && i != col_index) //  Đường nằm ngang
            {
                if (i % 2 == 0)
                    right_to_left(matrix, i, i, col_index);
                else
                    left_to_right(matrix, i, i, col_index);
            }
            if (i == col_index && i != row_index) //  Đường nằm dọc
            {
                if (i % 2 == 0)
                    bot_to_top(matrix, i, row_index, i);
                else
                    top_to_bot(matrix, i, row_index, i);
            }
            if (i == col_index && i == row_index) // Tâm
            {
                break;
            }
        }
        row_index--;
        col_index--;
    }
    output(matrix, row, col);
}