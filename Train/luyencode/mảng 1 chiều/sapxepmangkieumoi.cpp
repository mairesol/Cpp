#include <bits/stdc++.h>

using namespace std;

void convert(vector<long long>::iterator it)
{

    if (*it > 0)
    {
        string str(to_string(*it));
        sort(str.rbegin(), str.rend());
        *it = stoll(str);
    }
    else
    {
        string str(to_string(*it));
        string zeros;
        while (str.find('0') != -1)
        {
            str.erase(str.begin() + str.find('0'));
            zeros.append(1, '0');
        }
        sort(str.begin(), str.end());
        str.insert(str.begin() + 2, zeros.begin(), zeros.end());
        *it = stoll(str);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (auto it = a.begin(); it != a.end(); it++)
    {
        convert(it);
    }
    sort(a.rbegin(), a.rend());
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
// 10 -61 -947 -6 -96 -534 -2669 -263 -1449 -77 0