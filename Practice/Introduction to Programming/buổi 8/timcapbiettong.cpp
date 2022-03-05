#include <iostream>
#include <math.h>
#include <algorithm>

#define MAX 10000
using namespace std;

void input(int arr[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int n;
int main()
{
    int n;
    cin >> n;
    int arr[MAX];
    input(arr, n);
    int x;
    cin >> x;

    int a = -1, b = -1;
    int mindiff = x;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            if (abs(arr[i] - arr[j]) < mindiff && arr[i] + arr[j] == x)
            {
                a = arr[i];
                b = arr[j];
                mindiff = abs(arr[i] - arr[j]);
            }
    if (a != -1)
        cout << a << endl
             << b;
    return 0;
}