#include <iostream>
using namespace std;

int sum_of_digits(long long num)
{
    if (num == 0)
        return 0;
    return num % 10 + sum_of_digits(num / 10);
}
int main()
{
    int n;
    cin >> n;
    cout << sum_of_digits(n);
}