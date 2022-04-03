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
    void tinh_tien(double, double);
    void quay(Diem, double);
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
    void tinh_tien(double, double);
    void quay(Diem, double);
    void phong_to(double);
    void thu_nho(double);
    void nhap();
    void xuat();
};
int main()
{
    return 0;
}
//-----------------------------Diem------------------------------//
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
void Diem::tinh_tien(double a, double b)
{
    x += a;
    y += b;
}
void Diem::quay(Diem I, double goc)
{
    x = (x - I.x) * cos(goc) - (y - I.y) * sin(goc) + I.x;
    y = (x - I.x) * sin(goc) + (y - I.y) * cos(goc) + I.y;
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

//-----------------------------TamGiac------------------------------//
TamGiac::TamGiac(Diem dA, Diem dB, Diem dC)
{
    A = dA;
    B = dB;
    C = dC;
}

void TamGiac::tinh_tien(double a, double b)
{
    A.tinh_tien(a, b);
    B.tinh_tien(a, b);
    C.tinh_tien(a, b);
}
void TamGiac::quay(Diem I, double goc)
{
    A.quay(I, goc);
    B.quay(I, goc);
    C.quay(I, goc);
}
void TamGiac::phong_to(double k)
{
    A.thay_doi(A.getx() * k, A.gety() * k);
    B.thay_doi(B.getx() * k, B.gety() * k);
    C.thay_doi(C.getx() * k, C.gety() * k);
}
void TamGiac::thu_nho(double k)
{
    phong_to(1.0 / k);
}
void TamGiac::nhap()
{
    cin >> A >> B >> C;
}
void TamGiac::xuat()
{
    cout << A << "," << B << "," << C << endl;
}
//-----------------------------TamGiac------------------------------//