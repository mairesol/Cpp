#include <iostream>
#include <algorithm>

int odd_then_min(int a, int b)
{
    if (a % 2 != 0 && b % 2 != 0)
        return ((a < b) ? a : b);
    else if (a % 2 == 0)
        return b;
    else
        return a;
}

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 && b % 2 == 0)
        cout << "NO";
    else
        cout << "YES  " << odd_then_min(a, b) / 2 * 4 + 3;
    return 0;
}