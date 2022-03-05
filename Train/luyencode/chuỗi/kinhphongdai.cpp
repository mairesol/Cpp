#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    cin.ignore();

    vector<string> strs(r);
    for (int i = 0; i < strs.size(); i++)
        getline(cin, strs[i]);

    for (int i = 0; i < r; i++)
        for (int j = c - 1; j >= 0; j--)
            strs[i].insert(j, zc - 1, strs[i][j]);

    for (int i = r - 1; i >= 0; i--)
        strs.insert(strs.begin() + i, zr - 1, strs[i]);

    for (int i = 0; i < r * zr; i++)
        cout << strs[i] << endl;
    return 0;
}
