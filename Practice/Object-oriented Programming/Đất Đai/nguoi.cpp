#include <iostream>
#include <string>

#include "nguoi.h"

using namespace std;

// Nguoi
void Nguoi::nhap()
{
    cout << "\nTen: ";
    getline(cin, ten);
    cout << "\nNam sinh: ";
    cin >> nam_sinh;
    cin.ignore(256, '\n');
    cout << "\nCMND: ";
    cin >> CMND;
    cin.ignore(256, '\n');
    cout << "\nDia chi thuong tru: ";
    getline(cin, dia_chi_thuong_tru);
}

void Nguoi::xuat()
{
    cout << "\nTen: " << ten;
    cout << "\nNam sinh: " << nam_sinh;
    cout << "\nCMND: " << CMND;
    cout << "\nDia chi thuong tru: " << dia_chi_thuong_tru;
}