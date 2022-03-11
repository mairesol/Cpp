#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
    friend Complex operator+(Complex const &, Complex const &);
};

Complex operator+(Complex const &c1, Complex const &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
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

    Fraction operator+(const Fraction &b)
    {
        Fraction c;
        c.num = this->num * b.den + this->den * b.num;
        c.den = this->den * b.den;
        return c;
    }

    friend Fraction operator-(const Fraction &a, const Fraction &b)
    {
        Fraction c;
        c.num = a.num * b.den - a.den * b.num;
        c.den = a.den * b.den;
        return c;
    }
    friend istream &operator>>(istream &is, const Fraction &obj)
    {
        cout << "Nhap tu so: ";
        is >> obj.num;
        cout << "Nhap mau so: ";
        is >> obj.den;
        return is;
    }

    friend ostream &operator<<(ostream &os, Fraction &obj)
    {
        if (obj.num == 0)
            os << 0;
        else if (obj.den == 1)
            os << obj.num;
        else
            os << obj.num << "/" << obj.den << endl;
        return os;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();

    Fraction f1 = {3, 2}, f2 = {4, 5};
    Fraction f3 = f1 + f2;
    cout << f3;
    return 0;
}