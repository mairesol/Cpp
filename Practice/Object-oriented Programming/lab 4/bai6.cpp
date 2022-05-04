#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class GiaSuc
{
public:
    int sinh_con();
};

class Bo : public GiaSuc
{
public:
    void keu();
};

class Cuu : public GiaSuc
{
public:
    void keu();
};

class De : public GiaSuc
{
public:
    void keu();
};

int main()
{
    int a, b, c;
    cout << "Nhap so luong bo: ";
    cin >> a;
    Bo *A = new Bo[a];

    cout << "Nhap so luong cuu: ";
    cin >> b;
    Cuu *B = new Cuu[b];

    cout << "Nhap so luong de: ";
    cin >> c;
    De *C = new De[c];

    for (int i = 0; i < a; i++)
    {
        cout << "\t";
        A[i].keu();
    }
    for (int i = 0; i < a; i++)
    {
        cout << "\t";
        B[i].keu();
    }
    for (int i = 0; i < a; i++)
    {
        cout << "\t";
        C[i].keu();
    }
    return 0;
}
/*--------------------------------GiaSuc--------------------------------*/

/*--------------------------------Bo--------------------------------*/
void Bo::keu()
{
    cout << "moo moo";
}
/*--------------------------------Cuu--------------------------------*/
void Cuu::keu()
{
    cout << "baa baa";
}

/*--------------------------------De--------------------------------*/
void De::keu()
{
    cout << "baa baa";
}
