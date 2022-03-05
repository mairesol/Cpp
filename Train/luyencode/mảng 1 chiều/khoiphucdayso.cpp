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
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }
    if (n == 1)
        cout << -1;
    else
    {
        vector<int> c;
        for (int i = 1; i <= n; i++)
        {
            c.clear();
            int b = i;
            c.push_back(b);
            for (auto it = a.begin(); it != a.end(); it++)
            {
                b += *it;
                if (exist(c, b) == false && b > 0 && b <= n)
                    c.push_back(b);
                else
                    break;
            }
            if (c.size() == n)
            {
                for (auto it = c.begin(); it != c.end(); it++)
                {
                    cout << *it << " ";
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}