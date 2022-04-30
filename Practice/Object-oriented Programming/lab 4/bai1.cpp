#include <iostream>
#include <string.h>

using namespace std;

class Ngay
{
    friend class Nguoi;

private:
    int ngay, thang, nam;

public:
    Ngay(int, int, int);
    friend istream &operator>>(istream &, Ngay &);
    friend ostream &operator<<(ostream &, const Ngay &);
};

class Nguoi
{
protected:
    char hoten[100];
    Ngay ngaysinh;
    char quequan[100];

public:
    Nguoi(const char *, Ngay, const char *);

    friend istream &operator>>(istream &, Nguoi &);
    friend ostream &operator<<(ostream &, const Nguoi &);
};

int main()
{
    return 0;
}

Ngay::Ngay(int a, int b, int c) : ngay(a), thang(b), nam(c){};

Nguoi::Nguoi(const char *h, Ngay ng, const char *q) : ngaysinh(ng)
{
    memcpy(hoten, h, strlen(h));
    memcpy(quequan, q, strlen(q));
}