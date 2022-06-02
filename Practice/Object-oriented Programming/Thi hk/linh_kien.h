#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LinhKien
{
protected:
    long ma_sp;
    long gia_tien;
    bool trang_thai;

public:
    LinhKien(long, long, bool);
    ~LinhKien();
    virtual double get_xung_nhip() = 0;

    virtual void nhap();
    virtual void xuat();
};

class CPU : public LinhKien
{
private:
    string ten;
    string nhan_hieu;
    double muc_tieu_thu_dien;
    double xung_nhip;
    int so_nhan;
    int so_luong;

public:
    CPU(long = 0, long = 0, bool = false, string = "", string = "", double = 0, double = 0, int = 0, int = 0);
    ~CPU();

    void nhap();
    void xuat();

    double get_xung_nhip();
};

class GPU : public LinhKien
{
private:
    string ten;
    string nhan_hieu;
    double muc_tieu_thu_dien;
    double xung_nhip;
    double VRAM;

public:
    GPU(long = 0, long = 0, bool = false, string = "", string = "", double = 0, double = 0, double = 0);
    ~GPU();

    void nhap();
    void xuat();

    double get_xung_nhip();
};

class QuanLi
{
private:
    vector<LinhKien *> v;

public:
    void nhap();
    void xuat();
    void xung_nhip_manh_nhat();
};