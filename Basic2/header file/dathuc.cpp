#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include "dathuc.h"
dathuc::dathuc(int bdt)
{
    bacdathuc = bdt;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = 0;
}
dathuc::dathuc(const dathuc &right)
{
    bacdathuc = right.bacdathuc;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = right.ptr[i];
}
const dathuc &dathuc::operator=(const dathuc &right)
{
    if (*this != right)
    {
        if (bacdathuc != right.bacdathuc)
        {
            delete[] ptr;
            bacdathuc = right.bacdathuc;
            ptr = new int[bacdathuc];
        }
        for (int i = 0; i <= bacdathuc; i++)
            ptr[i] = right.ptr[i];
    }
    return (*this);
}
dathuc dathuc::operator+(const dathuc &add)
{
    int temp;
    temp = ((bacdathuc > add.bacdathuc) ? bacdathuc : add.bacdathuc);
    dathuc d(temp);
    for (int i = 0; i <= temp; i++)
    {
        if (bacdathuc >= i && add.bacdathuc >= i)
            d.ptr[i] = ptr[i] + add.ptr[i];
        else if (add.bacdathuc < i)
            d.ptr[i] = ptr[i];
        else if (bacdathuc < i)
            d.ptr[i] = add.ptr[i];
    }
    while (temp > 0 && d.ptr[temp] == 0)
        temp--;
    d.bacdathuc = temp;
    return d;
}
dathuc dathuc::operator-(const dathuc &sub)
{
    int i;
    int temp = (bacdathuc > sub.bacdathuc) ? bacdathuc : sub.bacdathuc;
    dathuc d(temp);
    for (i = 0; i <= temp; i++)
    {
        if (bacdathuc >= i && sub.bacdathuc >= i)
            d.ptr[i] = ptr[i] - sub.ptr[i];
        else if (sub.bacdathuc < i)
            d.ptr[i] = ptr[i];
        else if (bacdathuc < i)
            d.ptr[i] = sub.ptr[i];
    }
    return d;
}
dathuc dathuc::operator*(const dathuc &nhan)
{
    int temp;
    temp = bacdathuc + nhan.bacdathuc;
    dathuc d(temp);
    for (int i = 0; i <= bacdathuc; i++)
        for (int j = 0; j <= nhan.bacdathuc; j++)
            d.ptr[i + j] = d.ptr[i + j] + ptr[i] * nhan.ptr[j];
    return d;
}
dathuc dathuc::operator/(const dathuc &right)
{
    int temp;
    if (bacdathuc < right.bacdathuc)
        return 0;
    temp = bacdathuc - right.bacdathuc;
    dathuc d(temp);
    dathuc temp1(*this);
    for (int i = bacdathuc; i >= right.bacdathuc; i--, temp--)
    {
        d.ptr[i - right.bacdathuc] = temp1.ptr[i] / right.ptr[right.bacdathuc];
        if (i - 1 >= right.bacdathuc)
        {
            for (int j = i - 1, k = right.bacdathuc - 1; k >= 0; j--, k--)
                temp1.ptr[j] -= d.ptr[i - right.bacdathuc] * right.ptr[k];
        }
    }
    return d;
}
ostream &operator<<(ostream &output, const dathuc &right)
{
    output << "Cac he so : ";
    for (int i = 0; i <= right.bacdathuc; i++)
        output << setw(4) << right.ptr[i];
    return output;
}
istream &operator>>(istream &input, dathuc &right)
{
    cout << " Nhap he so : ";
    for (int i = 0; i <= right.bacdathuc; i++)
        input >> right.ptr[i];
    return input;
}
