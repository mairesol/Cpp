#pragma once

#include <iostream>

#include "cong.h"

using namespace std;

class HoangTu
{
private:
    double tien;
    double tri_tue;
    double suc_manh;

public:
    HoangTu(double = 0, double = 0, double = 0);
    ~HoangTu();

    void nhap();
    void xuat();

    bool tra_tien(double);
    bool tra_loi_cau_hoi(double);
    bool mat_suc(double);

    bool vuot_qua(Cong *);
};