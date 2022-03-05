#include <iostream>

#define MAXROW 1000
#define MAXCOL 1000

using namespace std;

void input(char A[][MAXCOL], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> A[i][j];
}
void turn_black(char A[][MAXCOL], int a, int b)
{
    A[a][b] = 0;
    if (A[a][b + 1] == '-')
        turn_black(A, a, b + 1);

    if (A[a][b - 1] == '-')
        turn_black(A, a, b - 1);

    if (A[a + 1][b] == '-')
        turn_black(A, a + 1, b);

    if (A[a - 1][b] == '-')
        turn_black(A, a - 1, b);
}

int main()
{

    char A[MAXROW][MAXCOL];
    int row, col;
    int pic = 1;
    while (cin >> row >> col)
    {
        input(A, row, col);
        int cnt = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (A[i][j] == '-')
                {
                    cnt++;
                    turn_black(A, i, j);
                }
        cout << "Case " << pic << ": " << cnt << endl;
        pic++;
    }
}
