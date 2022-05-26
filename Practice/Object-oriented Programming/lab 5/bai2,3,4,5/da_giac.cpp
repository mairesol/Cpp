#include <iostream>
#include <math.h>
#include <vector>

#include "da_giac.h"

//-----------------------------ToaDo------------------------------//
ToaDo::ToaDo(double dx, double dy)
{
    x = dx;
    y = dy;
}
void ToaDo::tinh_tien(double a, double b)
{
    x += a;
    y += b;
}
void ToaDo::quay(ToaDo I, double goc)
{
    x = (x - I.x) * cos(goc) - (y - I.y) * sin(goc) + I.x;
    y = (x - I.x) * sin(goc) + (y - I.y) * cos(goc) + I.y;
}
istream &operator>>(istream &is, ToaDo &obj)
{
    is >> obj.x;
    is >> obj.y;
    return is;
}
ostream &operator<<(ostream &os, const ToaDo &obj)
{
    cout << "(" << obj.x << ";" << obj.y << ")";
    return os;
}
bool operator==(const ToaDo &l, const ToaDo &r)
{
    return ((l.x == r.x) && (l.y == r.y));
}
bool operator!=(const ToaDo &l, const ToaDo &r)
{
    return !(l == r);
}
double tich_vo_huong(const ToaDo &l, const ToaDo &r)
{
    return l.x * r.x + l.y * r.y;
}
double module(const ToaDo &l, const ToaDo &r)
{
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}
ToaDo vectorToaDo(const ToaDo &l, const ToaDo &r)
{
    return ToaDo(r.x - l.x, r.y - l.y);
}
bool cung_phuong(ToaDo &l, ToaDo &r)
{
    if (l == ToaDo(0, 0) || r == ToaDo(0, 0))
        return false;
    if ((l.x == 0 && r.x == 0) || (l.y == 0 && r.y == 0))
        return true;
    return ((l.x / r.x) == (l.y / r.y));
}
bool vuong_goc(const ToaDo &l, const ToaDo &r)
{
    if (l == ToaDo(0, 0) || r == ToaDo(0, 0))
        return false;
    return (tich_vo_huong(l, r) == 0);
}

//-----------------------------DaGiac------------------------------//
DaGiac::DaGiac(int s)
{
    so_dinh = max(3, s);
    D = new ToaDo[so_dinh];
}
DaGiac::~DaGiac()
{
    delete[] D;
}
void DaGiac::nhap()
{
    for (int i = 0; i < so_dinh; i++)
        cin >> D[i];
    while (!hop_le())
    {
        cout << "\nKhong hop le. Nhap lai: ";
        for (int i = 0; i < so_dinh; i++)
            cin >> D[i];
    }
}
void DaGiac::xuat()
{
    cout << "{";
    for (int i = 0; i < so_dinh - 1; i++)
        cout << D[i] << ",";
    cout << D[so_dinh - 1] << "}" << endl;
}
void DaGiac::tinh_tien(double a, double b)
{
    for (int i = 0; i < so_dinh; i++)
        D[i].tinh_tien(a, b);
}
void DaGiac::quay(ToaDo I, double goc)
{
    for (int i = 0; i < so_dinh; i++)
        D[i].quay(I, goc);
}
void DaGiac::phong_to(double k)
{

    for (int i = 0; i < so_dinh; i++)
    {
        D[i].x *= k;
        D[i].y *= k;
    }
}
void DaGiac::thu_nho(double k)
{
    phong_to(1.0 / k);
}
bool DaGiac::hop_le()
{
    for (int i = 0; i < so_dinh - 1; i++)
        for (int j = i + 1; j < so_dinh; j++)
            if (D[i] == D[j])
                return false;
    return true;
}
//-----------------------------TuGiac------------------------------//
TuGiac::TuGiac() : DaGiac(so_dinh_tu_giac){};
TuGiac::~TuGiac(){};
void TuGiac::nhap()
{
    cout << "Tu giac: ";
    DaGiac::nhap();
}
void TuGiac::xuat()
{
    cout << "Tu giac: ";
    DaGiac::xuat();
}

//-----------------------------TamGiac------------------------------//
TamGiac::TamGiac() : DaGiac(so_dinh_tam_giac){};
TamGiac::~TamGiac(){};
void TamGiac::nhap()
{
    cout << "Tam giac: ";
    DaGiac::nhap();
}
void TamGiac::xuat()
{
    cout << "Tam giac: ";
    DaGiac::xuat();
}

//-----------------------------HinhBinhHanh------------------------------//
HinhBinhHanh::HinhBinhHanh(){};
HinhBinhHanh::~HinhBinhHanh(){};
void HinhBinhHanh::nhap()
{
    cout << "Hinh binh hanh: ";
    for (int i = 0; i < so_dinh; i++)
        cin >> D[i];
    while (!hop_le())
    {
        cout << "\nKhong hop le. Nhap lai: ";
        for (int i = 0; i < so_dinh; i++)
            cin >> D[i];
    }
}
void HinhBinhHanh::xuat()
{
    cout << "Hinh binh hanh: ";
    DaGiac::xuat();
}
bool HinhBinhHanh::hop_le()
{
    // Tứ giác có hai cặp cạnh đối song song

    if (TuGiac::hop_le() != true)
        return false;

    int count = 0;
    vector<ToaDo> v(0);
    for (int i = 0; i < so_dinh - 1; i++)
        for (int j = i + 1; j < so_dinh; j++)
            v.push_back(vectorToaDo(D[i], D[j]));

    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (cung_phuong(v[i], v[j]))
                count++;

    return (count == 2);
}

//-----------------------------HinhChuNhat------------------------------//
HinhChuNhat::HinhChuNhat(){};
HinhChuNhat::~HinhChuNhat(){};
void HinhChuNhat::nhap()
{
    cout << "Hinh chu nhat: ";
    for (int i = 0; i < so_dinh; i++)
        cin >> D[i];
    while (!hop_le())
    {
        cout << "\nKhong hop le. Nhap lai: ";
        for (int i = 0; i < so_dinh; i++)
            cin >> D[i];
    }
}
void HinhChuNhat::xuat()
{
    cout << "Hinh chu nhat: ";
    DaGiac::xuat();
}
bool HinhChuNhat::hop_le()
{
    // Tứ giác có bốn góc vuông

    if (TuGiac::hop_le() != true)
        return false;

    int count = 0;
    vector<ToaDo> v(0);
    for (int i = 0; i < so_dinh - 1; i++)
        for (int j = i + 1; j < so_dinh; j++)
            v.push_back(vectorToaDo(D[i], D[j]));

    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (vuong_goc(v[i], v[j]))
                count++;

    return (count >= 4);
}

//-----------------------------HinhVuong------------------------------//
HinhVuong::HinhVuong(){};
HinhVuong::~HinhVuong(){};
void HinhVuong::nhap()
{
    cout << "Hinh vuong: ";
    for (int i = 0; i < so_dinh; i++)
        cin >> D[i];
    while (!hop_le())
    {
        cout << "\nKhong hop le. Nhap lai: ";
        for (int i = 0; i < so_dinh; i++)
            cin >> D[i];
    }
}
void HinhVuong::xuat()
{
    cout << "Hinh vuong: ";
    DaGiac::xuat();
}
bool HinhVuong::hop_le()
{
    // Hình chữ nhật có hai đường chéo vuông góc

    if (TuGiac::hop_le() != true)
        return false;

    int count = 0;
    vector<ToaDo> v(0);
    for (int i = 0; i < so_dinh - 1; i++)
        for (int j = i + 1; j < so_dinh; j++)
            v.push_back(vectorToaDo(D[i], D[j]));

    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (vuong_goc(v[i], v[j]))
                count++;

    return (count == 5);
}

//-----------------------------Chuc nang------------------------------//
void quay(DaGiac *p)
{
    ToaDo I;
    double goc;
    cout << "\n-----Quay-----";
    cout << "\nNhap toa do tam: ";
    cin >> I;
    cout << "\nNhap goc quay: ";
    cin >> goc;
    p->quay(I, goc);
    p->xuat();
}
void tinh_tien(DaGiac *p)
{
    int x, y;
    cout << "\n-----Tinh tien-----";
    cout << "\nNhap vector: ";
    cin >> x >> y;
    p->tinh_tien(x, y);
    p->xuat();
}
void phong_to(DaGiac *p)
{
    int ti_le;
    cout << "\n-----Phong to-----";
    cout << "\nNhap ti le: ";
    cin >> ti_le;
    p->phong_to(ti_le);
    p->xuat();
}
void thu_nho(DaGiac *p)
{
    int ti_le;
    cout << "\n-----Thu nho-----";
    cout << "\nNhap ti le: ";
    cin >> ti_le;
    p->thu_nho(ti_le);
    p->xuat();
}