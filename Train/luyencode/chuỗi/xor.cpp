#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    if (str2.size() > str1.size())
        str1.insert(0, str2.size() - str1.size(), '0');
    else
        str2.insert(0, str1.size() - str2.size(), '0');

    string str3;
    for (int i = 0; i < str1.size(); i++)
    {
        str3.append(1, abs(str1[i] - str2[i]) + 48);
    }

    str3.erase(str3.begin(), str3.begin() + str3.find_first_not_of('0'));
    cout << str3;
    return 0;
}
