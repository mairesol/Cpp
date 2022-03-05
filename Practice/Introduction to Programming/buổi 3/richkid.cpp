#include <iostream>
using namespace std;

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    long long aohieu, quanhieu, giayhieu, aokhaochieu;
    cin >> aohieu >> quanhieu >> giayhieu >> aokhaochieu;
    long long MIN = min(aohieu, min(quanhieu, min(giayhieu, aokhaochieu)));
    long long MAX = max(aohieu, max(quanhieu, max(giayhieu, aokhaochieu)));
    long long sum = aohieu + quanhieu + giayhieu + aokhaochieu;
    if (sum > 100000000 && MIN >= 5000000 && MAX - MIN <= 20000000)
        cout << "TRUE";
    else
        cout << "FALSE";

    return 0;
}