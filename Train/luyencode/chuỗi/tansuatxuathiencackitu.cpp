#include <bits/stdc++.h>

using namespace std;

void lower(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    string str;
    getline(cin, str);

    lower(str);
    set<char> s;

    for (auto it = str.begin(); it != str.end(); it++)
        if (isalnum(*it))
            s.insert(*it);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << char(*it) << " ";

        int cnt = 0;
        for (auto nit = str.begin(); nit != str.end(); nit++)
            if (*nit == *it)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
