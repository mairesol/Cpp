#include <iostream>
#include <math.h>
typedef unsigned long long ull;
using namespace std;

ull sumdigit(ull n)
{
    if (n == 0)
        return 0;
    else
        return n % 10 + sumdigit(n / 10);
}
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

int main()
{
    ull number;
    cin >> number;
    int sum_digit = sumdigit(number);
    int index = log10(number); // Index các kí số
    while (index >= 0)
    {
        int digit = before(number, index) % 10; // Lấy kí số cuối cùngg
        int remain = (sum_digit - digit) % 3;   // Lấy phần dư khi không có số bị chọn
        int goal = 9 - remain;
        if (goal > digit)
        {
            cout << before(number, index + 1) * pow(10, index + 1) + goal * pow(10, index) + after(number, index);
            return 0; // Hoàn thành đổi 1 kí số
        }
        else
            index--;
    }
    do
    {
        number--;
    } while (number % 3 != 0);
    cout << number;
    return 0;
}