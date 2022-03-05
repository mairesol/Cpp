#include <bits/stdc++.h>

using namespace std;

bool isArmstrong(int n)
{
    int exponent = log10(n) + 1;
    int sum = 0;
    int temp = n;
    while (n)
    {
        sum += pow(n % 10, exponent);
        n /= 10;
    }
    if (sum == temp)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (isArmstrong(i) == true)
            cout << i << " ";
    }
    return 0;
}