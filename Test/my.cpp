#include <iostream>

using namespace std;

class CTimeSpan
{
private:
    int ngay, gio, phut, giay;

public:
    CTimeSpan(int = 0, int = 0, int = 0, int = 0);

    friend CTimeSpan chuan_hoa(CTimeSpan &);
    long tong_thoi_gian() const;

    CTimeSpan operator+(const CTimeSpan &);
    CTimeSpan operator-(const CTimeSpan &);

    bool operator==(const CTimeSpan &);
    bool operator!=(const CTimeSpan &);
    bool operator>(const CTimeSpan &);
    bool operator>=(const CTimeSpan &);
    bool operator<(const CTimeSpan &);
    bool operator<=(const CTimeSpan &);

    friend istream &operator>>(istream &, CTimeSpan &);
    friend ostream &operator<<(ostream &, const CTimeSpan &);
};

int main()
{
    int a = -1;
    cout << a / 24;

    return 0;
}

CTimeSpan::CTimeSpan(int a, int b, int c, int d) : ngay(a), gio(b), phut(c), giay(d) {}

CTimeSpan chuan_hoa(CTimeSpan &obj)
{
    long sa = obj.tong_thoi_gian();
    obj.ngay = sa / 86400;
    sa %= 86400;
    obj.gio = sa / 3600;
    sa %= 3600;
    obj.phut = sa / 60;
    sa %= 60;
    obj.giay = sa;

    return obj;
}
long CTimeSpan::tong_thoi_gian() const
{
    return (86400 * ngay + 3600 * gio + 60 * phut + giay);
}

CTimeSpan CTimeSpan::operator+(const CTimeSpan &obj)
{
    CTimeSpan sa(ngay + obj.ngay, gio + obj.gio, phut + obj.phut, giay + obj.giay);
    chuan_hoa(sa);
    return sa;
}
CTimeSpan CTimeSpan::operator-(const CTimeSpan &obj)
{
    CTimeSpan sa(ngay - obj.ngay, gio - obj.gio, phut - obj.phut, giay - obj.giay);
    if (sa.tong_thoi_gian() >= 0)
        chuan_hoa(sa);
    else
        cout << "Loi tinh toan.\n";
    return sa;
}

bool CTimeSpan::operator==(const CTimeSpan &obj)
{
    return (ngay == obj.ngay && gio == obj.gio && phut == obj.phut && giay == obj.giay);
}
bool CTimeSpan::operator!=(const CTimeSpan &obj)
{
    return !(*this == obj);
}
bool CTimeSpan::operator>(const CTimeSpan &obj)
{
    return (tong_thoi_gian() > obj.tong_thoi_gian());
}
bool CTimeSpan::operator>=(const CTimeSpan &obj)
{
    return (tong_thoi_gian() >= obj.tong_thoi_gian());
}
bool CTimeSpan::operator<(const CTimeSpan &obj)
{
    return (tong_thoi_gian() < obj.tong_thoi_gian());
}
bool CTimeSpan::operator<=(const CTimeSpan &obj)
{
    return (tong_thoi_gian() <= obj.tong_thoi_gian());
}

istream &operator>>(istream &is, CTimeSpan &obj)
{
    is >> obj.ngay;
    while (obj.ngay < 0)

    {
        cout << "Ngay khong hop le, nhap lai ngay: ";
        is >> obj.ngay;
    }

    is >> obj.gio;
    while (obj.gio < 0)
    {
        cout << "Gio khong hop le, nhap lai gio: ";
        is >> obj.gio;
    }

    is >> obj.phut;
    while (obj.phut < 0)
    {
        cout << "Phut khong hop le, nhap lai phut: ";
        is >> obj.phut;
    }

    is >> obj.giay;
    while (obj.giay < 0)
    {
        cout << "Giay khong hop le, nhap lai giay: ";
        is >> obj.giay;
    }
    chuan_hoa(obj);
    return is;
}
ostream &operator<<(ostream &os, const CTimeSpan &obj)
{
    if (obj.tong_thoi_gian() < 0)
        return os;

    if (obj.tong_thoi_gian() == 0)
        os << 0 << " giay";
    else if (obj.tong_thoi_gian() < 60)
        os << obj.giay << " giay";
    else if (obj.tong_thoi_gian() < 3600)
        os << obj.phut << " phut " << obj.giay << " giay";
    else if (obj.tong_thoi_gian() < 86400)
        os << obj.gio << " gio " << obj.phut << " phut " << obj.giay << " giay";
    else
        os << obj.ngay << " ngay " << obj.gio << " gio " << obj.phut << " phut " << obj.giay << " giay";
    return os;
}
