#include <iostream>

#include "cong.h"


using namespace std;

// Cong
Cong::Cong(int a) : loai(a){};
Cong::~Cong(){};

int Cong::get_loai()
{
    return loai;
}

// Cong giao thuong
CongGiaoThuong::CongGiaoThuong(double a, int b) : Cong(GiaoThuong)
{
    gia = a;
    hang = b;
    tinh_tien();
}

void CongGiaoThuong::nhap()
{
    cin >> gia >> hang;
    tinh_tien();
}
void CongGiaoThuong::xuat()
{
    cout << tien;
}
void CongGiaoThuong::tinh_tien()
{
    tien = gia * hang;
}
double CongGiaoThuong::get_tien()
{
    return tien;
};

// Cong hoc thuat
CongHocThuat::CongHocThuat(double a) : Cong(HocThuat)
{
    tri_tue = a;
}
CongHocThuat::~CongHocThuat(){};

void CongHocThuat::nhap()
{
    cin >> tri_tue;
}
void CongHocThuat::xuat()
{
    cout << tri_tue;
}
double CongHocThuat::get_tri_tue()
{
    return tri_tue;
};

// CongSucManh
CongSucManh::CongSucManh(double a) : Cong(SucManh)
{
    suc_manh = a;
}
CongSucManh::~CongSucManh(){};

void CongSucManh::nhap()
{
    cin >> suc_manh;
}
void CongSucManh::xuat()
{
    cout << suc_manh;
}
double CongSucManh ::get_suc_manh()
{
    return suc_manh;
}