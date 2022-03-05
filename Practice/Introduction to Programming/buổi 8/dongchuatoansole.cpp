#include <iostream>
using namespace std;
#define MAX 100

void input(int arr[][MAX], unsigned int &m, unsigned int &n)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}
void findOddRows(int arr[][MAX], unsigned int m, unsigned int n)
{
    bool odd = 0;
    for (int i = 0; i < m; i++)
    {
        bool flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] % 2 == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            odd = 1;
            cout << i << " ";
        }
    }
    if (odd == 0)
        cout << -1;
}

int main()
{
    int arr[MAX][MAX];
    unsigned int m;
    unsigned int n;

    input(arr, m, n);
    findOddRows(arr, m, n);

    return 0;
}
