#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
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
    void simplify();
    void standard();
    friend Fraction operator+(Fraction &, Fraction &);
    friend Fraction operator-(Fraction &, Fraction &);
    friend Fraction operator*(Fraction &, Fraction &);
    friend Fraction operator/(Fraction &, Fraction &);
    friend istream &operator>>(istream &, Fraction &);
    friend ostream &operator<<(ostream &, Fraction &);
};

int main()
{
    // Nhap vao hai phan so, tinh tong, hieu, tich, thuong cua chung roi xuat ket qua
    Fraction f, f1, f2;
    cout << "Nhap phan so thu nhat: " << endl;
    cin >> f1;
    cout << "Nhap phan so thu hai: " << endl;
    cin >> f2;

    cout << "Tong cua 2 phan so: ";
    f = f1 + f2;
    cout << f << endl;
    cout << "Hieu cua 2 phan so: ";
    f = f1 - f2;
    cout << f << endl;
    cout << "Tich cua 2 phan so: ";
    f = f1 * f2;
    cout << f << endl;
    cout << "Thuong cua 2 phan so: ";
    f = f1 / f2;
    cout << f << endl;
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
istream &operator>>(istream &is, Fraction &obj)
{
    cout << "Nhap tu so: ";
    is >> obj.num;
    cout << "Nhap mau so: ";
    is >> obj.den;
    obj.standard();
    return is;
}

ostream &operator<<(ostream &os, Fraction &obj)
{
    obj.standard();
    if (obj.num == 0)
        os << 0;
    else if (obj.den == 1)
        os << obj.num;
    else
        os << obj.num << "/" << obj.den;
    return os;
}
