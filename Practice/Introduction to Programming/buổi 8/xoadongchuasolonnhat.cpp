#include <iostream>
using namespace std;
#define MAX 100

int max(int arr[][MAX], unsigned int m, unsigned int n)
{
    int max = arr[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            max = (arr[i][j] > max) ? arr[i][j] : max;
    return max;
}
void input(int arr[][MAX], unsigned int &m, unsigned int &n)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}
void deleteRow(int arr[][MAX], unsigned int &m, unsigned int n)
{
    int max_element = max(arr, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (arr[i][j] == max_element)
            {
                m--;
                for (int k = i; k < m; k++)
                    for (int l = 0; l < n; l++)
                        arr[k][l] = arr[k + 1][l];
                return;
            }
    }
}
void output(int matrix[][MAX], unsigned int m, unsigned int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[MAX][MAX];
    unsigned int m;
    unsigned int n;

    input(arr, m, n);

    cout << "Mang truoc khi xoa la " << endl;
    output(arr, m, n);

    deleteRow(arr, m, n);

    cout << "Mang sau khi xoa la " << endl;
    output(arr, m, n);

    return 0;
}
