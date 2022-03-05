#include <bits/stdc++.h>

using namespace std;

bool exist(vector<int> vect, int x)
{
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        if (*it == x)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    int pos, height;
    set<int> se;
    set<int> nse;
    for (int i = 0; i < m; i++)
    {
        cin >> pos >> height;
        a[pos - 1] = height;
        se.insert(pos);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (se.find(i + 1) == se.end())
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (se.find(j + 1) == se.end())
                continue;
            if (abs(a[i] - a[j]) > j - i)
            {
                cout << -1;
                return 0;
            }
        }
    }

    while (se.size() < n)
    {
        nse = se;
        for (auto it = se.begin(); it != se.end(); it++)
        {
            if (se.find(*it + 1) == se.end() && *it + 1 <= n)
            {
                a[*it] = a[*it - 1] + 1;
                nse.insert(*it + 1);
            }
            if (se.find(*it - 1) == se.end() && *it - 1 >= 1)
            {
                a[*it - 2] = a[*it - 1] + 1;
                nse.insert(*it - 1);
            }
        }
        se = nse;
    }
    cout << *max_element(a.begin(), a.end());
    return 0;
}