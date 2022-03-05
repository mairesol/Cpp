#include <iostream>
#include <math.h>
#include <stdlib.h>  /* srand, rand */
#include <conio.h>   /*getch */
#include <time.h>    /* time */
#include <windows.h> /*system, Sleep */
#include <string>

typedef long long ll;

using namespace std;

struct SCORE
{
    char name[256];
    ll number;
    int second;
    int minute;
    int hour;
    int date;
    int month;
    int year;
};

int init[2] = {2, 512};
ll board[4][4];
SCORE score;
SCORE table[10];
bool winyet;
string url = "start https://www.youtube.com/watch?v=dQw4w9WgXcQ";

// Game
void newgame(ll board[][4]);
int blank_tile(ll board[][4]);
void initiate(ll board[][4]);
ll left(ll board[][4]);
ll right(ll board[][4]);
ll up(ll board[][4]);
ll down(ll board[][4]);
bool isGameOver(ll board[][4]);
bool isWin(ll board[][4]);
void insert(SCORE table[10], SCORE score);
void ShowHighScore(SCORE table[10]);

// Function
void copy(ll cop[][4], ll board[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cop[i][j] = board[i][j];
}
bool isSame(ll board[][4], ll cop[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (cop[i][j] != board[i][j])
                return false;
    return true;
}

// Output
void setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}
void setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor)
{
    int color = 16 * BackGroundColor + ForeGroundColor;
    setcolor(color);
}
void loading()
{
    setcolor(1);
    cout << "Loading";
    Sleep(2000);
}
void invalid()
{
    setcolor(4);
    cout << "Please press again!" << endl;
}
void output(ll board[][4]);
void heart();

int main()
{
menu_brand:
    system("cls");
    // Gioi thieu
    setcolor(2);
    cout << "- - - - Welcome to 2048 - - - -" << endl;
    cout << "- - Game was made by ghiten963 - -" << endl;
    // Huong dan
    setcolor(6);
    cout << "- - - - - - - - - - - - - - - - - -" << endl;
    cout << "Use:" << endl;
    cout << "   A/: Left" << endl;
    cout << "   D: Right" << endl;
    cout << "   W: Up" << endl;
    cout << "   S: Down" << endl;
    cout << "   N: New game" << endl;
    cout << "   Esc: Back to menu game" << endl;
    cout << "   X: Exit game" << endl;
    cout << "- - - - - - - - - - - - - - - - - -" << endl;
    setcolor(5);
    cout << "If you have read game guide, just press ENTER to play" << endl;
    while (true)
    {
        char ch = getch();
        switch (ch)
        {
        case 'X':
        case 'x':
            goto endgame_brand;
            break;
        case 13:
            loading();
            goto newgame_brand;
            break;
        }
    }

    // Bat dau game
    // ull board[4][4] = {{2, 2, 0, 0}, {2, 0, 2, 2}, {2, 2, 2, 2}, {2, 0, 0, 2}};

newgame_brand:
    srand(time(NULL));
    newgame(board);
    ll cop[4][4];

    score.number = 0;
    winyet = 0;
    // Choi game
    while (true)
    {
        srand(time(NULL));
        initiate(board);

    continuegame_brand:
        system("cls");
        output(board);

        setcolor(3);
        cout << "Score: ";
        if (score.number <= 4)
            setcolor(1);
        else
            setcolor(int(log2(score.number)) / 2);
        cout << score.number << endl;

        // Neu thua thi hoi choi lai hay khong
        if (isGameOver(board) == true)
        {
            setcolor(6);
            cout << "You lose, wanna play again? - y/n" << endl;

            char answer;
            while (true)
            {
                answer = getch();
                switch (answer)
                {
                case 'Y':
                case 'y':
                    goto newgame_brand;
                    break;
                case 'N':
                case 'n':
                    Sleep(500);
                    setcolor(5);
                    cout << "Try better next time." << endl;
                    Sleep(2000);
                    loading();
                    goto menu_brand;
                    break;
                default:
                    invalid();
                }
            }
        }
        // Neu thang thi hoi choi tiep hay khong
        if (winyet == false && isWin(board) == true)
        {
            system(url.c_str());
            setcolor(6);
            cout << "Roll baby. You win, wanna continue? - y/n" << endl;

            char answer;
            while (true)
            {
                answer = getch();
                switch (answer)
                {
                case 'Y':
                case 'y':
                    winyet = true;
                    goto continuegame_brand;
                    break;
                case 'N':
                case 'n':
                    Sleep(500);
                    setcolor(5);
                    cout << "So you're satisfied with this score. HOPE you create 2048 tile AGAIN with new high scores, see yaa!" << endl;
                    Sleep(2000);
                    loading();
                    goto menu_brand;
                    break;
                default:
                    invalid();
                }
            }
        }

        char dir;
        while (true)
        {
            copy(cop, board);
            dir = getch();
            switch (dir)
            {
            case 'A':
            case 'a':
                score.number += left(board);
                break;
            case 'D':
            case 'd':
                score.number += right(board);
                break;
            case 'W':
            case 'w':
                score.number += up(board);
                break;
            case 'S':
            case 's':
                score.number += down(board);
                break;
            case 'N':
            case 'n':
                goto newgame_brand;
                break;
            case 'X':
            case 'x':
                goto endgame_brand;
                break;
            case 27:
                goto menu_brand;
                break;
            default:
                invalid();
            }
            if (isSame(board, cop) == false)
                break;
        }
    }

endgame_brand:
    system("cls");
    Sleep(500);
    setcolor(2);
    cout << "- - - - - - GAME END - - - - - -" << endl;
    Sleep(1500);
    cout << "- - - THANKS FOR PLAYING ^__^ - " << endl;
    Sleep(2000);
    // system("cls");
    // heart();
    // for (int i = 0; i < 2; i++)
    // {
    //     Sleep(400);
    //     system("Color 0B");
    //     Sleep(400);
    //     system("Color 0C");
    //     Sleep(400);
    //     system("Color 0D");
    //     Sleep(400);
    //     system("Color 0E");
    //     Sleep(400);
    // }
    system("Color 07");
    return 0;
}

int blank_tile(ll board[][4])
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                cnt++;
    return cnt;
}

void initiate(ll board[][4])
{
    // int tiles = rand() % 2;
    while (blank_tile(board) != 0)
    {
        int i = rand() % 4;
        int j = rand() % 4;
        if (board[i][j] == 0)
        {
            board[i][j] = init[0];
            return;
        }
    }
}
void newgame(ll board[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;
    initiate(board);
}

ll left(ll board[][4])
{
    ll point = 0;
    for (int i = 0; i < 4; i++)
    {
        // Tính toán
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < 4; k++)
            {
                if (board[i][j] != board[i][k] && board[i][k] != 0)
                    break;
                else if (board[i][j] == board[i][k])
                {
                    board[i][j] *= 2;
                    point += board[i][j];
                    board[i][k] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 0;
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                board[i][index] = board[i][j];
                if (j != index)
                    board[i][j] = 0;
                index++;
            }
        }
    }
    return point;
}
ll right(ll board[][4])
{
    ll point = 0;
    for (int i = 3; i >= 0; i--)
    {
        // Tính toán
        for (int j = 3; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[i][j] != board[i][k] && board[i][k] != 0)
                    break;
                else if (board[i][j] == board[i][k])
                {
                    board[i][j] *= 2;
                    point += board[i][j];
                    board[i][k] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 3;
        for (int j = 3; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                board[i][index] = board[i][j];
                if (j != index)
                    board[i][j] = 0;
                index--;
            }
        }
    }
    return point;
}
ll up(ll board[][4])
{
    ll point = 0;
    for (int j = 0; j < 4; j++)
    {
        // Tính toán
        for (int i = 0; i < 4; i++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = i + 1; k < 4; k++)
            {
                if (board[i][j] != board[k][j] && board[k][j] != 0)
                    break;
                else if (board[i][j] == board[k][j])
                {
                    board[i][j] *= 2;
                    point += board[i][j];
                    board[k][j] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 0;
        for (int i = 0; i < 4; i++)
        {
            if (board[i][j] != 0)
            {
                board[index][j] = board[i][j];
                if (i != index)
                    board[i][j] = 0;
                index++;
            }
        }
    }
    return point;
}
ll down(ll board[][4])
{
    ll point = 0;
    for (int j = 3; j >= 0; j--)
    {
        // Tính toán
        for (int i = 3; i >= 0; i--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = i - 1; k >= 0; k--)
            {
                if (board[i][j] != board[k][j] && board[k][j] != 0)
                    break;
                else if (board[i][j] == board[k][j])
                {
                    board[i][j] *= 2;
                    point += board[i][j];
                    board[k][j] = 0;
                    break;
                }
            }
        }
        // Di chuyển
        int index = 3;
        for (int i = 3; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                board[index][j] = board[i][j];
                if (i != index)
                    board[i][j] = 0;
                index--;
            }
        }
    }
    return point;
}
bool isGameOver(ll board[][4])
{
    if (blank_tile(board) != 0)
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
bool isWin(ll board[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 2048)
                return true;
    return false;
}

// void ShowHighScore(SCORE table[10])
// {
//     for (int i = 0; i < 10; i++)
//     {
//         cout << i + 1 << ".  ";
//         cout << table[i].number << "\t";
//         cout << table[i].hour << ":" << table[i].minute << ":" << table[i].second << "\t";
//         cout << table[i].month << "/" << table[i].date << "/" << table[i].year << endl;
//     }
// }

int index(ll n)
{
    if (n >= 0 && n <= 9)
        return 0;
    else
        return (index(n / 10) + 1);
}
int max_index_in_col(ll board[][4], int itscol)
{
    int maxindex = 0;
    for (int i = 0; i < 4; i++)
    {
        maxindex = (index(board[i][itscol]) > maxindex) ? index(board[i][itscol]) : maxindex;
    }
    return maxindex;
}

void output(ll board[][4])
{
    // Tạo mảng chứa các độ rộng của cột
    int width_cols[100];
    for (int j = 0; j < 4; j++)
        width_cols[j] = max_index_in_col(board, j);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // Them khoang trang truoc
            int diff = width_cols[j] - index(board[i][j]);
            for (int k = 0; k < diff / 2; k++)
                cout << " ";

            if (board[i][j] == 0)
                setcolor(7);
            else if (log2(board[i][j]) < 7)
                setcolor(log2(board[i][j]));
            else
                setcolor(log2(board[i][j]) + 2);
            cout << board[i][j];

            // Them khoang trang sau
            for (int k = 0; k <= diff / 2 + (diff % 2 != 0) + 2; k++)
                cout << " ";
        }
        cout << endl;
        cout << endl;
    }
    setcolor(7);
}

void heart()
{
    int i, j;
    int n = 10;
    cout << "\n\n\n";
    for (i = n / 2; i <= n; i += 2)
    {
        cout << "  ";
        for (j = 1; j < n - i; j += 2)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << "*";
        for (j = 1; j <= n - i; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    for (i = n; i >= 1; i--)
    {
        cout << "  ";
        for (j = i; j < n; j++)
            cout << " ";
        for (j = 1; j <= (i * 2) - 1; j++)
            cout << "*";
        cout << endl;
    }
}

/*
Color      Background    Foreground
---------------------------------------------
Black            0           0
Blue             1           1
Green            2           2
Cyan             3           3
Red              4           4
Magenta          5           5
Brown            6           6
White            7           7
Gray             -           8
Intense Blue     -           9
Intense Green    -           10
Intense Cyan     -           11
Intense Red      -           12
Intense Magenta  -           13
Yellow           -           14
Intense White    -           15
*/

/*
Bảng kỉ lục
Chỉnh bố cục giữa center
comfirm to exit
make color function
*/
