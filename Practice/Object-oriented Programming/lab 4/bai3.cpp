#include <iostream>
#include <algorithm>

using namespace std;

class DaThuc
{
private:
    int *ptr;
    int bacdathuc;

public:
    DaThuc(int = 0);
    DaThuc(const DaThuc &);
    ~DaThuc();

    friend bool operator==(const DaThuc &, const DaThuc &);
    friend bool operator!=(const DaThuc &, const DaThuc &);
    const DaThuc &operator=(const DaThuc &);

    friend DaThuc operator+(const DaThuc &, const DaThuc &);
    friend DaThuc operator-(const DaThuc &, const DaThuc &);
    friend DaThuc operator*(const DaThuc &, const DaThuc &);
    friend DaThuc operator/(const DaThuc &, const DaThuc &);

    friend istream &operator>>(istream &, DaThuc &);
    friend ostream &operator<<(ostream &, const DaThuc &);
};

int main()
{
    return 0;
}
DaThuc::DaThuc(int b)
{
    bacdathuc = b;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = 0;
}
DaThuc::DaThuc(const DaThuc &rhs)
{
    bacdathuc = rhs.bacdathuc;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = rhs.ptr[i];
}
DaThuc::~DaThuc()
{
    delete[] ptr;
}
bool operator==(const DaThuc &lhs, const DaThuc &rhs)
{
    if (lhs.bacdathuc != rhs.bacdathuc)
        return false;
    for (int i = 0; i <= lhs.bacdathuc; i++)
        if (lhs.ptr[i] != rhs.ptr[i])
            return false;
    return true;
}
bool operator!=(const DaThuc &lhs, const DaThuc &rhs)
{
    return !(lhs == rhs);
}
const DaThuc &DaThuc::operator=(const DaThuc &rhs)
{
    if (*this != rhs)
    {
        if (bacdathuc != rhs.bacdathuc)
        {
            delete[] ptr;
            bacdathuc = rhs.bacdathuc;
            ptr = new int[bacdathuc];
        }
        for (int i = 0; i <= bacdathuc; i++)
            ptr[i] = rhs.ptr[i];
    }
    return *this;
}
DaThuc operator+(const DaThuc &lhs, const DaThuc &rhs)
{
    int temp = max(lhs.bacdathuc, rhs.bacdathuc);
    DaThuc result(temp);
    for (int i = 0; i <= temp; i++)
    {
        if (lhs.bacdathuc >= i && rhs.bacdathuc >= i)
            result.ptr[i] = lhs.ptr[i] + rhs.ptr[i];
        else if (rhs.bacdathuc < i)
            result.ptr[i] = lhs.ptr[i];
        else if (lhs.bacdathuc < i)
            result.ptr[i] = rhs.ptr[i];
    }
    while (temp > 0 && result.ptr[temp] == 0)
        temp--;
    result.bacdathuc = temp;
    return result;
}
DaThuc operator-(const DaThuc &lhs, const DaThuc &rhs)
{
    int temp = max(lhs.bacdathuc, rhs.bacdathuc);
    DaThuc result(temp);
    for (int i = 0; i <= temp; i++)
    {
        if (lhs.bacdathuc >= i && rhs.bacdathuc >= i)
            result.ptr[i] = lhs.ptr[i] - rhs.ptr[i];
        else if (rhs.bacdathuc < i)
            result.ptr[i] = lhs.ptr[i];
        else if (lhs.bacdathuc < i)
            result.ptr[i] = -rhs.ptr[i];
    }
    while (temp > 0 && result.ptr[temp] == 0)
        temp--;
    result.bacdathuc = temp;
    return result;
}
DaThuc operator*(const DaThuc &lhs, const DaThuc &rhs)
{
    int temp = lhs.bacdathuc * rhs.bacdathuc;
    DaThuc result(temp);
    for (int i = 0; i <= lhs.bacdathuc; i++)
    {
        for (int j = 0; j <= rhs.bacdathuc; j++)
            result.ptr[i + j] += lhs.ptr[i] * rhs.ptr[j];
    }
    while (temp > 0 && result.ptr[temp] == 0)
        temp--;
    result.bacdathuc = temp;
    return result;
}
DaThuc operator/(const DaThuc &lhs, const DaThuc &rhs)
{
    if (lhs.bacdathuc < lhs.bacdathuc)
        return;
    int temp = lhs.bacdathuc - rhs.bacdathuc;
    DaThuc result(temp);
    DaThuc dtemp(lhs);
    for (int i = lhs.bacdathuc; i >= rhs.bacdathuc; i--, temp--)
    {
        result.ptr[i - rhs.bacdathuc] = dtemp.ptr[i] / rhs.ptr[rhs.bacdathuc];
        if (i - 1 >= rhs.bacdathuc)
        {
            for (int j = i - 1, k = rhs.bacdathuc - 1; k >= 0; j--, k--)
                dtemp.ptr[j] -= result.ptr[i - rhs.bacdathuc] * rhs.ptr[k];
        }
    }
    while (temp > 0 && result.ptr[temp] == 0)
        temp--;
    result.bacdathuc = temp;
    return result;
}
istream &operator>>(istream &is, DaThuc &obj)
{
    for (int i = 0; i <= obj.bacdathuc; i++)
        is >> obj.ptr[i];
    return is;
}
ostream &operator<<(ostream &os, const DaThuc &obj)
{
    for (int i = 0; i <= obj.bacdathuc; i++)
        os << obj.ptr[i] << "\t";
    return os;
}