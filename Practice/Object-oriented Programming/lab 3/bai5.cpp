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
}