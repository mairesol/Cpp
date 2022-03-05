#include <iostream>
using namespace std;

int main()
{
    int value1, weight1, value2, weight2, maxW;
    cin >> value1 >> weight1 >> value2 >> weight2 >> maxW;
    if (maxW >= weight1 + weight2)
        cout << value1 + value2;
    else if (maxW < weight1 && maxW < weight2)
        cout << 0;
    else if (weight1 <= maxW && weight2 > maxW)
        cout << value1;
    else if (weight2 <= maxW && weight1 > maxW)
        cout << value2;
    else
    {
        if (value1 > value2)
            cout << value1;
        else
            cout << value2;
    }
    return 0;
}