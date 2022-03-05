#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull power(ull num, int exponent)
{
    ull kq = 1;
    while (exponent != 0)
    {
        kq *= num;
        exponent--;
    }
    return kq;
}
int count(ull number)
{

    int count = 0;
    do
    {
        number = number / 10;
        count += 1;
    } while (number != 0);
    return count;
}
ull reverse(ull number, ull count)
{
    ull reverse = 0;
    for (int i = 1; i <= count; i++)
    {
        reverse += (number % 10) * power(10, count - i);
        number = number / 10;
    }
    return reverse;
}
void check_reverse(ull number, ull reverse)
{
    if (number == reverse)
        cout << 0;
    else
        cout << 1;
}

int main()
{
    ull number;
    cin >> number;
    check_reverse(number, reverse(number, count(number)));
    return 0;
}
