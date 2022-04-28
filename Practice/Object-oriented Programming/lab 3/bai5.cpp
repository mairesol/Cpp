#include <iostream>

using namespace std;

class CDate
{
private:
    int ngay, thang, nam;

public:
    CDate(int = 0, int = 0, int = 0);

    friend bool nam_nhuan(const CDate &);
    friend int ngay_trong_thang(const CDate &);
    friend bool hop_le(const CDate &);
    friend long long uoc_tinh(CDate);

    CDate operator+(long);
    CDate operator-(long);
    long long operator-(const CDate &);

    CDate &operator++();
    CDate operator++(int);
    CDate &operator--();
    CDate operator--(int);

    friend istream &operator>>(istream &, CDate &);
    friend ostream &operator<<(ostream &, const CDate &);
};

int main()
{
    return 0;
}

CDate::CDate(int a, int b, int c) : ngay(a), thang(b), nam(c) {}

bool nam_nhuan(const CDate &obj)
{
    return ((obj.nam % 4 == 0 && obj.nam % 100 != 0) || obj.nam % 400 == 0);
}

int ngay_trong_thang(const CDate &obj)
{
    int ans;
    switch (obj.thang)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        ans = 30;
        break;
    case 2:
        if (nam_nhuan(obj))
            ans = 29;
        else
            ans = 28;
        break;
    default:
        ans = 31;
        break;
    }
    return ans;
}

bool hop_le(const CDate &obj)
{
    if (obj.nam < 0)
        return false;
    if (obj.thang < 1 || obj.thang > 12)
        return false;
    if (obj.ngay < 1 || obj.ngay > ngay_trong_thang(obj))
        return false;
    return true;
}
long long uoc_tinh(CDate x)
{
    long long a = x.ngay;
    do
    {
        switch (x.thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            a += 31;
            x.thang--;
            if (x.thang == 0)
            {
                x.nam--;
                x.thang = 12;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            a += 30;
            x.thang--;
            break;
        case 2:
            if (nam_nhuan(x))
            {
                a += 29;
                x.thang--;
            }
            else
            {
                a += 28;
                x.thang--;
            }
        }
    } while (x.nam > 0);
    return a;
}
CDate CDate::operator+(long a)
{
    CDate d = *this;
    a += d.ngay;
    do
    {
        switch (d.thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (a > 31)
            {
                d.thang++;
                if (d.thang == 13)
                {
                    d.thang = 1;
                    d.nam++;
                }
                a -= 31;
            }
            else
            {
                d.ngay = a;
                a = 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (a > 30)
            {
                d.thang++;
                a -= 30;
            }
            else
            {
                d.ngay = a;
                a = 0;
            }
            break;
        case 2:
            if (nam_nhuan(d))
            {
                if (a > 29)
                {
                    d.thang++;
                    a -= 29;
                }
                else
                {
                    d.ngay = a;
                    a = 0;
                }
            }
            else
            {
                if (a > 28)
                {
                    d.thang++;
                    a -= 28;
                }
                else
                {
                    d.ngay = a;
                    a = 0;
                }
            }
            break;
        default:
            break;
        }
    } while (a > 0);
    return d;
}
CDate CDate::operator-(long a)
{
    CDate d = *this;
    do
    {
        if (d.ngay > a)
        {
            d.ngay -= a;
            a = 0;
        }
        else
        {
            a -= d.ngay;
            d.thang--;
            switch (d.thang)
            {
            case 0:
                d.thang = 12;
                d.nam--;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                d.ngay = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                d.ngay = 30;
                break;
            case 2:
                if (nam_nhuan(d))
                    d.ngay = 29;
                else
                    d.ngay = 28;
                break;

            default:
                break;
            }
        }
    } while (a > 0);
    return d;
}
long long CDate::operator-(const CDate &d)
{
    int a = uoc_tinh(*this), b = uoc_tinh(d);
    if (a < b)
    {
        cout << "Loi tinh toan.\n";
        return -1;
    }
    else
        return a - b;
}

CDate &CDate::operator++()
{
    *this = *this + 1;
    return *this;
}
CDate CDate::operator++(int)
{
    CDate aux = *this;
    ++(*this);
    return aux;
}
CDate &CDate::operator--()
{
    *this = *this - 1;
    return *this;
}
CDate CDate::operator--(int)
{
    CDate aux = *this;
    --(*this);
    return aux;
}

istream &operator>>(istream &is, CDate &obj)
{
    bool flag;
    do
    {
        flag = false;
        is >> obj.ngay >> obj.thang >> obj.nam;
        flag = hop_le(obj);
        if (flag == false)
            cout << "Khong hop le!\n";
    } while (!flag);
    return is;
}
ostream &operator<<(ostream &os, const CDate &obj)
{
    cout << " ngay " << obj.ngay << " thang " << obj.thang << " nam " << obj.nam;
    return os;
}