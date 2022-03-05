#include <iostream>
typedef unsigned long long ull;
using namespace std;
int count(int number)
{
    int count = 0;
    do
    {
        number = number / 10;
        count += 1;
    } while (number != 0);
    return count;
}

ull power(int num, int exponent)
{
    ull kq = 1;
    while (exponent != 0)
    {
        kq *= num;
        exponent--;
    }
    return kq;
}
int reverse(int number, int count)
{
    int reverse = 0;
    for (int i = 1; i <= count; i++)
    {
        reverse += (number % 10) * power(10, count - i);
        number = number / 10;
    }
    return reverse;
}

bool KTSNT(ull x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    ull a, b;
    cin >> a >> b;
    ull cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (KTSNT(i) == true && KTSNT(reverse(i, count(i))) == true)
            cnt++;
    }
    cout << cnt;
    return 0;
}