#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

#include "da_giac.h"

using namespace std;

int menu_hinh();
int menu_chuc_nang();
bool menu_hinh_yet = false;
bool menu_chuc_yet = false;

int main()
{
    DaGiac *p;
    int choice;

    bool flag = true;
    while (flag)
    {
        flag = false;
        choice = menu_hinh();
        switch (choice)
        {
        case 1:
            p = new TuGiac;
            break;
        case 2:
            p = new TamGiac;
            break;
        case 3:
            p = new HinhBinhHanh;
            break;
        case 4:
            p = new HinhChuNhat;
            break;
        case 5:
            p = new HinhVuong;
            break;
        default:
            cout << "\nLua chon khong dung, vui long nhap lai.";
            flag = true;
            break;
        }
    }
    p->nhap();
    p->xuat();

    flag = true;
    while (flag)
    {
        choice = menu_chuc_nang();
        switch (choice)
        {
        case 0:
            cout << "\nKet thuc chuong trinh.";
            flag = false;
            break;
        case 1:
            quay(p);
            break;
        case 2:
            tinh_tien(p);
            break;
        case 3:
            phong_to(p);
            break;
        case 4:
            thu_nho(p);
            break;
        default:
            cout << "\nLua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    delete p;
    p = NULL;

    return 0;
}
//-----------------------------Menu------------------------------//
int menu_hinh()
{
    int choice;

    cout << "\n ================================";
    cout << "\n Vui long chon loai da giac:";
    cout << "\n 1. Hinh tu giac.";
    cout << "\n 2. Hinh tam giac.";
    cout << "\n 3. Hinh binh hanh.";
    cout << "\n 4. Hinh chu nhat.";
    cout << "\n 5. Hinh vuong.";
    cout << "\n ================================";

    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
int menu_chuc_nang()
{
    int choice;

    cout << "\n ================================";
    cout << "\n Vui long chon thao tac:";
    cout << "\n 0. Ket thuc chuong trinh.";
    cout << "\n 1. Quay.";
    cout << "\n 2. Tinh tien.";
    cout << "\n 3. Phong to.";
    cout << "\n 4. Thu nho.";
    cout << "\n ================================";

    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
