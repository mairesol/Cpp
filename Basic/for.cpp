#include <iostream>
using namespace std;

int main()
{
    int num, sum;
    sum = 0;
    cout << "Enter a positive integer: ";
    cin >> num;
    for (int i = 1, j = 1; i <= num; ++i, j--)
    {
        sum += i - j;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}