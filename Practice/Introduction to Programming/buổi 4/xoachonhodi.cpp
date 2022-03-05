#include <iostream>
#include <math.h>
typedef unsigned long long ull;
using namespace std;

int before(ull n, int i)
{
    while (i > 0)
    {
        n /= 10;
        i--;
    }
    return n;
}
int after(ull n, int i)
{
    int power = 1;
    while (i > 0)
    {
        power *= 10;
        i--;
    }
    return n % power;
}
ull eliminate(ull n, int i)
{
    return before(n, i + 1) * pow(10, i) + after(n, i);
}

int main()
{
    ull number;
    cin >> number;
    ull min = pow(10, 12);
    int index = log10(number);
    if (number != 0)
    {
        for (int i = 0; i <= index; i++)
        {
            if (eliminate(number, i) < min)
                min = eliminate(number, i);
        }
    }
    else
        min = 0;
    cout << min;
    return 0;
}