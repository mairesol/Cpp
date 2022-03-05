#include <iostream>
using namespace std;
long long divide(int m, int n)
{
    if (m >= n)
        return divide(m - n, n) + 1;
    else
        return 0;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << divide(m, n);
}
