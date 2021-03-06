#include <iostream>

using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo(int = 0, int = 1);
    ~PhanSo() {}
    PhanSo cong(const PhanSo &);
    PhanSo tru(const PhanSo &);
    PhanSo nhan(const PhanSo &);
    PhanSo chia(const PhanSo &);

    friend PhanSo chuan_hoa(PhanSo &);
    void nhap();
    void xuat();
    void dinh_gia_tri(int, int);
};
int gcd(int, int);
PhanSo chuan_hoa(PhanSo &);

int main()
{
    PhanSo p, p1, p2;
    cout << "Nhap phan so thu nhat: ";
    p1.nhap();
    cout << "Nhap phan so thu hai: ";
    p2.nhap();

    p = p1.cong(p2);
    cout << "\nTong cua hai phan so: ";
    p.xuat();

    p = p1.tru(p2);
    cout << "\nHieu cua hai phan so: ";
    p.xuat();

    p = p1.nhan(p2);
    cout << "\nTich cua hai phan so: ";
    p.xuat();

    p = p1.chia(p2);
    cout << "\nThuong cua hai phan so: ";
    p.xuat();
    return 0;
}
PhanSo::PhanSo(int t, int m)
{
    tu = t;
    mau = m;
}
PhanSo PhanSo::cong(const PhanSo &a)
{
    return PhanSo(tu * a.mau + mau * a.tu, mau * a.mau);
}
PhanSo PhanSo::tru(const PhanSo &a)
{
    return PhanSo(tu * a.mau - mau * a.tu, mau * a.mau);
}
PhanSo PhanSo::nhan(const PhanSo &a)
{
    return PhanSo(tu * a.tu, mau * a.mau);
}
PhanSo PhanSo::chia(const PhanSo &a)
{
    return PhanSo(tu * a.mau, mau * a.tu);
}
void PhanSo::nhap()
{
    cin >> tu >> mau;
    chuan_hoa(*this);
}
void PhanSo::xuat()
{
    chuan_hoa(*this);
    if (mau == 0)
        cout << "NaN";
    else if (tu == 0)
        cout << 0;
    else if (mau == 1)
        cout << tu;
    else
        cout << tu << "/" << mau;
}
void PhanSo::dinh_gia_tri(int t, int m)
{
    tu = t;
    mau = m;
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