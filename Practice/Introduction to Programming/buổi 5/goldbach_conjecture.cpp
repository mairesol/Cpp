#include <iostream>
using namespace std;
bool KTSNT(int x)
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
    int number;
    cin >> number;
    int cnt = 0;
    for (int i = 2; i <= number / 2; i++)
    {
        if (KTSNT(i) == true && KTSNT(number - i) == true)
            cnt++;
    }
    cout << cnt;
    return 0;
}
