#include <iostream>
#include <vector>
#include <string>

#include "so_hong.h"

using namespace std;

// SoHong
SoHong::SoHong(int a) : loaiSoHong(a){};
SoHong::~SoHong(){};

void SoHong::nhap()
{
    cout << "\nSo giay chung nhan: ";
    getline(cin, so_giay_chung_nhan);
    int n;
    cout << "\nSo nguoi su dung dat: ";
    cin >> n;
    cin.ignore(256, '\n');
    for (int i = 0; i < n; i++)
    {
        Nguoi p;
        p.nhap();
        nguoi_so_huu.push_back(p);
    }
    cout << "\nSo thua dat: ";
    cin >> so_thua;
    cout << "\nSo to ban do: ";
    cin >> so_to_ban_do;
    cin.ignore(256, '\n');
    cout << "\nDia chi thua dat: ";
    getline(cin, dia_chi);
    cout << "\nDien tich: ";
    cin >> dien_tich;
    cin.ignore(256, '\n');
    cout << "\nNgay cap: ";
    getline(cin, ngay_cap);
    cout << "\nDon gia thue: ";
    cin >> don_gia_thue;
}

void SoHong::xuat()
{
    cout << "\nSo giay chung nhan: " << so_giay_chung_nhan;
    for (int i = 0; i < nguoi_so_huu.size(); i++)
    {
        nguoi_so_huu[i].xuat();
    }
    cout << "\nSo thua dat: " << so_thua;
    cout << "\nSo to ban do: " << so_to_ban_do;
    cout << "\nDia chi thua dat: " << dia_chi;
    cout << "\nDien tich: " << dien_tich;
    cout << "\nNgay cap: " << ngay_cap;
    cout << "\nDon gia thue: " << don_gia_thue;
}

double SoHong::tinh_tien_thue()
{
    return dien_tich * don_gia_thue;
}

int SoHong::get_loai()
{
    return loaiSoHong;
}

// SoHongDatO
SoHongDatO::SoHongDatO() : SoHong(DatO){};
SoHongDatO::~SoHongDatO(){};

void SoHongDatO::nhap()
{
    SoHong::nhap();
}

void SoHongDatO::xuat()
{
    SoHong::xuat();
}

// SoHongDatNongNghiep
SoHongDatNongNghiep::SoHongDatNongNghiep() : SoHong(DatNongNghiep){};
SoHongDatNongNghiep::~SoHongDatNongNghiep(){};

void SoHongDatNongNghiep::nhap()
{
    SoHong::nhap();
    cout << "\nThoi han";
    cin >> thoi_han;
}

void SoHongDatNongNghiep::xuat()
{
    SoHong::xuat();
    cout << "\nThoi han: " << thoi_han;
}
int SoHongDatNongNghiep::get_thoi_han()
{
    return thoi_han;
}