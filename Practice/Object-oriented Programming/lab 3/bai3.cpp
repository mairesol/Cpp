#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#include <iostream>

using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double = 0, double = 0);
    void thay_doi(double, double);
    double getx();
    double gety();
    Diem tinh_tien(double, double);
    Diem quay(Diem, double);
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
};

class DaGiac
{
private:
    vector<Diem> vect;

public:
    DaGiac(vector<Diem> dvect = vector<Diem>(0));
    ~DaGiac();
    DaGiac tinh_tien(double, double);
    DaGiac quay(Diem, double);
    DaGiac thay_doi_kich_thuoc(double);
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
Diem Diem::tinh_tien(double a, double b)
{
    x += a;
    y += b;
    return *this;
}
Diem Diem::quay(Diem I, double goc)
{
    x = (x - I.x) * cos(goc) - (y - I.y) * sin(goc) + I.x;
    y = (x - I.x) * sin(goc) + (y - I.y) * cos(goc) + I.y;
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
DaGiac::DaGiac(vector<Diem> dvect)
{
    vect = dvect;
}
DaGiac::~DaGiac()
{
    vect.clear();
}
void DaGiac::nhap()
{
    cout << "Nhap so dinh cua da giac: ";
    int s;
    cin >> s;
    vect.resize(s);
    for (int i = 0; i < vect.size(); i++)
    {
        cout << "Nhap dinh thu " << i + 1 << ": ";
        cin >> vect[i];
    }
}
void DaGiac::xuat()
{
    cout << "Da giac tao boi " << vect.size() << " diem: ";
    for (int i = 0; i < vect.size() - 1; i++)
    {
        cout << vect[i] << ",";
    }
    cout << vect[vect.size() - 1] << "." << endl;
}
DaGiac DaGiac::tinh_tien(double a, double b)
{
    for (int i = 0; i < vect.size(); i++)
        vect[i].tinh_tien(a, b);
    return *this;
}
DaGiac DaGiac::quay(Diem I, double goc)
{
    for (int i = 0; i < vect.size(); i++)
        vect[i].quay(I, goc);
    return *this;
}
DaGiac DaGiac::thay_doi_kich_thuoc(double k)
{
    for (int i = 0; i < vect.size(); i++)
        vect[i].thay_doi(vect[i].getx() * k, vect[i].gety() * k);
    return *this;
}