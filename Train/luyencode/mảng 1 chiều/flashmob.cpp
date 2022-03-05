#include <bits/stdc++.h>

using namespace std;

int main()
{
    int win, n;
    cin >> win >> n;

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    set<int> se;
    se.insert(win);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == win)
        {
            win = a[i];
            se.insert(win);
        }
    }
    cout << win << " " << se.size();
    return 0;
}