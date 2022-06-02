#include <iostream>

#include "ban_nhac.h"

using namespace std;

int main()
{
    BanNhac B;
    B.nhap();
    B.xuat();
    cout << B.so_dau_lang_den() << endl;
    NotNhac a = B.cao_do_lon_nhat();
    cout << a;
    return 0;
}