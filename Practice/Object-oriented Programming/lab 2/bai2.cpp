#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double thuc, ao;

public:
    SoPhuc(double = 0, double = 0);
    ~SoPhuc() {}

    SoPhuc cong(const SoPhuc &);
    SoPhuc tru(const SoPhuc &);
    SoPhuc nhan(const SoPhuc &);
    SoPhuc chia(const SoPhuc &);

    void nhap();
    void xuat();
    void dinh_gia_tri(double, double);
};

int main()
{
    SoPhuc p, p1, p2;
    cout << "Nhap so phuc thu nhat: ";
    p1.nhap();
    cout << "Nhap so phuc thu hai: ";
    p2.nhap();

    p = p1.cong(p2);
    cout << "\nTong cua 2 so phuc: ";
    p.xuat();

    p = p1.tru(p2);
    cout << "\nHieu cua 2 so phuc: ";
    p.xuat();

    p = p1.nhan(p2);
    cout << "\nTich cua 2 so phuc: ";
    p.xuat();

    p = p1.chia(p2);
    cout << "\nThuong cua 2 so phuc: ";
    p.xuat();
    return 0;
}
SoPhuc::SoPhuc(double t, double a)
{
    thuc = t;
    ao = a;
}
SoPhuc SoPhuc::cong(const SoPhuc &b)
{
    return SoPhuc(thuc + b.thuc, ao + b.ao);
}
SoPhuc SoPhuc::tru(const SoPhuc &b)
{
    return SoPhuc(thuc - b.thuc, ao - b.ao);
}
SoPhuc SoPhuc::nhan(const SoPhuc &b)
{
    return SoPhuc(thuc * b.thuc - ao * b.ao, thuc * b.ao + ao * b.thuc);
}
SoPhuc SoPhuc::chia(const SoPhuc &b)
{
    return SoPhuc((thuc * b.thuc + ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao), (b.thuc * ao - thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao));
}

void SoPhuc::nhap()
{
    cin >> thuc >> ao;
}
void SoPhuc::xuat()
{
    if (thuc == 0 && ao == 0)
        cout << 0;
    else if (ao == 0)
        cout << thuc;
    else if (thuc == 0)
        cout << ao << "i";
    else
        cout << thuc << " + " << ao << "i";
}