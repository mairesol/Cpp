#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void input(char A[][1000], int &n)
{
    n = 0;
    while (true)
    {
        cin >> A[n];
        if (A[n][0] == '.')
            break;
        n++;
    }
}
void convert(char A[][1000], int &n)
{
    for (int i = 0; i < n; i++)
    {
        int index_result = 0;
        for (int j = 0; j < strlen(A[i]); j++)
        {
            int cnt = 1;
            while (A[i][j + 1] == A[i][j])
            {
                cnt++;
                j++;
            }
            if (cnt > 1)
            {
                cout << cnt << A[i][j];
                index_result += 2;
            }
            else
            {
                cout << A[i][j];
                index_result++;
            }
        }
        cout << endl;
    }
}

int main()
{
    char A[1000][1000];
    char result[1000][1000];
    int n;
    input(A, n);
    convert(A, n);
}
