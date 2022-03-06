#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arrs(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int b = 0; b < a; b++)
        {
            int c;
            cin >> c;
            arrs[i].push_back(c);
        }
    }

    for (int s = 0; s < q; s++)
    {
        int i, j;
        cin >> i >> j;
        cout << arrs[i][j] << endl;
    }

    return 0;
}