#include <bits/stdc++.h>
using namespace std;

bool menu_yet = false;
int menu();

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
public:
    int num, den;
    Fraction(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    ~Fraction()
    {
        this->num = 0;
        this->den = 0;
    }
    void input();
    void simplify();
    void standard();
    void output();
    Fraction operator+(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den + p.num * den;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator-(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den - p.num * den;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator*(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.num;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator/(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den;
        ans.den = den * p.num;
        ans.standard();
        return ans;
    }
    bool operator<(Fraction p)
    {
        return (num * p.den < p.num * den);
    }
    bool operator>(Fraction p)
    {
        return (num * p.den > p.num * den);
    }
};

void swap(Fraction &, Fraction &);
Fraction max(Fraction, Fraction);
Fraction max_element(Fraction *, int);

void input(Fraction *, int);
void output(Fraction *, int);

int main()
{
    return 0;
}
void Fraction::input()
{
    cin >> num >> den;
}
void Fraction::simplify()
{
    while (gcd(num, den) != 1)
    {
        int temp = num;
        num /= gcd(num, den);
        den /= gcd(temp, den);
    }
}
void Fraction::standard()
{
    this->simplify();
    if ((num < 0 && den < 0) || (num > 0 && den < 0))
    {
        num = -num;
        den = -den;
    }
}
void Fraction::output()
{
    this->standard();
    if (num == 0)
        cout << 0;
    else if (den == 0)
        cout << num;
    else
        cout << num << "/" << den;
}

void swap(Fraction &p1, Fraction &p2)
{
    Fraction temp = p1;
    p1 = p2;
    p2 = temp;
}

Fraction max(Fraction p1, Fraction p2)
{
    Fraction ans;
    if (p1.num * p2.den > p2.num * p1.den)
    {
        ans.num = p1.num;
        ans.den = p1.den;
    }
    else
    {
        ans.num = p2.num;
        ans.den = p2.den;
    }
    ans.standard();
    return ans;
}
Fraction max_element(Fraction *arr, int n)
{
    Fraction ans = *arr;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, *arr);
        arr++;
    }
    ans.standard();
    return ans;
}

void input(Fraction *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        arr->input();
        arr++;
    }
}
void output(Fraction *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr->output();
        arr++;
        cout << " ";
    }
}