#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool isKaprekarNumber(int n)
{
    int64_t sqrt = n * n;
    int length = (log10(sqrt) + 2) / 2;
    int64_t power = 1;
    while (length--)
    {
        power *= 10;
    }
    int64_t lhs = sqrt / power, rhs = sqrt % power;
    cout << lhs << " " << rhs;
    if (lhs + rhs == n)
        return true;
    return false;
}

void kaprekarNumbers(int p, int q)
{
    int cnt = 0;
    for (int i = p; i <= q; i++)
    {
        if (isKaprekarNumber(i))
        {
            cout << i << " ";
            cnt++;
        }
    }
    if (cnt == 0)
        cout << "INVALID RANGE";
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
