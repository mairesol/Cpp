#include <iostream>
#include <math.h>
typedef unsigned long long ull;
using namespace std;

ull before(ull n, int i)
{
    while (i > 0)
    {
        n /= 10;
        i--;
    }
    return n;
}
ull after(ull n, int i)
{
    int power = 1;
    while (i > 0)
    {
        power *= 10;
        i--;
    }
    return n % power;
}
int digit(ull n, int i)
{
    return before(n, i) % 10;
}
int takemid(ull n, int index)
{
    if (index % 2 == 0)
        return digit(n, index / 2);
    else
        return digit(n, index / 2 + 1) * 10 + digit(n, index / 2);
}
int main()
{
    ull n;
    cin >> n;
    int midmax = 0;
    ull need_n;
    while (n--)
    {
        ull number;
        cin >> number;
        int index = log10(number);
        if (takemid(number, index) >= midmax)
        {
            midmax = takemid(number, index);
            need_n = number;
        }
    }
    cout << need_n;
    return 0;
}
