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
    void simplify();
    void standard();
    friend istream &operator>>(istream &, Fraction &);
    friend ostream &operator<<(ostream &, Fraction &);
};

int main()
{
    // Nhap vao phan so, rut gon roi xuat ket qua ra man hinh
    Fraction f;
    cout << "Nhap phan so: " << endl;
    cin >> f;
    cout << f;
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