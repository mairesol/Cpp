#include <bits/stdc++.h>

using namespace std;

bool isPerfect(int n)
{
    if (n <= 1)
        return false;
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
                sum += i + n / i;
            else
                sum += i;
        }
    }
    if (n == sum)
        return true;
    else
        return false;
}

int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
        if (isPerfect(i) == true)
            cout << i << " ";
    return 0;
}