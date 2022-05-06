#include <iostream>
#include <string>

using namespace std;

int menu();
bool menu_yet = false;

class Ngay
{
private:
    int ngay, thang, nam;

public:
    Ngay(int = 0, int = 0, int = 0);

    friend istream &operator>>(istream &, Ngay &);
    friend ostream &operator<<(ostream &, const Ngay &);
};

class Nguoi
{
private:
    string hoten;
    Ngay ngaysinh;
    string quequan;

public:
    Nguoi(string = "", Ngay = Ngay(0, 0, 0), string = "");
    Nguoi(const char *, Ngay, const char *);

    void input();
    void output();
};

class SinhVien : public Nguoi
{
protected:
    string mssv;
    string lop;
    string sdt;
    string truong;
    string chuyen_nganh;

public:
    SinhVien(string = "", Ngay = Ngay(0, 0, 0), string = "", string = "", string = "", string = "", string = "", string = "");
    SinhVien(const char *, Ngay, const char *, const char *, const char *, const char *, const char *, const char *);

    void input();
    void output();
};
class HocSinh : public SinhVien
{
public:
    HocSinh(string = "", Ngay = Ngay(0, 0, 0), string = "", string = "", string = "", string = "");
    HocSinh(const char *, Ngay, const char *, const char *, const char *, const char *);

    void input();
    void output();
};

class CongNhan : public Nguoi
{
protected:
    string noi_lam_viec;
    unsigned long long luong;

public:
    CongNhan(string = "", Ngay = Ngay(0, 0, 0), string = "", string = "", unsigned long long = 0);
    CongNhan(const char *, Ngay, const char *, const char *, unsigned long long);

    void input();
    void output();
};

class NgheSi : public Nguoi
{
protected:
    string loai_hinh_nghe_thuat;
    unsigned long long tuoi_nghe;

public:
    NgheSi(string = "", Ngay = Ngay(0, 0, 0), string = "", string = "", unsigned long long = 0);
    NgheSi(const char *, Ngay, const char *, const char *, unsigned long long);

    void input();
    void output();
};

class CaSi : public Nguoi
{
protected:
    string dong_nhac;
    unsigned long long tuoi_nghe;

public:
    CaSi(string = "", Ngay = Ngay(0, 0, 0), string = "", string = "", unsigned long long = 0);
    CaSi(const char *, Ngay, const char *, const char *, unsigned long long);

    void input();
    void output();
};
int main()
{
    int choice;
    bool flag = true;
    SinhVien a;
    HocSinh b;
    CongNhan c;
    NgheSi d;
    CaSi e;
    while (flag)
    {
        choice = menu();
        cin.ignore(256, '\n');
        switch (choice)
        {
        case 1:
            a.input();
            a.output();
            break;
        case 2:
            b.input();
            b.output();
            break;
        case 3:
            c.input();
            c.output();
            break;
        case 4:
            d.input();
            d.output();
            break;
        case 5:
            e.input();
            e.output();
            break;
        case 6:
            ::menu_yet = false;
            break;
        case 7:
            cout << "Chuong trinh ngung hoat dong.\n";
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac doi tuong sau:";
        cout << "\n 1. Sinh vien.";
        cout << "\n 2. Hoc sinh.";
        cout << "\n 3. Cong nhan.";
        cout << "\n 4. Nghe si.";
        cout << "\n 5. Ca si.";
        cout << "\n 6. Xem lai menu.";
        cout << "\n 7. Thoat chuong trinh.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}

/*--------------------------------Ngay--------------------------------*/
Ngay::Ngay(int a, int b, int c) : ngay(a), thang(b), nam(c){};
istream &operator>>(istream &is, Ngay &obj)
{
    is >> obj.ngay >> obj.thang >> obj.nam;
    return is;
}
ostream &operator<<(ostream &os, const Ngay &obj)
{
    os << obj.ngay << "/" << obj.thang << "/" << obj.nam;
    return os;
}

/*--------------------------------Nguoi--------------------------------*/
Nguoi::Nguoi(string h, Ngay ng, string q) : hoten(h), ngaysinh(ng), quequan(q){};
Nguoi::Nguoi(const char *h, Ngay ng, const char *q) : hoten(h), ngaysinh(ng), quequan(q){};

void Nguoi::input()
{
    cout << "\nHo ten: ";
    getline(cin, hoten);
    cout << "\nNgay sinh: ";
    cin >> ngaysinh;
    cin.ignore(256, '\n');
    cout << "\nQue quan: ";
    getline(cin, quequan);
}
void Nguoi::output()
{
    cout << "\nHo ten: " << hoten;
    cout << "\nNgay sinh: " << ngaysinh;
    cout << "\nQue quan: " << quequan;
}

/*--------------------------------SinhVien--------------------------------*/
SinhVien::SinhVien(string h, Ngay ng, string q, string m, string l, string s, string t, string c) : Nguoi(h, ng, q)
{
    mssv = m;
    lop = l;
    sdt = s;
    truong = t;
    chuyen_nganh = c;
};
SinhVien::SinhVien(const char *h, Ngay ng, const char *q, const char *m, const char *l, const char *s, const char *t, const char *c) : Nguoi(h, ng, q)
{
    mssv = m;
    lop = l;
    sdt = s;
    truong = t;
    chuyen_nganh = c;
};

void SinhVien::input()
{
    cout << "\nNhap thong tin sinh vien:";
    Nguoi::input();
    cout << "\nMssv: ";
    getline(cin, mssv);
    cout << "\nLop: ";
    getline(cin, lop);
    cout << "\nSo dien thoai: ";
    getline(cin, sdt);
    cout << "\nTruong: ";
    getline(cin, truong);
    cout << "\nChuyen nganh: ";
    getline(cin, chuyen_nganh);
}
void SinhVien::output()
{
    cout << "\nIn thong tin sinh vien:";
    Nguoi::output();
    cout << "\nMssv: " << mssv;
    cout << "\nLop: " << lop;
    cout << "\nSo dien thoai: " << sdt;
    cout << "\nTruong: " << truong;
    cout << "\nChuyen nganh: " << chuyen_nganh;
}

/*--------------------------------HocSinh--------------------------------*/
HocSinh::HocSinh(string h, Ngay ng, string q, string l, string s, string t) : SinhVien(h, ng, q, string(""), l, s, t, string("")){};
HocSinh::HocSinh(const char *h, Ngay ng, const char *q, const char *l, const char *s, const char *t) : SinhVien(h, ng, q, "", l, s, t, ""){};

void HocSinh::input()
{
    cout << "\nNhap thong tin hoc sinh:";
    Nguoi::input();
    cout << "\nLop: ";
    getline(cin, lop);
    cout << "\nSo dien thoai: ";
    getline(cin, sdt);
    cout << "\nTruong: ";
    getline(cin, truong);
}
void HocSinh::output()
{
    cout << "\nIn thong tin hoc sinh:";
    Nguoi::output();
    cout << "\nLop: " << lop;
    cout << "\nSo dien thoai: " << sdt;
    cout << "\nTruong: " << truong;
}

/*--------------------------------CongNhan--------------------------------*/
CongNhan::CongNhan(string h, Ngay ng, string q, string n, unsigned long long l) : Nguoi(h, ng, q), noi_lam_viec(n), luong(l){};
CongNhan::CongNhan(const char *h, Ngay ng, const char *q, const char *n, unsigned long long l) : Nguoi(h, ng, q), noi_lam_viec(n), luong(l){};

void CongNhan::input()
{
    cout << "\nNhap thong tin cong nhan:";
    Nguoi::input();
    cout << "\nNoi lam viec: ";
    getline(cin, noi_lam_viec);
    cout << "\nLuong: ";
    cin >> luong;
}
void CongNhan::output()
{
    cout << "\nIn thong tin cong nhan:";
    Nguoi::output();
    cout << "\nNoi lam viec: " << noi_lam_viec;
    cout << "\nLuong: " << luong;
}

/*--------------------------------NgheSi--------------------------------*/
NgheSi::NgheSi(string h, Ngay ng, string q, string l, unsigned long long t) : Nguoi(h, ng, q), loai_hinh_nghe_thuat(l), tuoi_nghe(t){};
NgheSi::NgheSi(const char *h, Ngay ng, const char *q, const char *l, unsigned long long t) : Nguoi(h, ng, q), loai_hinh_nghe_thuat(l), tuoi_nghe(t){};

void NgheSi::input()
{
    cout << "\nNhap thong tin nghe si:";
    Nguoi::input();
    cout << "\nLoai hinh nghe thuat: ";
    getline(cin, loai_hinh_nghe_thuat);
    cout << "\nTuoi nghe: ";
    cin >> tuoi_nghe;
}
void NgheSi::output()
{
    cout << "\nIn thong tin nghe si:";
    Nguoi::output();
    cout << "\nLoai hinh nghe thuat: " << loai_hinh_nghe_thuat;
    cout << "\nTuoi nghe: " << tuoi_nghe;
}

/*--------------------------------NgheSi--------------------------------*/
CaSi::CaSi(string h, Ngay ng, string q, string d, unsigned long long t) : Nguoi(h, ng, q), dong_nhac(d), tuoi_nghe(t){};
CaSi::CaSi(const char *h, Ngay ng, const char *q, const char *d, unsigned long long t) : Nguoi(h, ng, q), dong_nhac(d), tuoi_nghe(t){};

void CaSi::input()
{
    cout << "\nNhap thong tin ca si:";
    Nguoi::input();
    cout << "\nDong nhac: ";
    getline(cin, dong_nhac);
    cout << "\nTuoi nghe: ";
    cin >> tuoi_nghe;
}
void CaSi::output()
{
    cout << "\nIn thong tin ca si:";
    Nguoi::output();
    cout << "\nDong nhac: " << dong_nhac;
    cout << "\nTuoi nghe: " << tuoi_nghe;
}