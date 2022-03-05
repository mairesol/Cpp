#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string str;
    while (n--)
    {
        str.clear();
        cin >> str;

        int leng = str.size();
        leng = min(5, max(leng - 5, 0));

        bool check_num = false, check_low = false, check_upp = false;

        for (int i = 0; i < str.size(); i++)
        {
            if (check_num + check_low + check_upp == 3)
                break;
            if (isdigit(str[i]) > 0)
                check_num = true;
            if (islower(str[i]) > 0)
                check_low = true;
            if (isupper(str[i]) > 0)
                check_upp = true;
        }

        int diff;
        if (check_num + check_low + check_upp == 1)
            diff = 1;
        else if (check_num + check_low + check_upp == 2)
            diff = 2;
        else
            diff = 5;
        cout << leng + diff << " ";
    }
    return 0;
}
