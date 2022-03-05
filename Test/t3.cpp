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
    cin.ignore(256, 10);
    for (int i = 0; i < n; i++)
    {
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, 100);
        cin.getline(A[i].NgaySinh, 12);
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        cin.ignore(256, 10);
    }
}
void Nhap(SinhVien &sv)
{
    cin.getline(sv.MASV, 10);
    cin.getline(sv.HoTen, 100);
    cin.getline(sv.NgaySinh, 12);
    cin >> sv.GioiTinh;
    cin >> sv.DiemToan >> sv.DiemLy >> sv.DiemHoa;
    cin.ignore(256, 10);
}
void Chen(SinhVien A[MAXN - 1], int &n, SinhVien sv)
{
    if (n == 0)
    {
        A[0] = sv;
        n++;
    }
    else
        for (int i = n - 1; i >= 0; i--)
        {
            if (strcmp(sv.MASV, A[i].MASV) < 0)
            {
                for (int j = n; j > i + 1; j--)
                    A[j] = A[j - 1];
                A[i + 1] = sv;
                n++;
                return;
            }
            else if (i == 0)
            {
                for (int j = n; j > 0; j--)
                    A[j] = A[j - 1];
                A[0] = sv;
                n++;
                return;
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