#include <iostream>
#include <math.h>
using namespace std;
int count_divisors(int N)
{
    int total_divisors = 1;
    for (int i = 2; i * i <= N; i++)
    {
        int cnt = 0; // Đếm thừa số nguyên tố trong N
        while (N % i == 0)
        {
            cnt++;
            N /= i;
        }
        total_divisors *= (cnt + 1);
    }
    if (N > 1)
        total_divisors *= 2; // Thừa số nguyên tố lớn hơn căn bậc 2
    return total_divisors;
}

int main()
{
    long long n;
    cin >> n;
    cout << count_divisors(abs(n));
    return 0;
}
