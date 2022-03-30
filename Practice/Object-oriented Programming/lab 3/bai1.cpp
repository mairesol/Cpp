#include <iostream>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double dx = 0, double dy = 0)
    {
        x = dx;
        y = dy;
    }
    ~Diem() {}
    void thay_doi(double, double);
    double getx();
    double gety();
    Diem tinh_tien(double, double);
    void nhap();
    void xuat();
};

int main()
{
    return 0;
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
Diem Diem::tinh_tien(double a, double b)
{
    x += a;
    y += b;
    return *this;
}
void Diem::nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}
void Diem::xuat()
{
    cout << "(" << x << ";" << y << ")";
}