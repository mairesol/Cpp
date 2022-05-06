#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define chan_duoi_sinh_san 1
#define chan_tren_sinh_san 4

#define chan_duoi_sua 0
#define chan_tren_sua_bo 20
#define chan_tren_sua_cuu 5
#define chan_tren_sua_de 10

typedef unsigned long long ull;

ull random(ull, ull);
class GiaSuc
{
private:
public:
    ull so_luong;

    void keu();
    ull sinh_con();
    ull cho_sua();
};

class Bo : public GiaSuc
{
private:
public:
    void keu();
    ull cho_sua();
};

class Cuu : public GiaSuc
{
private:
public:
    void keu();
    ull cho_sua();
};

class De : public GiaSuc
{
private:
public:
    void keu();
    ull cho_sua();
};

int main()
{
    srand(time(NULL));
    Bo a;
    Cuu b;
    De c;
    cout << "Nhap so luong bo: ";
    cin >> a.so_luong;

    cout << "Nhap so luong cuu: ";
    cin >> b.so_luong;

    cout << "Nhap so luong de: ";
    cin >> c.so_luong;

    cout << "\n\nTieng keu trong nong trai:";
    cout << "\nBo keu: ";
    for (ull i = 1; i <= a.so_luong; i++)
    {
        a.keu();
        cout << " ";
    }

    cout << "\nCuu keu: ";
    for (ull i = 1; i <= b.so_luong; i++)
    {
        b.keu();
        cout << " ";
    }

    cout << "\nDe keu: ";
    for (ull i = 1; i <= c.so_luong; i++)
    {
        c.keu();
        cout << " ";
    }

    char choice;
    bool flag = true;
    while (flag)
    {
        cout << "\n\nBan co muon xem thong tin sau 1 lua sinh moi: y(chap nhan)/n(tu choi) ";
        cin >> choice;
        switch (choice)
        {
        case 'y':
        case 'Y':
            cout << "\nTong so lit sua: " << a.cho_sua() + b.cho_sua() + c.cho_sua();

            cout << "\nSo luong gia suc cac loai: ";
            cout << "\n- Bo: ";
            a.so_luong += a.sinh_con();
            cout << a.so_luong;

            cout << "\n- Cuu: ";
            b.so_luong += b.sinh_con();
            cout << b.so_luong;

            cout << "\n- De: ";
            c.so_luong += c.sinh_con();
            cout << c.so_luong;
            break;

        case 'n':
        case 'N':
            cout << "\nChuong trinh ngung hoat dong.\n";
            flag = false;
            break;

        default:
            cout << "\nLua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}
ull random(ull minN, ull maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

/*--------------------------------GiaSuc--------------------------------*/
ull GiaSuc::sinh_con()
{
    ull sa = 0;
    for (ull i = 1; i <= so_luong; i++)
        sa += random(chan_duoi_sinh_san, chan_tren_sinh_san);
    return sa;
}

/*--------------------------------Bo--------------------------------*/
void Bo::keu()
{
    cout << "*moo moo*";
}
ull Bo::cho_sua()
{
    ull sa = 0;
    for (ull i = 1; i <= so_luong; i++)
        sa += random(chan_duoi_sua, chan_tren_sua_bo);
    return sa;
}

/*--------------------------------Cuu--------------------------------*/
void Cuu::keu()
{
    cout << "*baa baa*";
}
ull Cuu::cho_sua()
{
    ull sa = 0;
    for (ull i = 1; i <= so_luong; i++)
        sa += random(chan_duoi_sua, chan_tren_sua_cuu);
    return sa;
}

/*--------------------------------De--------------------------------*/
void De::keu()
{
    cout << "*maa maa*";
}
ull De::cho_sua()
{
    ull sa = 0;
    for (ull i = 1; i <= so_luong; i++)
        sa += random(chan_duoi_sua, chan_tren_sua_de);
    return sa;
}