#include <bits/stdc++.h>

using namespace std;
void normalize(string &str)
{
    int i = 0;
    while (true)
    {
        int j = str.find(' ', i);
        if (j != -1)
        {
            str[i] = toupper(str[i]);
            i++;
            while (i < j)
            {
                str[i] = tolower(str[i]);
                i++;
            }
        }
        else
        {
            str[i] = toupper(str[i]);
            i++;
            while (i < str.size())
            {
                str[i] = tolower(str[i]);
                i++;
            }
            break;
        }
        i++;
    }
}
int main()
{
    string name = "doAn ANh tUaN";
    normalize(name);
    cout << name;
}