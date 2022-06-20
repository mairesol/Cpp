#include <iostream>

#include "cong.h"
#include "hoang_tu.h"

using namespace std;

int main()
{
    int n;
    cout << "\nNhap so cong: ";
    cin >> n;

    Cong **list = new Cong *[n];
    for (int i = 0; i < n; i++)
    {
        int choice;
        cout << "\nLoai: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list[i] = new CongGiaoThuong();
            break;
        case 2:
            list[i] = new CongHocThuat();
            break;
        case 3:
            list[i] = new CongSucManh();
            break;

        default:
            break;
        }
        list[i]->nhap();
    }

    HoangTu p;
    cout << "\nNhap cac thong so ban dau cua hoang tu: ";
    p.nhap();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        flag = p.vuot_qua(list[i]);
        if (flag == false)
            break;
    }
    if (flag == true)
    {
        cout << "\nCuu cong chua thanh cong.";
        p.xuat();
    }
    else
    {
        cout << "\nCuu cong chua that bai.";
    }

    delete[] list;
}