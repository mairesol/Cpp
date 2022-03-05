#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    double a;
    int n;
    cin >> a >> n;
    double b = static_cast<int>(a * n);
    double c = a * n - b;
    double d = 1, e = 0.5, f = 0;
    if (c >= e && c < d)
        b += d;
    else
        b += f;
    int tu = b - static_cast<float>(n * int(a));
    if (tu != int(f) && tu != n)
        cout << int(b / n) << " " << tu << "/" << n;
    else
        cout << int(b / n);
    return 0;
}