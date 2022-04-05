#include <iostream>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double = 0, double = 0);
    ~Diem() {}
    void thay_doi(double, double);
    double getx();
    double gety();
    void tinh_tien(double, double);
    void nhap();
    void xuat();
};

int main()
{
    return 0;
}
Diem::Diem(double dx, double dy)
{
    x = dx;
    y = dy;
}
void Diem::thay_doi(double dx, double dy)
{
    x = dx;
    y = dy;
}
double Diem::getx()
{
    return x;
}
double Diem::gety()
{
    return y;
}
void Diem::tinh_tien(double a, double b)
{
    x += a;
    y += b;
}
void Diem::nhap()
{
    cin >> x >> y;
}
void Diem::xuat()
{
    cout << "(" << x << ";" << y << ")";
}