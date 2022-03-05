#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
    friend Complex operator+(Complex const &, Complex const &);
};

Complex operator+(Complex const &c1, Complex const &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

struct PS
{
    int tu, mau;
};

PS operator+(PS p1, PS p2)
{
    PS p;
    p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    p.mau = p1.mau * p2.mau;
    return p;
}
PS operator-(PS p1, PS p2)
{
    PS p;
    p.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    p.mau = p1.mau * p2.mau;
    return p;
}
PS operator*(PS p1, PS p2)
{
    PS p;
    p.tu = p1.tu * p2.tu;
    p.mau = p1.mau * p2.mau;
    return p;
}
PS operator/(PS p1, PS p2)
{
    PS p;
    p.tu = p1.tu * p2.mau;
    p.mau = p1.mau * p2.tu;
    return p;
}

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
    PS f1 = {3, 2}, f2 = {4, 5};
    PS f3 = f1 + f2;
    cout << f3.tu << " / " << f3.mau;
    return 0;
}