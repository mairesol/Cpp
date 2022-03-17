#include <iostream>

using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double real = 0, double imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }
    ~Complex()
    {
        this->real = 0;
        this->imag = 0;
    }
    Complex operator-();
    void operator=(Complex &);
    void operator+=(Complex &);
    void operator-=(Complex &);
    friend Complex operator+(Complex &, Complex &);
    friend Complex operator-(Complex &, Complex &);
    friend Complex operator*(Complex &, Complex &);
    friend Complex operator/(Complex &, Complex &);
    friend istream &operator>>(istream &is, Complex &);
    friend ostream &operator<<(ostream &os, const Complex &);
};

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

    friend Fraction operator+(Fraction &, Fraction &);
    friend Fraction operator-(Fraction &, Fraction &);
    friend Fraction operator*(Fraction &, Fraction &);
    friend Fraction operator/(Fraction &, Fraction &);
    operator float();
    friend istream &operator>>(istream &, Fraction &);
    friend ostream &operator<<(ostream &, const Fraction &);
    bool operator<(Fraction &);
    bool operator>(Fraction &);
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
    Time operator++();
    Time operator++(int);
    friend istream &operator>>(istream &, Time &);
    friend ostream &operator<<(ostream &, const Time &);
};

class Array
{
private:
    int *array;
    int size;

public:
    Array(int size = 0, int element = 0)
    {
        this->size = size;
        array = new int[size]{element};
    }
    Array(int *array = NULL)
    {
        this->array = array;
    }
    ~Array()
    {
        delete[] array;
        array = NULL;
    }
    int &operator[](const int index)
    {
        if (index >= size || index < 0)
            return array[size];
        else
            return array[index];
    }
    Array operator()(int *array)
    {
        return Array(array);
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
Complex Complex::operator-()
{
    return Complex(-real, -imag);
};
void Complex::operator=(Complex &c)
{
    this->real = c.real;
    this->imag = c.imag;
}
void Complex::operator+=(Complex &c)
{
    this->real += c.real;
    this->imag += c.imag;
}
void Complex::operator-=(Complex &c)
{
    this->real -= c.real;
    this->imag -= c.imag;
}
Complex operator+(Complex &c1, Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator-(Complex &c1, Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator*(Complex &c1, Complex &c2)
{
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}
Complex operator/(Complex &c1, Complex &c2)
{
    return Complex((c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag), (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag));
}

istream &operator>>(istream &is, Complex &obj)
{
    cout << "Nhap so thuc: ";
    is >> obj.real;
    cout << "Nhap so ao: ";
    is >> obj.imag;
    return is;
}
ostream &operator<<(ostream &os, const Complex &obj)
{
    if (obj.real == 0)
        os << obj.imag << "i";
    else if (obj.imag == 0)
        os << obj.real;
    else
        os << obj.real << " + " << obj.imag << "i";
    return os;
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

Time Time::operator++()
{
    ++minute;
    if (minute >= 60)
    {
        ++hour;
        minute -= 60;
    }
    return *this;
}

Time Time ::operator++(int)
{
    Time aux;
    aux = *this;
    ++(*this);
    return aux;
}
istream &operator>>(istream &is, Time &obj)
{
    cout << "Nhap gio: ";
    is >> obj.hour;
    cout << "Nhap phut: ";
    is >> obj.minute;
    return is;
}
ostream &operator<<(ostream &os, const Time &obj)
{
    os << obj.hour << ":" << obj.minute;
    return os;
}