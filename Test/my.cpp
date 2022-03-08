#include <bits/stdc++.h>

using namespace std;

int findDigits(int n)
{
    int ans = 0;
    int r = n;
    while (r != 0)
    {
        if (r % 10 != 0 && n % (r % 10) == 0)
            ans++;
        r /= 10;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        cout << findDigits(a) << endl;
    }
    return 0;
}
