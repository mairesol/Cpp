#include <bits/stdc++.h>
using namespace std;

int chocolateFeast(int n, int c, int m)
{
    int ans = 0;
    int choco = n / c, wrap, remain = 0;
    do
    {
        ans += choco;
        wrap = choco;
        choco = (wrap + remain) / m;
        remain = wrap - choco * m;
    } while (choco != 0);
    return ans;
}

int main()
{
    int n, c, m;
    cin >> n >> c >> m;
    cout << chocolateFeast(n, c, m);
    return 0;
}