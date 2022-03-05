#include <iostream>
#include <math.h>
using namespace std;
#define eps 1e-4
int main()
{
    // // Xac dinh ngay thu may trong nam
    // int day, month, year;
    // cout << "Nhap ngay, thang, nam: ";
    // cin >> day >> month >> year;
    // int thu_tu = day;
    // if (month != 1)
    //     for (int i = 1; i < month; i++)
    //     {
    //         switch (i)
    //         {
    //         case 4:
    //         case 6:
    //         case 9:
    //         case 11:
    //             thu_tu += 30;
    //             break;
    //         case 2:
    //             thu_tu += ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
    //             break;
    //         default:
    //             thu_tu += 31;
    //         }
    //     }
    // cout << "Ngay thu " << thu_tu << endl;.
    // Cần có tổng a đồng từ 3 loại giấy bạc 1000 đồng, 2000 đồng, 5000 đồng. Lập chương trình để tìm ra tất cả các phương án có thể.
    // 1000*200; 2000*100; 5000*50
    // long money;
    // cout << "Nhap so tien: ";
    // cin >> money;
    // cout << "Phuong an: ";
    // for (int i = 0; i <= money / 1000; i++)
    // {
    //     if (money >= 2000)
    //         for (int j = 0; j <= money / 2000; j++)
    //         {
    //             if (1000 * i + 2000 * j == money)
    //                 cout << i << "\t" << j << "\t" << 0 << "; ";
    //             else if (money >= 5000)
    //                 for (int k = 0; k <= money / 5000; k++)
    //                 {
    //                     if (1000 * i + 2000 * j + 5000 * k == money)
    //                         cout << i << "\t" << j << "\t" << k << "; ";
    //                 }
    //         }
    //     else if (1000 * i == money)
    //         cout << i << "\t" << 0 << "\t" << 0 << "; ";
    // }
    // Lập chương trình tính sin(x) với độ chính xác 0.00001 theo công thức: Sin(x) = x – x^3/3! + x^5/5! + … + (-1)^n . x^(2n + 1)/(2n + 1)!
    float S, T, x, LuyThua, GiaiThua;
    int Dau = -1;
    cout << "Nhap x(radian): ";
    cin >> x;
    GiaiThua = 1;
    S = T = LuyThua = x;
    for (int i = 3; T > eps; i += 2, Dau = -Dau)
    {
        T = (LuyThua *= x * x) / (GiaiThua *= i * (i - 1));
        S += Dau * T;
    }
    cout << "sin(" << x << ") = " << S << endl;
    return 0;
}
