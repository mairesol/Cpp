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
    friend istream &operator>>(istream &is, Complex &obj)
    {
        cout << "Nhap so thuc: ";
        is >> obj.real;
        cout << "Nhap so ao: ";
        is >> obj.imag;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Complex &obj)
    {
        if (obj.real == 0)
            os << obj.imag << "i";
        else if (obj.imag == 0)
            os << obj.real;
        else
            os << obj.real << " + " << obj.imag << "i";
        return os;
    }
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
    operator float() const
    {
        return float(num) / float(den);
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
        cout << "Nhap tu so: ";
        is >> obj.num;
        cout << "Nhap mau so: ";
        is >> obj.den;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Fraction &obj)
    {
        if (obj.num == 0)
            os << 0;
        else if (obj.den == 1)
            os << obj.num;
        else
            os << obj.num << "/" << obj.den;
        return os;
    }
};

class Time
{
private:
    int hour;
    int minute;

public:
    Time(int hour = 0, int minute = 0)
    {
        this->hour = hour;
        this->minute = minute;
    }
    ~Time()
    {
        this->hour = 0;
        this->minute = 0;
    }
    friend istream &operator>>(istream &is, Time &obj)
    {
        cout << "Nhap gio: ";
        is >> obj.hour;
        cout << "Nhap phut: ";
        is >> obj.minute;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Time &obj)
    {
        os << obj.hour << ":" << obj.minute;
        return os;
    }

    Time operator++()
    {
        ++minute;
        if (minute >= 60)
        {
            ++hour;
            minute -= 60;
        }
        return Time(hour, minute);
    }

    Time operator++(int)
    {
        Time T(hour, minute);

        minute++;
        if (minute >= 60)
        {
            hour++;
            minute -= 60;
        }
        return T;
    }
};
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    cout << c3 << endl;

    Fraction f1 = {3, 2}, f2 = {4, 5};
    Fraction f3 = f1 + f2;
    cout << f3 << endl;

    Time t1(19, 30);
    cout << t1++ << " " << ++t1;
    return 0;
}