#include <iostream>
#include < string>

using namespace std;

struct NGAYTHANG
{
    int ngay;
    int thang;
    int nam;

    void NhapNgayThangNam()
    {
        cin >> ngay >> thang >> nam;
    }
    void XuatNgayThangNam()
    {
        cout << ngay << thang << nam;
    }
};

struct SV
{
    string masv;
    string hodem;
    string ten;
    NGAYTHANG ngsinh;
    string gioitinh;
    string hokhau;
    float diem;

    void Nhapsv()
    {
        cin.ignore();
        cout << "\tMa sv: ";
        cin >> masv;
        cin.ignore();
        cout << "\tHo dem: ";
        getline(cin, hodem);
        cout << "\tTen: ";
        cin >> ten;
        cout << "\tNgay sinh: ";
        cin >> ngsinh.ngay;
        cout << "\tThang sinh: ";
        cin >> ngsinh.thang;
        cout << "\tNam sinh: ";
        cin >> ngsinh.nam;
        cout << "\tGioi tinh: ";
        cin >> gioitinh;
        cin.ignore();
        cout << "\tHo khau: ";
        getline(cin, hokhau);
        cout << "\tDiem: ";
        cin >> diem;
    }

    void Hienthisv()
    {
        cout << masv;
        cout << "\t" << hodem;
        cout << " " << ten;
        cout << "\t" << ngsinh.ngay;
        cout << "-" << ngsinh.thang;
        cout << "-" << ngsinh.nam;
        cout << "\t" << gioitinh;
        cout << "\t" << hokhau;
        cout << "\t" << diem;
    }
};
void Nhapds(SV *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cua sv thu " << i + 1 << " :" << endl;
        p->Nhapsv();
        p++;
    }
}
void Hienthids(SV *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p->Hienthisv();
        p++;
        cout << "\n";
    }
}
void Sapxep(SV *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if ((p + i)->diem > (p + j)->diem)
            {
                SV tmp = *(p + j);
                *(p + j) = *(p + i);
                *(p + i) = tmp;
            }
    }
}
int main()
{
    SV *p;
    int n;
    do
    {
        cout << "Nhap vao so sv: ";
        cin >> n;
    } while (n < 0 || n > 10);
    p = new SV[n];
    cout << "Nhap vao thong tin " << n << " sv: " << endl;
    Nhapds(p, n);
    cout << "Hien thi thong tin vua nhap: " << endl;
    Hienthids(p, n);
    cout << "\nDanh sach sau khi sap xep la: " << endl;
    Sapxep(p, n);
    Hienthids(p, n);
    delete[] p;
    return 0;
}