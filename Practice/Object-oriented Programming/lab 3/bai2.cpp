#include <iostream>
#include <math.h>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double = 0, double = 0);
    ~Diem() {}
    void thay_doi(double, double);
    double getx();
    double gety();
    Diem tinh_tien(double, double);
    Diem quay(Diem, double);
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
};

class TamGiac
{
private:
    Diem A, B, C;

public:
    TamGiac(Diem = Diem(0, 0), Diem = Diem(0, 0), Diem = Diem(0, 0));
    ~TamGiac() {}
    TamGiac tinh_tien(double, double);
    TamGiac quay(Diem, double);
    TamGiac thay_doi_kich_thuoc(double);
    void nhap();
    void xuat();
};
int main()
{
    return 0;
}
Diem::Diem(double dx, double dy)
{
    x = dx;
    y = dy;
}
void Diem::thay_doi(double dx, double dy)
{
    x = dx;
    y = dy;
}
double Diem::getx()
{
    return x;
}
double Diem::gety()
{
    return y;
}
Diem Diem::tinh_tien(double a, double b)
{
    x += a;
    y += b;
    return *this;
}
Diem Diem::quay(Diem I, double goc)
{
    x = (x - I.x) * cos(goc) - (y - I.y) * sin(goc) + I.x;
    y = (x - I.x) * sin(goc) + (y - I.y) * cos(goc) + I.y;
    return *this;
}
istream &operator>>(istream &is, Diem &obj)
{
    is >> obj.x >> obj.y;
    return is;
}
ostream &operator<<(ostream &os, const Diem &obj)
{
    cout << "(" << obj.x << ";" << obj.y << ")";
    return os;
}

TamGiac::TamGiac(Diem dA, Diem dB, Diem dC)
{
    A = dA;
    B = dB;
    C = dC;
}

TamGiac TamGiac::tinh_tien(double a, double b)
{
    A.tinh_tien(a, b);
    B.tinh_tien(a, b);
    C.tinh_tien(a, b);
    return *this;
}
TamGiac TamGiac::quay(Diem I, double goc)
{
    A.quay(I, goc);
    B.quay(I, goc);
    C.quay(I, goc);
    return *this;
}
TamGiac TamGiac::thay_doi_kich_thuoc(double k)
{
    A.thay_doi(A.getx() * k, A.gety() * k);
    B.thay_doi(B.getx() * k, B.gety() * k);
    C.thay_doi(C.getx() * k, C.gety() * k);
    return *this;
}
void TamGiac::nhap()
{
    cout << "Nhap diem thu nhat: ";
    cin >> A;
    cout << "Nhap diem thu hai: ";
    cin >> B;
    cout << "Nhap diem thu ba: ";
    cin >> C;
}
void TamGiac::xuat()
{
    cout << "Tam giac tao boi 3 diem: " << A << "," << B << "," << C << "." << endl;
}