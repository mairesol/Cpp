// Tinh can bac 2 cua a voi do chinh xac b chu so thap phan ( xn+1 = 1 / 2 * ( xn + S / xn ))
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    float num = a - 1;
    float decimal_round = pow(10, -b);
    while ((pow(num, 2) < a - decimal_round) || (pow(num, 2) > a + decimal_round))
    {
        num = (num + a / num) / 2;
    }
    cout << num << endl;
    return 0;
}