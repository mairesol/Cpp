#include <bits/stdc++.h>

using namespace std;

int main()
{

    string str;
    cin >> str;

    vector<string> ans;
    sort(str.begin(), str.end());

    do
    {
        ans.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << endl;
    return 0;
}
