#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
private:
    int num, den;

public:
    Fraction()
    {
        this->num = 0;
        this->den = 1;
    }
    Fraction(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    Fraction(Fraction &A)
    {
        this->num = A.num;
        this->den = A.den;
    }
    bool zero_error()
    {
        if (this->den == 0)
            return 1;
        return 0;
    }
    void reduce();
};