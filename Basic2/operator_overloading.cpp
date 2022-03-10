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
    friend Complex operator+(Complex const &, Complex const &);
    friend istream &operator>>(istream &, Complex const &);
    friend ostream &operator<<(ostream &, Complex const &);
};
Complex operator+(Complex const &c1, Complex const &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
istream &operator>>(istream &is, Complex const &obj)
{
    cout << "Enter real number: ";
    is >> obj.real;
    cout << "Enter imaginary number: ";
    is >> obj.imag;
    return is;
}

ostream &operator<<(ostream &os, Complex const &obj)
{
    if (obj.real == 0)
        os << obj.imag << "i" << endl;
    else if (obj.imag == 0)
        os << obj.real << endl;
    else
        os << obj.real << " + " << obj.imag << "i" << endl;
    return os;
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
    friend istream &operator>>(istream &is, Fraction &obj)
    {
        cout << "Enter numerator: ";
        is >> obj.num;
        cout << "Enter donoinator: ";
        is >> obj.den;
        return is;
    }
    friend ostream &operator<<(ostream &os, Fraction &obj)
    {
        if (obj.num == 0)
            os << 0 << endl;
        else if (obj.den == 1)
            os << obj.num << endl;
        else
            os << obj.num << "/" << obj.den << endl;
        return os;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    cout << c3;

    Fraction f1 = {3, 2}, f2 = {4, 5};
    Fraction f3 = f1 + f2;
    cout << f3;
    return 0;
}