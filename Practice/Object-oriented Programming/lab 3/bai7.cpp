#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Dathuc
{
private:
    double *arr;
    int bac;

public:
    Dathuc(int = 0);
    Dathuc(const Dathuc &);
    ~Dathuc();

    Dathuc &operator=(const Dathuc &);
    Dathuc operator+(const Dathuc &);
    Dathuc operator-(const Dathuc &);

    bool operator==(const Dathuc &);
    bool operator!=(const Dathuc &);

    friend istream &operator>>(istream &, Dathuc &);
    friend ostream &operator<<(ostream &, const Dathuc &);
};

int main()
{
    Dathuc a(3), b(3);
    cin >> a >> b;
    cout << a + b << endl;
    cout << a - b;
    return 0;
}

Dathuc::Dathuc(int b)
{
    bac = b;
    arr = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        arr[i] = 0;
}
Dathuc::Dathuc(const Dathuc &obj)
{
    bac = obj.bac;
    arr = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        arr[i] = obj.arr[i];
}
Dathuc::~Dathuc()
{
    delete[] arr;
}

Dathuc &Dathuc::operator=(const Dathuc &obj)
{
    if (bac != obj.bac)
    {
        delete[] arr;
        bac = obj.bac;
        arr = new double[bac + 1];
    }
    for (int i = 0; i <= bac; i++)
        arr[i] = obj.arr[i];
    return *this;
}
Dathuc Dathuc::operator+(const Dathuc &obj)
{
    int bacmoi;
    bacmoi = max(bac, obj.bac);
    Dathuc d(bacmoi);
    for (int i = 0; i <= bacmoi; i++)
    {
        if (i <= bac)
            d.arr[i] += arr[i];
        if (i <= obj.bac)
            d.arr[i] += obj.arr[i];
    }
    while (bacmoi > 0 && d.arr[bacmoi] == 0)
        bacmoi--;
    d.bac = bacmoi;
    return d;
}
Dathuc Dathuc::operator-(const Dathuc &obj)
{
    int bacmoi;
    bacmoi = max(bac, obj.bac);
    Dathuc d(bacmoi);
    for (int i = 0; i <= bacmoi; i++)
    {
        if (i <= bac)
            d.arr[i] += arr[i];
        if (i <= obj.bac)
            d.arr[i] -= obj.arr[i];
    }
    while (bacmoi > 0 && d.arr[bacmoi] == 0)
        bacmoi--;
    d.bac = bacmoi;
    return d;
}

bool Dathuc::operator==(const Dathuc &obj)
{
    if (bac != obj.bac)
        return false;
    for (int i = 0; i <= bac; i++)
        if (arr[i] != obj.arr[i])
            return false;
    return true;
}

bool Dathuc ::operator!=(const Dathuc &obj)
{
    return !(*this == obj);
}

istream &operator>>(istream &is, Dathuc &obj)
{
    for (int i = obj.bac; i >= 0; i--)
        is >> obj.arr[i];
    return is;
}
ostream &operator<<(ostream &os, const Dathuc &obj)
{
    if (obj.arr[obj.bac] != 0)
    {
        if (obj.arr[obj.bac] < 0)
            os << "- ";
        if (abs(obj.arr[obj.bac]) != 1)
            os << abs(obj.arr[obj.bac]);
        if (obj.bac != 0)
            os << "x^" << obj.bac;
    }

    for (int i = obj.bac - 1; i > 0; i--)
    {
        if (obj.arr[i] == 0)
            continue;
        if (obj.arr[i] < 0)
            os << " - ";
        if (obj.arr[i] > 0)
            os << " + ";
        if (abs(obj.arr[i]) != 1)
            os << abs(obj.arr[i]);
        os << "x^" << i;
    }

    if (obj.arr[0] == 0)
        return os;

    if (obj.arr[0] < 0)
        os << " - ";
    if (obj.arr[0] > 0)
        os << " + ";
    os << abs(obj.arr[0]);
    return os;
}