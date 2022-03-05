#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vect;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        vect.push_back(i);
    }

    if (k == 0)
    {
        for (auto it = vect.begin(); it != vect.end(); it++)
        {
            cout << *it << " ";
        }
        return 0;
    }
    if (k > n / 2 || (k != 0 && (n / 2) % k != 0) || n % 2 != 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int cnt = 0;
        for (int i = 0, j = 0; i < n / 2; i++, j++)
        {
            swap(vect[j], vect[j + k]);
            cnt++;
            if (cnt == k)
            {
                j += k;
                cnt = 0;
            }
        }
        for (auto it = vect.begin(); it != vect.end(); it++)
        {
            cout << *it << " ";
        }
    }
    return 0;
}