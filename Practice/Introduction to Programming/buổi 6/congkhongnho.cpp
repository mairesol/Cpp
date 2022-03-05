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
int congdonvikhongnho(int a, int b)
{
    return (a + b) % 10;
}
int sum_without_remember(int param1, int param2)
{
    if (param1 == 0 && param2 == 0)
        return 0;
    int thutu1 = demSochuso(param1) - 1;
    int thutu2 = demSochuso(param2) - 1;
    int thutumax = (thutu1 > thutu2) ? thutu1 : thutu2; // Đệ quy theo số nhiều chữ số nhất
    int ketquatheocot = congdonvikhongnho(param1 / power(10, thutumax), param2 / power(10, thutumax));
    return ketquatheocot * power(10, thutumax) + sum_without_remember(param1 % power(10, thutumax), param2 % power(10, thutumax));
}
int main()
{
    int param1, param2;
    cin >> param1 >> param2;
    cout << sum_without_remember(param1, param2);
}