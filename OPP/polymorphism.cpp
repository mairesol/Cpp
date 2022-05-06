#include <iostream>
using namespace std;

#include <vector>
#include <string>

class NhanVien
{
protected:
    string hoTen;
    float luong;

public:
    NhanVien()
    {
        hoTen = "";
        luong = 0.0;
    }

    virtual void nhap()
    {
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
    }

    virtual void xuat()
    {
        cout << "Ho ten: ";
        cout << hoTen << endl;
    }

    virtual void tinhLuong() = 0;
};

class NhanVienSanXuat : public NhanVien
{
private:
    int soSanPham;
    float tienCong1SP;

public:
    NhanVienSanXuat() : NhanVien()
    {
        soSanPham = 0;
        tienCong1SP = 0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "So san pham: ";
        cin >> soSanPham;
        cout << "Tien cong 1 san pham: ";
        cin >> tienCong1SP;
    }

    void xuat()
    {
        cout << "So san pham: ";
        cout << soSanPham << endl;
        cout << "Tien cong 1 san pham: ";
        cout << tienCong1SP << endl;
        cout << "Luong: ";
        cout << luong << endl;
    }

    void tinhLuong()
    {
        luong = soSanPham * tienCong1SP;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    float luongCoBan;
    int soNgayLamViec;

public:
    NhanVienVanPhong() : NhanVien()
    {
        luongCoBan = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban: ";
        cin >> luongCoBan;
        cout << "So ngay lam viec: ";
        cin >> soNgayLamViec;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban: ";
        cout << luongCoBan << endl;
        cout << "So ngay lam viec: ";
        cout << soNgayLamViec << endl;
        cout << "Luong: ";
        cout << luong << endl;
    }

    void tinhLuong()
    {
        luong = soNgayLamViec * luongCoBan;
    }
};

class CongTy
{
private:
    vector<NhanVien *> NV;

public:
    void nhap()
    {
        cout << "Nhap so nhan vien: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhan vien van phong (1), nhan vien san xuat (2): ";
            int k;
            cin >> k;
            NhanVien *nv;
            // Tùy vào người dùng chọn đối tượng nào để nhập
            if (k == 1)
                nv = new NhanVienVanPhong;
            else
                nv = new NhanVienSanXuat;
            nv->nhap(); // ta sẽ sử dụng hàm nhập của đối tượng mà người dùng chọn
            NV.push_back(nv);
        }
    }

    void xuat()
    {
        cout << "Nhan vien van phong:" << endl;
        for (int i = 0; i < NV.size(); i++)
        {
            cout << "STT:" << i + 1 << endl;
            NV[i]->xuat(); // tùy vào đối tượng là gì mà phương thức xuất sẽ được gọi theo đúng đối tượng đó
        }
    }

    void tinhLuong()
    {
        for (int i = 0; i < NV.size(); i++)
            NV[i]->tinhLuong(); // tùy vào đối tượng là gì mà phương thức tính lương sẽ được gọi theo đúng đối tượng đó
    }
};

int main()
{
    CongTy cty;
    cty.nhap();
    cty.tinhLuong();
    cty.xuat();
    return 0;
}