#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int sum = 0;
    int partner;
    for (int i = 1; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            partner = number / i;
            if (partner != i) // Khong lay chinh so do vao tong va tranh cong nham can bac hai 2 lan
                sum += i + partner;
            else
                sum += i;
        }
    }
    cout << sum;
    return 0;
}