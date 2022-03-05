#include <bits/stdc++.h>

using namespace std;

int main()
{

    string str;
    cin >> str;

    int ans = str.size() / 2;
    int i = (str.size() + 1) / 2;
    while (i < str.size())
    {
        if (str.substr(0, ans) == str.substr(i, ans))
        {
            cout << ans;
            return 0;
        }
        i++;
        ans--;
    }
    cout << -1;
    return 0;
}
