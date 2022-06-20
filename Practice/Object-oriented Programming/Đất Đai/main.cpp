#include <iostream>

#include "so_hong.h"

#define nam_hien_tai 2022

using namespace std;

int main()
{
    int n;
    cout << "\nNhap so giay chung nhan quyen so huu dat: ";
    cin >> n;
    SoHong **list = new SoHong *[n];
    for (int i = 0; i < n; i++)
    {
        int choice;
        cout << "\nLua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list[i] = new SoHongDatO;
            break;
        case 2:
            list[i] = new SoHongDatNongNghiep;
            break;
        default:
            break;
        }
        cin.ignore(256, '\n');
        list[i]->nhap();
    }

    for (int i = 0; i < n; i++)
    {
        list[i]->xuat();
    }

    double tien_thue_max = 0;
    SoHong *p_max;
    for (int i = 0; i < n; i++)
    {
        if (list[i]->tinh_tien_thue() > tien_thue_max)
        {
            tien_thue_max = list[i]->tinh_tien_thue();
            p_max = list[i];
        }
    }
    p_max->xuat();

    SoHong *p;
    for (int i = 0; i < n; i++)
    {
        if (nam_hien_tai > dynamic_cast<SoHongDatNongNghiep *>(list[i])->get_thoi_han())
        {
            list[i]->xuat();
            cout << endl;
        }
    }
    delete[] list;
}