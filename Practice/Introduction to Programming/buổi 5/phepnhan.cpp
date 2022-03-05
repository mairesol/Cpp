#include <iostream>
using namespace std;

long long multiply(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (n == 1)
        return m;
    else
        return m + multiply(m, n - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiply(m, n);
}