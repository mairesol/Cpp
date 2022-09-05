#pragma once

#include <iostream>

using namespace std;

enum LoaiCong
{
    GiaoThuong = 1,
    HocThuat = 2,
    SucManh = 3
};

class Cong
{
protected:
    int loai;

public:
    Cong(int = 0);
    ~Cong();

    virtual void nhap() = 0;
    virtual void xuat() = 0;
    int get_loai();
};

class CongGiaoThuong : public Cong
{
private:
    double tien;
    double gia;
    int hang;

public:
    CongGiaoThuong(double = 0, int = 0);
    ~CongGiaoThuong();

    void nhap();
    void xuat();
    void tinh_tien();

    double get_tien();
};

class CongHocThuat : public Cong
{
private:
    double tri_tue;

public:
    CongHocThuat(double = 0);
    ~CongHocThuat();

    void nhap();
    void xuat();

    double get_tri_tue();
};

class CongSucManh : public Cong
{
private:
    double suc_manh;

public:
    CongSucManh(double = 0);
    ~CongSucManh();

    void nhap();
    void xuat();

    double get_suc_manh();
};