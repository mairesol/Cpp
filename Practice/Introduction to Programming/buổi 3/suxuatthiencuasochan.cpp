#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int phandu;
    while (number > 0)
    {
        phandu = number % 10;
        if (phandu % 2 == 0)
        {
            cout << "TRUE";
            return 0;
        }
        number /= 10;
    }

    cout << "FALSE";
    return 0;
}