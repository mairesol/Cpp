#pragma once

#include <iostream>

using namespace std;

enum SoDinh
{
    so_dinh_tam_giac = 3,
    so_dinh_tu_giac = 4
};

class ToaDo
{
public:
    double x, y;

    ToaDo(double = 0, double = 0);
    void tinh_tien(double, double);
    void quay(ToaDo, double);
    friend istream &operator>>(istream &, ToaDo &);
    friend ostream &operator<<(ostream &, const ToaDo &);

    friend bool operator==(const ToaDo &, const ToaDo &);
    friend bool operator!=(const ToaDo &, const ToaDo &);
};
double tich_vo_huong(const ToaDo &, const ToaDo &);
double module(const ToaDo &, const ToaDo &);
ToaDo vectorToaDo(const ToaDo &, const ToaDo &);
bool cung_phuong(const ToaDo &, const ToaDo &);
bool vuong_goc(const ToaDo &, const ToaDo &);

class DaGiac
{
protected:
    ToaDo *D;
    int so_dinh;

public:
    DaGiac(int = 3);
    ~DaGiac();
    void tinh_tien(double, double);
    void quay(ToaDo, double);
    void phong_to(double);
    void thu_nho(double);
    virtual void nhap();
    virtual void xuat();
    virtual bool hop_le();
};

void tinh_tien(DaGiac *);
void quay(DaGiac *);
void phong_to(DaGiac *);
void thu_nho(DaGiac *);

class TuGiac : public DaGiac
{
private:
public:
    TuGiac();
    ~TuGiac();
    void nhap();
    void xuat();
};

class TamGiac : public DaGiac
{
private:
public:
    TamGiac();
    ~TamGiac();
    void nhap();
    void xuat();
};

class HinhBinhHanh : public TuGiac
{
public:
    HinhBinhHanh();
    ~HinhBinhHanh();
    void nhap();
    void xuat();
    bool hop_le();
};

class HinhChuNhat : public HinhBinhHanh
{
public:
    HinhChuNhat();
    ~HinhChuNhat();
    void nhap();
    void xuat();
    bool hop_le();
};

class HinhVuong : public HinhChuNhat
{
public:
    HinhVuong();
    ~HinhVuong();
    void nhap();
    void xuat();
    bool hop_le();
};
