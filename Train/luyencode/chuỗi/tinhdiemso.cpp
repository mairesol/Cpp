#include <bits/stdc++.h>

using namespace std;

long long sum(long long N)
{
    return N * (N + 1) / 2;
}

int main()
{
    string str;
    cin >> str;

    int pos = str.find('N');
    if (pos == -1)
    {
        cout << sum(str.size());
        return 0;
    }

    long long ans = sum(pos);
    while (pos != -1)
    {
        int temp = str.find('N', pos + 1);
        if (temp == -1)
        {
            ans += sum(str.size() - pos - 1);
            break;
        }
        ans += sum(temp - pos - 1);
        pos = temp;
    }
    cout << ans;
    return 0;
}
