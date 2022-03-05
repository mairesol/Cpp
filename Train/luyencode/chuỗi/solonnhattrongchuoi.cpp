#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    string num = "0123456789";
    int pos = str.find_first_of(num, 0);
    if (pos == -1)
        return 0;
    long long ans = 0;
    while (pos != -1)
    {
        int temp = str.find_first_not_of(num, pos + 1);
        if (temp == -1)
        {
            ans = max(ans, stoll(str.substr(pos, str.size() - pos)));
            break;
        }
        ans = max(ans, stoll(str.substr(pos, temp - pos)));
        pos = str.find_first_of(num, temp + 1);
    }
    cout << ans;
    return 0;
}
