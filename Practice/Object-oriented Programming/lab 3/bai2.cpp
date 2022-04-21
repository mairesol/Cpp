#include <iostream>

using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo(int = 0, int = 1);

    friend PhanSo chuan_hoa(PhanSo &);

    PhanSo operator+(const PhanSo &);
    PhanSo operator-(const PhanSo &);
    PhanSo operator*(const PhanSo &);
    PhanSo operator/(const PhanSo &);

    bool operator==(const PhanSo &);
    bool operator!=(const PhanSo &);
    bool operator>(const PhanSo &);
    bool operator>=(const PhanSo &);
    bool operator<(const PhanSo &);
    bool operator<=(const PhanSo &);

    friend istream &operator>>(istream &, PhanSo &);
    friend ostream &operator<<(ostream &, const PhanSo &);
};
int gcd(int, int);
PhanSo chuan_hoa(PhanSo &);

int main()
{
    PhanSo p1, p2;
    cout << "Nhap phan so thu nhat: ";
    cin >> p1;
    cout << "Nhap phan so thu hai: ";
    cin >> p2;

    cout << "\nTong cua hai phan so: ";
    cout << p1 + p2;

    cout << "\nHieu cua hai phan so: ";
    cout << p1 - p2;

    cout << "\nTich cua hai phan so: ";
    cout << p1 * p2;

    cout << "\nThuong cua hai phan so: ";
    cout << p1 / p2;
    return 0;
}

PhanSo ::PhanSo(int t, int m) : tu(t), mau(m) {}

PhanSo PhanSo::operator+(const PhanSo &b)
{
    PhanSo c(tu * b.mau + mau * b.tu, mau * b.mau);
    chuan_hoa(c);
    return c;
}
PhanSo PhanSo::operator-(const PhanSo &b)
{
    PhanSo c(tu * b.mau - mau * b.tu, mau * b.mau);
    chuan_hoa(c);
    return c;
}
PhanSo PhanSo::operator*(const PhanSo &b)
{
    PhanSo c(tu * b.tu, mau * b.mau);
    chuan_hoa(c);
    return c;
}
PhanSo PhanSo::operator/(const PhanSo &b)
{
    PhanSo c(tu * b.mau, mau * b.tu);
    if (c.mau == 0)
        cout << "Loi chia cho 0.\n";
    else
        chuan_hoa(c);
    return c;
}

bool PhanSo::operator==(const PhanSo &b)
{
    return (tu * b.mau == mau * b.tu);
}
bool PhanSo::operator!=(const PhanSo &b)
{
    return (tu * b.mau != mau * b.tu);
}
bool PhanSo::operator>(const PhanSo &b)
{
    return (tu * b.mau > mau * b.tu);
}
bool PhanSo::operator>=(const PhanSo &b)
{
    return (tu * b.mau >= mau * b.tu);
}
bool PhanSo::operator<(const PhanSo &b)
{
    return (tu * b.mau < mau * b.tu);
}
bool PhanSo::operator<=(const PhanSo &b)
{
    return (tu * b.mau <= mau * b.tu);
}

istream &operator>>(istream &is, PhanSo &b)
{
    is >> b.tu >> b.mau;
    while (b.mau == 0)
    {
        cout << "Mau so bang 0, nhap lai mau: ";
        is >> b.mau;
    }
    chuan_hoa(b);
    return is;
}
ostream &operator<<(ostream &os, const PhanSo &b)
{
    if (b.mau == 0)
        os << "inf";
    else if (b.tu == 0)
        os << 0;
    else if (b.mau == 1)
        os << b.tu;
    else
        os << b.tu << "/" << b.mau;
    return os;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
PhanSo chuan_hoa(PhanSo &a)
{
    while (gcd(a.tu, a.mau) != 1)
    {
        int temp = a.tu;
        a.tu /= gcd(temp, a.mau);
        a.mau /= gcd(temp, a.mau);
    }
    if (a.mau < 0)
    {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
    return a;
}