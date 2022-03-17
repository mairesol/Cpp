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
    friend Fraction max(const Fraction &, const Fraction &);
};

int main()
{
    // Nhap vao hai phan so, tim phan so lon nhat roi xuat ket qua
    Fraction f, f1, f2;
    cout << "Nhap phan so thu nhat: " << endl;
    cin >> f1;
    cout << "Nhap phan so thu hai: " << endl;
    cin >> f2;
    cout << "Phan so lon nhat: ";
    f = max(f1, f2);
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
Fraction max(const Fraction &A, const Fraction &B)
{
    if (A.num * B.den > A.den * B.num)
        return A;
    return B;
}
