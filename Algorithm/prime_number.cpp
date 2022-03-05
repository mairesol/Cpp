// prime number = 6k +- 1
#include <iostream>
using namespace std;

bool isPrimeNumber(long long number)
{
    if (number <= 4 && number > 0)
        if ((number % 2 == 0 || number % 3 == 0) && number != 4)
            return true;
        else
            return false;
    else
    {
        for (long i = 1; i * i <= number; i++)
        {
            if (number == 6 * i + 1 || number == 6 * i - 1)

                return true;
            else
                return false;
        }
    }
}

int main()
{
    long long number;
    cin >> number;
    if (isPrimeNumber(number) == true)
        cout << "YES";
    else
        cout << "NO";
}