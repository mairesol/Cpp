#pragma once

#include <string>
#include <vector>

#include "nguoi.h"

enum LoaiSoHong
{
    DatO = 1,
    DatNongNghiep = 2
};

using namespace std;

class SoHong
{
private:
    int loaiSoHong;

protected:
    string so_giay_chung_nhan;
    vector<Nguoi> nguoi_so_huu;
    int so_thua;
    int so_to_ban_do;
    string dia_chi;
    double dien_tich;
    string ngay_cap;
    double don_gia_thue;

public:
    SoHong(int = -1);
    ~SoHong();
    int get_loai();

    virtual void nhap() = 0;
    virtual void xuat() = 0;
    double tinh_tien_thue();
};

class SoHongDatO : public SoHong
{
private:
public:
    SoHongDatO();
    ~SoHongDatO();

    void nhap();
    void xuat();
};

class SoHongDatNongNghiep : public SoHong
{
private:
    int thoi_han;

public:
    SoHongDatNongNghiep();
    ~SoHongDatNongNghiep();

    void nhap();
    void xuat();
    int get_thoi_han();
};