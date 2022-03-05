#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien
{
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien A[MAXN - 1], int &n)
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, 100);
        cin.getline(A[i].NgaySinh, 12);
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        cin.ignore();
    }
}
void Nhap(SinhVien &sv)
{
    cin.getline(sv.MASV, 10);
    cin.getline(sv.HoTen, 100);
    cin.getline(sv.NgaySinh, 12);
    cin >> sv.GioiTinh;
    cin >> sv.DiemToan >> sv.DiemLy >> sv.DiemHoa;
    cin.ignore();
}
void Chen(SinhVien A[MAXN - 1], int &n, SinhVien sv)
{
    n++;
    if (n == 1)
        A[0] = sv;
    else
    {
        int i = 0;
        while (true)
        {
            if (strcmp(sv.MASV, A[i].MASV) > 0)
            {
                for (int j = n - 1; j > i; j--)
                    A[j] = A[j - 1];
                A[i] = sv;
                return;
            }
            else if (i == n - 1)
            {
                A[n - 1] = sv;
                return;
            }
            i++;
        }
    }
}
void Xuat(SinhVien A[MAXN - 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i].MASV << "\t" << A[i].HoTen << "\t" << A[i].NgaySinh
             << "\t" << A[i].GioiTinh << "\t" << A[i].DiemToan
             << "\t" << A[i].DiemLy << "\t" << A[i].DiemHoa << "\t";
        cout << setprecision(3) << (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3 << endl;
    }
}
int main()
{
    SinhVien A[MAXN - 1], sv;
    int n;
    Nhap(A, n);
    Nhap(sv);
    Chen(A, n, sv);
    Xuat(A, n);
    return 0;
}