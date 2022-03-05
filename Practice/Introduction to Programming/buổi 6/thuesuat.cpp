#include <iostream>
#include <string>
#include <utility>
typedef long long ll;
typedef double d;
using namespace std;
void nhapmangnguyen(ll I[10000], int a)
{
    for (int i = 0; i < a; i++)
        cin >> I[i];
}
void nhapmangthuc(d F[10000], int b)
{
    for (int i = 0; i < b; i++)
        cin >> F[i];
}
ll tinhtoanthue(ll I[10000], d F[10000], int a, ll thunhapchiuthue)
{
    if (a == 0)
        return 0;
    else if (thunhapchiuthue >= I[a - 1])
        return (thunhapchiuthue - I[a - 1] + 1) * F[a - 1] + tinhtoanthue(I, F, a - 1, I[a - 1] - 1);
    else if (thunhapchiuthue < I[a - 1])
        return tinhtoanthue(I, F, a - 1, thunhapchiuthue);
}
int main()
{
    int n;
    cin >> n; // Số bậc thuế
    ll canduoi[10000];
    d thuesuat[10000];
    nhapmangnguyen(canduoi, n);
    nhapmangthuc(thuesuat, n);
    ll tongthunhap, thunhapmienthue;
    cin >> tongthunhap >> thunhapmienthue;
    ll thunhapchiuthue = tongthunhap - thunhapmienthue;
    if (thunhapchiuthue <= canduoi[0])
        cout << 0;
    else
        cout << tinhtoanthue(canduoi, thuesuat, n, thunhapchiuthue) / 100 / 10 * 10; // Làm tròn tới hàng chục
    return 0;
}
