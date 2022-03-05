#include <iostream>
using namespace std;
typedef long long ull;
typedef double d;
int count_x(int a[], int n, int x)
{
    if (n = 0)
        return 0;
    else
        return count_x(a, n - 1, x) + (a[n - 1] == x);
}
int main()
{

    int a[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << count_x(a, n, x);
}