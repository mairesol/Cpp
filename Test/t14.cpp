#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <Windows.h>

typedef unsigned long long ull;

using namespace std;

int init[2] = {2, 4};
ull board[4][4] = {{8, 16, 0, 2}, {2, 16, 2, 64}, {4, 8, 128, 8}, {8, 2, 32, 2}};

bool isFull(ull board[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                return false;
    }
    return true;
}
bool initiate(ull board[][4])
{
    while (isFull(board) != 1)
    {
        int i = rand() % 4;
        int j = rand() % 4;
        if (board[i][j] == 0)
        {
            board[i][j] = init[rand() % 2];
            break;
        }
    }
}
void output(ull board[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool isGameOver(ull board[][4])
{
    if (isFull(board) == 0)
        return false;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == board[i - 1][j] && i != 0)
                return false;
            if (board[i][j] == board[i + 1][j] && i != 3)
                return false;
            if (board[i][j] == board[i][j - 1] && j != 0)
                return false;
            if (board[i][j] == board[i][j + 1] && j != 3)
                return false;
        }
    return true;
}

int main()
{
    output(board);
    cout << isGameOver(board);
    return 0;
}