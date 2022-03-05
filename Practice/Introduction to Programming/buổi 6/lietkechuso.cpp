/*
MÔ TẢ BÀI TOÁN
Cho một số nguyên x ≥ 0, hãy xuất các chữ số của số đó ra, mỗi chữ số một hàng (xuất theo thứ tự như ví dụ bên dưới).

INPUT
- Một số nguyên x ≥ 0

OUTPUT
Nhiều hàng, mỗi hàng có 1 chữ số
*/
#include <iostream>
using namespace std;
int demSochuso(int n)
{
    if (n >= 0 && n <= 9)
        return 1;
    else
        return (demSochuso(n / 10) + 1);
}
int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
        return power(a, b - 1) * a;
}
void lietke(int n, int thutu)
{
    if (thutu == -1)
        cout << "";
    else
    {
        cout << n / power(10, thutu) << endl;
        lietke(n % power(10, thutu), thutu - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    lietke(n, demSochuso(n) - 1);
    return 0;
}
