#include <iostream>
#include <algorithm>
using namespace std;

long long UCLN(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return UCLN(b, a % b);
}

struct Time
{
    int hour, minute, second;
};

int main()
{
    Time film, binh;
    cin >> film.hour >> film.minute >> film.second;
    cin >> binh.hour >> binh.minute >> binh.second;
    int mau = film.hour * 3600 + film.minute * 60 + film.second, tu = binh.hour * 3600 + binh.minute * 60 + binh.second;
    int temp;
    while (UCLN(tu, mau) > 1)
    {
        temp = tu;
        tu /= UCLN(tu, mau);
        mau /= UCLN(temp, mau);
    }
    cout << tu << " " << mau;
    return 0;
}