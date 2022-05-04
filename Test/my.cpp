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
        A[i].keu();
        cout << "\t";
    }
    for (int i = 0; i < b; i++)
    {
        B[i].keu();
        cout << "\t";
    }
    for (int i = 0; i < c; i++)
    {
        C[i].keu();
        cout << "\t";
    }
    return 0;
}
/*--------------------------------GiaSuc--------------------------------*/

/*--------------------------------Bo--------------------------------*/
void Bo::keu()
{
    cout << "*moo moo*";
}
/*--------------------------------Cuu--------------------------------*/
void Cuu::keu()
{
    cout << "*baa baa*";
}

/*--------------------------------De--------------------------------*/
void De::keu()
{
    cout << "*baa baa*";
}
