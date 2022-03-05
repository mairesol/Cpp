#include <iostream>
using namespace std;
int demSochuso(int n)
{
    if (n == 0)
        return 0;
    else if (n > 0 && n <= 9)
        return 1;
    else
        return (demSochuso(n / 10) + 1);
}
int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
        return power(a, b - 1) * a;
}
int tongchuso(long long n)
{
    int thutu = demSochuso(n) - 1;
    if (thutu == -1)
        return 0;
    else
        return n / power(10, thutu) + tongchuso(n % power(10, thutu));
}
int largest_sum_of_digits(int n)
{
    long long t;
    cin >> t;
    int max = 0;
    if (n - 1 > 0)
    {
        long long save = largest_sum_of_digits(n - 1);
        if (tongchuso(t) >= tongchuso(save)) // Nếu bằng thì lấy con số được nhập trước
            max = t;
        else
            max = save;
        return max;
    }
    else
        return t; // Trường hợp cơ bản
}

int main()
{
    int n;
    cin >> n;
    cout << largest_sum_of_digits(n);
}