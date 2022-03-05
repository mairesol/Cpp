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
    cout.precision(10);
    cout << b / n;
    return 0;
}