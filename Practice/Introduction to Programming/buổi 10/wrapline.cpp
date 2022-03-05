#include <iostream>
#include <cstring>
#include <locale>

using namespace std;

const long long N = 100000;

int space_void_from(char A[N], int pos)
{
    for (int i = pos; i <= strlen(A); i++)
        if (A[i] == ' ' || A[i] == 0)
            return i;
    return -1;
}
void insert(char str[N], int x, int pos)
{
    int leng = strlen(str);
    for (int i = leng; i > pos; i--)
        str[i] = str[i - 1];
    str[pos] = x;
}

void print(char a[N], int n)
{
    int pos = -1;
    int cnt = 0;
    int words = 0;
    int x, y;
    while (space_void_from(a, pos + 1) != -1)
    {
        x = pos + 1;
        pos = space_void_from(a, pos + 1);
        y = pos - x + 1;

        words++;
        if (words >= 2) // có 2 từ trên 1 hàng
        {
            if (cnt + y > n) // Từ vượt quá
            {
                if (cnt + y == n + 1) // 1 khoảng trắng vượt quá
                {
                    insert(a, 10, pos);
                    cnt = 1;
                    pos++;
                    words = 1;
                }
                else
                {
                    insert(a, 10, x);
                    cnt = y;
                    pos++;
                    words = 1;
                }
            }
            else
                cnt += y;
        }
        else
            cnt += y;
    }
    cout << a;
}
int main()
{
    char a[N];
    cin.getline(a, N);
    int n;
    cin >> n;
    print(a, n);
}
/*
tuan deptrai qua troi oi la troi !
7

123456 12 1 12
4


I3KJsZzp'i'xvmi23c'H!L2(Zkanc(!'QyVwA7ziks'bq!6f6!FLLyi846XFynBrg"iIibk7r!7OtBXK8%gD3hZhpsyr4k(o95N$hlw%qOQjFYveKwef!OLg$lrMDNvQ77ndk 9C2zr
83
*/