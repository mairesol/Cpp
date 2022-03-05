#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int digitOfNumber(int n, int pos)
{
    int quotient = (n / pow(10, pos));
    return quotient % 10;
}

bool isStrobogrammatic(long n)
{
    int digits = log10(n) + 1;
    if (digits % 2 != 0)
        if (digitOfNumber(n, digits / 2) != 0 && digitOfNumber(n, digits / 2) != 8 && digitOfNumber(n, digits / 2) != 1)
            return false;

    for (int i = 0; i < digits / 2; i++)
    {
        int num = digitOfNumber(n, i);
        switch (num)
        {
        case 0:
            if (digitOfNumber(n, digits - i - 1) != 0)
                return false;
            break;
        case 1:
            if (digitOfNumber(n, digits - i - 1) != 1)
                return false;
            break;
        case 6:
            if (digitOfNumber(n, digits - i - 1) != 9)
                return false;
            break;
        case 8:
            if (digitOfNumber(n, digits - i - 1) != 8)
                return false;
            break;
        case 9:
            if (digitOfNumber(n, digits - i - 1) != 6)
                return false;
            break;
        default:
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    for (long i = 0; i < 1000000; i++)
    {
        if (isStrobogrammatic(i) == true && isPrime(i) == true)
            cout << i << " ";
    }
    return 0;
}