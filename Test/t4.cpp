#include <iostream>
using namespace std;

struct mang_char
{
    char arr[800];
    int n;
};
struct mang2d
{
    mang_char arr[800];
    int n;
};

void xuat_mang2d(mang2d A)
{
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.arr[i].n; j++)
        {
            cout << A.arr[i].arr[j];
        }
        cout << endl;
    }
}
void add_border(char x[][800], int row, int column, mang2d &result)
{
    result.n = row + 2;
    for (int i = 0; i < result.n; i++)
    {
        result.arr[i].n = column + 2;
        result.arr[i].arr[0] = '*';
        result.arr[i].arr[column + 1] = '*';
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            result.arr[i + 1].arr[j + 1] = x[i][j];

    for (int i = 1; i < column + 1; i++)
    {
        result.arr[0].arr[i] = '*';
        result.arr[row + 1].arr[i] = '*';
    }
}

int main()
{
    int row, column;
    cin >> row >> column;

    char x[800][800];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cin >> x[i][j];
    }

    mang2d result;
    add_border(x, row, column, result);
    xuat_mang2d(result);
}
