#include <bits/stdc++.h>

using namespace std;

int digitOfNumber(int n, int pos)
{
    int quotient = (n / pow(10, pos));
    return quotient % 10;
}

bool isPalindromic(long n)
{
    int digits = log10(n) + 1;

    for (int i = 0; i < digits / 2; i++)
    {
        if (digitOfNumber(n, i) != digitOfNumber(n, digits - i - 1))
            return false;
    }
    return true;
}

int main()
{
    for (long i = 0; i < 100000; i++)
    {
        if (isPalindromic(i) == true)
            cout << i << " ";
    }
    return 0;
}