#include <iostream>
#include <math.h>

using namespace std;

#include <iostream>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(int dx = 0, int dy = 0)
    {
        x = dx;
        y = dy;
    }
    ~Diem() {}
    Diem tinh_tien(int, int);
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
};

class TamGiac
{
private:
    Diem A, B, C;

public:
    TamGiac()
    {
        A = Diem(0, 0);
        B = Diem(0, 0);
        C = Diem(0, 0);
    }
    TamGiac(Diem da, Diem db, Diem dc)
    {
        A = da;
        B = db;
        C = dc;
    }
    ~TamGiac() {}
    void nhap()
    {
        cout << "Nhap diem thu nhat: ";
        cin >> A;
        cout << "Nhap diem thu hai: ";
        cin >> B;
        cout << "Nhap diem thu ba: ";
        cin >> C;
    }
    void xuat()
    {
        cout << "Tam giac: "
             << "{" << A << "," << B << "<" << C << "}" << endl;
    }
    TamGiac tinh_tien(int a, int b)
    {
        A.tinh_tien(a, b);
        B.tinh_tien(a, b);
        C.tinh_tien(a, b);
        return *this;
    }
};

int main()
{
    TamGiac A;
    A.nhap();
    A.xuat();
    return 0;
}

Diem Diem::tinh_tien(int a, int b)
{
    x += a;
    y += b;
    return *this;
}
istream &operator>>(istream &is, Diem &obj)
{
    is >> obj.x >> obj.y;
    return is;
}
ostream &operator<<(ostream &os, const Diem &obj)
{
    cout << "(" << obj.x << ";" << obj.y << ")";
    return os;
}