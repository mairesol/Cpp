#include <iostream>

using namespace std;

class CTime
{
private:
    int gio, phut, giay;

public:
    CTime(int = 0, int = 0, int = 0);

    long tong_thoi_gian() const;
    friend CTime uoc_tinh(long);

    CTime operator+(long);
    CTime operator-(long);
    CTime operator-(const CTime &);

    CTime &operator++();
    CTime operator++(int);
    CTime &operator--();
    CTime operator--(int);

    friend istream &operator>>(istream &, CTime &);
    friend ostream &operator<<(ostream &, const CTime &);
};

int main()
{
    CTime p, q;
    cout << "\nNhap khoang thoi gian thu nhat: ";
    cin >> p;

    long a;
    cout << "\nNhap so nguyen: ";
    cin >> a;

    cout << "\nPhep cong khoang thoi gian voi so nguyen: ";
    cout << p + a;

    cout << "\nPhep tru khoang thoi gian voi so nguyen: ";
    cout << p - a;

    cout << "\nNhap khoang thoi gian thu hai: ";
    cin >> q;

    cout << "\nHieu hai khoang thoi gian: ";
    cout << p - q;

    return 0;
}

CTime::CTime(int a, int b, int c) : gio(a), phut(b), giay(c) {}

long CTime::tong_thoi_gian() const
{
    return (3600 * gio + 60 * phut + giay);
}
CTime uoc_tinh(long a)
{
    CTime obj;
    a %= 86400;
    if (a < 0)
        a += 86400;
    obj.gio = a / 3600;
    a %= 3600;
    obj.phut = a / 60;
    a %= 60;
    obj.giay = a;
    return obj;
}

CTime CTime::operator+(long a)
{
    CTime obj = uoc_tinh(tong_thoi_gian() + a);
    return obj;
}
CTime CTime::operator-(long a)
{
    CTime obj = uoc_tinh(tong_thoi_gian() - a);
    return obj;
}
CTime CTime::operator-(const CTime &obj)
{
    CTime sa(0, 0, -1);
    if (obj.tong_thoi_gian() > tong_thoi_gian())
        cout << "Loi tinh toan.\n";
    else
        sa = *this - obj.tong_thoi_gian();
    return sa;
}

CTime &CTime::operator++()
{
    *this = *this + 1;
    return *this;
}
CTime CTime::operator++(int)
{
    CTime aux = *this;
    ++(*this);
    return aux;
}
CTime &CTime::operator--()
{
    *this = *this - 1;
    return *this;
}
CTime CTime::operator--(int)
{
    CTime aux = *this;
    --(*this);
    return aux;
}

istream &operator>>(istream &is, CTime &obj)
{
    is >> obj.gio;
    while (obj.gio < 0 || obj.gio > 23)
    {
        cout << "Gio khong hop le, nhap lai gio: ";
        is >> obj.gio;
    }

    is >> obj.phut;
    while (obj.phut < 0 || obj.phut > 59)
    {
        cout << "Phut khong hop le, nhap lai phut: ";
        is >> obj.phut;
    }

    is >> obj.giay;
    while (obj.giay < 0 || obj.giay > 59)
    {
        cout << "Giay khong hop le, nhap lai giay: ";
        is >> obj.giay;
    }
    return is;
}
ostream &operator<<(ostream &os, const CTime &obj)
{
    if (obj.tong_thoi_gian() >= 0)
        os << obj.gio << " gio " << obj.phut << " phut " << obj.giay << " giay";

    return os;
}
