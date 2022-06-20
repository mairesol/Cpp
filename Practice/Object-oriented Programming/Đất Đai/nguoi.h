#pragma once

#include <iostream>

using namespace std;

class Nguoi
{
private:
    string ten;
    int nam_sinh;
    string CMND;
    string dia_chi_thuong_tru;

public:
    void nhap();
    void xuat();
};