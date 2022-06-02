#include <iostream>

#include "linh_kien.h"

//-----------------------------LinhKien-----------------------------
LinhKien::LinhKien(long a, long b, bool c) : ma_sp(a), gia_tien(b), trang_thai(c){};
LinhKien::~LinhKien(){};
void LinhKien::nhap()
{
    cout << "\nMa san phan: ";
    cin >> ma_sp;
    cout << "\nGia tien: ";
    cin >> gia_tien;
    cout << "\nTrang thai: ";
    cin >> trang_thai;
}
void LinhKien::xuat()
{
    string tt;
    if (trang_thai == true)
        tt = "da ban";
    else
        tt = "chua ban";
    cout << ma_sp << "\t" << gia_tien << "\t" << tt;
}

//-----------------------------CPU-----------------------------
CPU::CPU(long a, long b, bool c, string d, string e, double f, double g, int h, int i) : LinhKien(a, b, c)
{
    ten = d;
    nhan_hieu = e;
    muc_tieu_thu_dien = f;
    xung_nhip = g;
    so_nhan = h;
    so_luong = i;
}
CPU::~CPU(){};

double CPU::get_xung_nhip()
{
    return xung_nhip;
}

void CPU::nhap()
{
    LinhKien::nhap();
    cin.ignore(256, '\n');
    cout << "\nTen: ";
    getline(cin, ten);
    cout << "\nNhan hieu: ";
    getline(cin, nhan_hieu);
    cout << "\nMuc tieu thu dien: ";
    cin >> muc_tieu_thu_dien;
    cout << "\nXung nhip: ";
    cin >> xung_nhip;
    cout << "\nSo nhan: ";
    cin >> so_nhan;
    cout << "\nSo luong: ";
    cin >> so_luong;
}
void CPU::xuat()
{
    LinhKien::xuat();
    cout << endl;
    cout << ten << "\t" << nhan_hieu << "\t"
         << muc_tieu_thu_dien << " W\t" << xung_nhip << " Ghz\t"
         << so_nhan << " nhan\t" << so_luong << " luong";
}

//-----------------------------GPU-----------------------------
GPU::GPU(long a, long b, bool c, string d, string e, double f, double g, double h) : LinhKien(a, b, c)
{
    ten = d;
    nhan_hieu = e;
    muc_tieu_thu_dien = f;
    xung_nhip = g;
    VRAM = h;
}
GPU::~GPU(){};
double GPU::get_xung_nhip()
{
    return xung_nhip;
}

void GPU::nhap()
{
    LinhKien::nhap();
    cin.ignore(256, '\n');
    cout << "\nTen: ";
    getline(cin, ten);
    cout << "\nNhan hieu: ";
    getline(cin, nhan_hieu);
    cout << "\nMuc tieu thu dien: ";
    cin >> muc_tieu_thu_dien;
    cout << "\nXung nhip: ";
    cin >> xung_nhip;
    cout << "\nVRAM: ";
    cin >> VRAM;
}
void GPU::xuat()
{
    LinhKien::xuat();
    cout << endl;
    cout << ten << "\t" << nhan_hieu << "\t"
         << muc_tieu_thu_dien << " W\t" << xung_nhip << " Ghz\t" << VRAM << " GB";
}

//-----------------------------QuanLi-----------------------------
void QuanLi::nhap()
{
    int n;
    cout << "\nSo linh kien can quan li: ";
    cin >> n;

    LinhKien *p;
    cout << "\n\nCac loai linh kien:";
    cout << "\n1. CPU.";
    cout << "\n2. GPU.";

    int choice;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nLua chon loai linh kien thu " << i << ": ";
        do
        {
            cin >> choice;
        } while (choice != 1 && choice != 2);
        switch (choice)
        {
        case 1:
            p = new CPU;
            break;
        case 2:
            p = new GPU;
        default:
            break;
        }

        p->nhap();
        v.push_back(p);
    }
}
void QuanLi::xuat()
{
    cout << "\nDanh sach linh kien: ";

    for (int i = 1; i <= v.size(); i++)
    {
        cout << "\n\nLinh kien thu " << i << ": " << endl;
        v[i - 1]->xuat();
    }
}
void QuanLi::xung_nhip_manh_nhat()
{
    LinhKien *p_xung_nhip_manh_nhat = v[0];
    double xung_nhip_manh_nhat = v[0]->get_xung_nhip();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->get_xung_nhip() >= xung_nhip_manh_nhat)
        {
            p_xung_nhip_manh_nhat = v[i];
            xung_nhip_manh_nhat = v[i]->get_xung_nhip();
        }
    }
    cout << "\nLinh kien co xung nhip manh nhat: " << endl;
    p_xung_nhip_manh_nhat->xuat();
}