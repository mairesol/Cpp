#include <iostream>
#include <string>

#include "hoang_tu.h"

using namespace std;

HoangTu::HoangTu(double a, double b, double c) : tien(a), tri_tue(b), suc_manh(c){};

HoangTu::~HoangTu(){};

void HoangTu::nhap()
{
    cin >> tien >> tri_tue >> suc_manh;
}
void HoangTu::xuat()
{
    cout << "\nThong so: ";
    cout << "\nTien: " << tien;
    cout << "\nTri tue: " << tri_tue;
    cout << "\nSuc manh: " << suc_manh;
}

bool HoangTu::tra_tien(double a)
{
    tien -= a;
    return (tien >= 0);
}
bool HoangTu::tra_loi_cau_hoi(double a)
{
    return (tri_tue >= a);
}
bool HoangTu::mat_suc(double a)
{
    suc_manh -= a;
    return (suc_manh >= 0);
}

bool HoangTu::vuot_qua(Cong *p)
{
    int loai = p->get_loai();

    bool flag;
    switch (loai)
    {
    case 1:
        flag = tra_tien(p->get_chi_so_co_ban());
        break;

    case 2:
        flag = tra_loi_cau_hoi(p->get_chi_so_co_ban());
        break;

    case 3:
        flag = mat_suc(p->get_chi_so_co_ban());
        break;

    default:
        break;
    }

    return flag;
}