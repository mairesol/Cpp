#include <iostream>
#include <limits.h>
typedef unsigned long long ull;
using namespace std;

int main()
{
    ull number;
    cin >> number;
    ull count = 0;
    if (number == 1)
        cout << 0;
    else
        while (true)
        {

            if (number % 2 == 0)
                number /= 2;
            else
                number = number * 3 + 1;
            count++;
            if (number != 1)
                cout << number << " ";
            else
            {
                cout << 1 << endl
                     << count;
                break;
            }
        }
    return 0;
}