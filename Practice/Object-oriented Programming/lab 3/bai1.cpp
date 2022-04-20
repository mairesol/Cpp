#include <iostream>
#include <math.h>

using namespace std;

class SoPhuc
{
private:
    double thuc, ao;

public:
    SoPhuc(double = 0, double = 0);

    friend double module(const SoPhuc &);

    SoPhuc operator+(const SoPhuc &);
    SoPhuc operator-(const SoPhuc &);
    SoPhuc operator*(const SoPhuc &);
    SoPhuc operator/(const SoPhuc &);

    bool operator==(const SoPhuc &);
    bool operator!=(const SoPhuc &);
    bool operator>(const SoPhuc &);
    bool operator>=(const SoPhuc &);
    bool operator<(const SoPhuc &);
    bool operator<=(const SoPhuc &);

    friend istream &operator>>(istream &, SoPhuc &);
    friend ostream &operator<<(ostream &, const SoPhuc &);
};

int main()
{
    SoPhuc p1, p2;
    cout << "Nhap so phuc thu nhat: ";
    cin >> p1;
    cout << "Nhap so phuc thu hai: ";
    cin >> p2;

    cout << "\nTong cua hai so phuc: ";
    cout << p1 + p2;

    cout << "\nHieu cua hai so phuc: ";
    cout << p1 - p2;

    cout << "\nTich cua hai so phuc: ";
    cout << p1 * p2;

    cout << "\nThuong cua hai so phuc: ";
    cout << p1 / p2;
    return 0;
}

SoPhuc ::SoPhuc(double t, double a) : thuc(t), ao(a) {}

double module(const SoPhuc &b)
{
    return sqrt(b.thuc * b.thuc + b.ao * b.ao);
}

SoPhuc SoPhuc::operator+(const SoPhuc &b)
{
    return SoPhuc(thuc + b.thuc, ao + b.ao);
}
SoPhuc SoPhuc::operator-(const SoPhuc &b)
{
    return SoPhuc(thuc - b.thuc, ao - b.ao);
}
SoPhuc SoPhuc::operator*(const SoPhuc &b)
{
    return SoPhuc(thuc * b.thuc - ao * b.ao, thuc * b.ao + ao * b.thuc);
}
SoPhuc SoPhuc::operator/(const SoPhuc &b)
{
    return SoPhuc((thuc * b.thuc + ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao), (b.thuc * ao - thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao));
}

bool SoPhuc::operator==(const SoPhuc &b)
{
    return (module(*this) == module(b));
}
bool SoPhuc::operator!=(const SoPhuc &b)
{
    return !(*this == b);
}
bool SoPhuc::operator>(const SoPhuc &b)
{
    return (module(*this) > module(b));
}
bool SoPhuc::operator>=(const SoPhuc &b)
{
    return (module(*this) >= module(b));
}
bool SoPhuc::operator<(const SoPhuc &b)
{
    return (module(*this) < module(b));
}
bool SoPhuc::operator<=(const SoPhuc &b)
{
    return (module(*this) <= module(b));
}
istream &operator>>(istream &is, SoPhuc &b)
{
    is >> b.thuc >> b.ao;
    return is;
}
ostream &operator<<(ostream &os, const SoPhuc &b)
{
    if (b.thuc == 0 && b.ao == 0)
        os << 0;
    else if (b.ao == 0)
        os << b.thuc;
    else if (b.thuc == 0)
    {
        if (b.ao == 1)
            os << 'i';
        else
            os << b.ao << 'i';
    }
    else
    {
        if (b.ao == 1)
            os << b.thuc << '+' << 'i';
        else
            os << b.thuc << '+' << b.ao << 'i';
    }
    return os;
}