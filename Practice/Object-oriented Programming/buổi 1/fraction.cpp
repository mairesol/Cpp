#include <iostream>

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
private:
    int num, den;

public:
    Fraction(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    ~Fraction()
    {
        this->num = 0;
        this->den = 1;
    }
    void input();
    void simplify();
    void standard();
    void output();
    friend Fraction operator+(Fraction &, Fraction &);
    friend Fraction operator-(Fraction &, Fraction &);
    friend Fraction operator*(Fraction &, Fraction &);
    friend Fraction operator/(Fraction &, Fraction &);
    operator float();
    friend istream &operator>>(istream &, Fraction &);
    friend ostream &operator<<(ostream &, const Fraction &);
    bool operator<(Fraction &);
    bool operator>(Fraction &);
    friend Fraction max(const Fraction &, const Fraction &);
};

void swap(Fraction &, Fraction &);
Fraction max_element(Fraction *, int);

void input(Fraction *, int);
void output(Fraction *, int);

int main()
{
    return 0;
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
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}
Fraction operator+(Fraction &b1, Fraction &b2)
{
    return Fraction(b1.num * b2.den + b2.num * b1.den, b1.den * b2.den);
}
Fraction operator-(Fraction &b1, Fraction &b2)
{
    return Fraction(b1.num * b2.den - b2.num * b1.den, b1.den * b2.den);
}
Fraction operator*(Fraction &b1, Fraction &b2)
{
    return Fraction(b1.num * b2.num, b1.den * b2.den);
}
Fraction operator/(Fraction &b1, Fraction &b2)
{
    return Fraction(b1.num * b2.den, b1.den * b2.num);
}
Fraction::operator float()
{
    return float(num) / float(den);
}
bool Fraction::operator<(Fraction &p)
{
    return (num * p.den < p.num * den);
}
bool Fraction::operator>(Fraction &p)
{
    return (num * p.den > p.num * den);
}
istream &operator>>(istream &is, Fraction &obj)
{
    cout << "Nhap tu so: ";
    is >> obj.num;
    cout << "Nhap mau so: ";
    is >> obj.den;
    return is;
}

ostream &operator<<(ostream &os, const Fraction &obj)
{
    if (obj.num == 0)
        os << 0;
    else if (obj.den == 1)
        os << obj.num;
    else
        os << obj.num << "/" << obj.den;
    return os;
}
void swap(Fraction &p1, Fraction &p2)
{
    Fraction temp = p1;
    p1 = p2;
    p2 = temp;
}

Fraction max(const Fraction &A, const Fraction &B)
{
    if (A.num * B.den > A.den * B.num)
        return A;
    return B;
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