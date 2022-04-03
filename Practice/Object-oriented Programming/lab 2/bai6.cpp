#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double = 0, double = 0);
    void thay_doi(double, double);
    double getx();
    double gety();
    void tinh_tien(double, double);
    void quay(Diem, double);
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
};

class DaGiac
{
private:
    Diem *arr;
    int so_dinh;

public:
    DaGiac(int = 3);
    ~DaGiac();
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
//-----------------------------Diem------------------------------//

//-----------------------------DaGiac------------------------------//
DaGiac::DaGiac(int s)
{
    so_dinh = max(3, s);
    arr = new Diem[so_dinh];
}
DaGiac::~DaGiac()
{
    delete[] arr;
}
void DaGiac::nhap()
{
    for (int i = 0; i < so_dinh; i++)
        cin >> arr[i];
}
void DaGiac::xuat()
{
    for (int i = 0; i < so_dinh - 1; i++)
        cout << arr[i] << ",";
    cout << arr[so_dinh - 1] << endl;
}
void DaGiac::tinh_tien(double a, double b)
{
    for (int i = 0; i < so_dinh; i++)
        arr[i].tinh_tien(a, b);
}
void DaGiac::quay(Diem I, double goc)
{
    for (int i = 0; i < so_dinh; i++)
        arr[i].quay(I, goc);
}
void DaGiac::phong_to(double k)
{

    for (int i = 0; i < so_dinh; i++)
        arr[i].thay_doi(arr[i].getx() * k, arr[i].gety() * k);
}
void DaGiac::thu_nho(double k)
{
    phong_to(1.0 / k);
}
//-----------------------------DaGiac------------------------------//