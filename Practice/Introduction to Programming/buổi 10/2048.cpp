#include <iostream>

typedef unsigned long long ull;

using namespace std;

void left(ull matrix[][4])
{
    for (int i = 0; i < 4; i++)
    {
        // Tính toán
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == 0)
                continue;
            for (int k = j + 1; k < 4; k++)
            {
                if (matrix[i][j] != matrix[i][k] && matrix[i][k] != 0)
                    break;
                else if (matrix[i][j] == matrix[i][k])
                {
                    matrix[i][j] *= 2;
                    matrix[i][k] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 0;
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][index] = matrix[i][j];
                if (j != index)
                    matrix[i][j] = 0;
                index++;
            }
        }
    }
}
void right(ull matrix[][4])
{
    for (int i = 3; i >= 0; i--)
    {
        // Tính toán
        for (int j = 3; j >= 0; j--)
        {
            if (matrix[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (matrix[i][j] != matrix[i][k] && matrix[i][k] != 0)
                    break;
                else if (matrix[i][j] == matrix[i][k])
                {
                    matrix[i][j] *= 2;
                    matrix[i][k] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 3;
        for (int j = 3; j >= 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][index] = matrix[i][j];
                if (j != index)
                    matrix[i][j] = 0;
                index--;
            }
        }
    }
}
void up(ull matrix[][4])
{
    for (int j = 0; j < 4; j++)
    {
        // Tính toán
        for (int i = 0; i < 4; i++)
        {
            if (matrix[i][j] == 0)
                continue;
            for (int k = i + 1; k < 4; k++)
            {
                if (matrix[i][j] != matrix[k][j] && matrix[k][j] != 0)
                    break;
                else if (matrix[i][j] == matrix[k][j])
                {
                    matrix[i][j] *= 2;
                    matrix[k][j] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 0;
        for (int i = 0; i < 4; i++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[index][j] = matrix[i][j];
                if (i != index)
                    matrix[i][j] = 0;
                index++;
            }
        }
    }
}

void down(ull matrix[][4])
{
    for (int j = 3; j >= 0; j--)
    {
        // Tính toán
        for (int i = 3; i >= 0; i--)
        {
            if (matrix[i][j] == 0)
                continue;
            for (int k = i - 1; k >= 0; k--)
            {
                if (matrix[i][j] != matrix[k][j] && matrix[k][j] != 0)
                    break;
                else if (matrix[i][j] == matrix[k][j])
                {
                    matrix[i][j] *= 2;
                    matrix[k][j] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 3;
        for (int i = 3; i >= 0; i--)
        {
            if (matrix[i][j] != 0)
            {
                matrix[index][j] = matrix[i][j];
                if (i != index)
                    matrix[i][j] = 0;
                index--;
            }
        }
    }
}

int main()
{
    ull table[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> table[i][j];

    char dir;
    cin >> dir;
    switch (dir)
    {
    case 'L':
        left(table);
        break;
    case 'R':
        right(table);
        break;
    case 'U':
        up(table);
        break;
    case 'D':
        down(table);
        break;
    default:
        break;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }
    return 0;
}
