#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "dathuc.h"
int main()
{
    dathuc dathuc1(3), dathuc2(1);
    cin >> dathuc1 >> dathuc2;
    cout << " + " << dathuc1 + dathuc2 << endl;
    cout << " - " << dathuc1 - dathuc2 << endl;
    cout << " * " << dathuc1 * dathuc2 << endl;
    cout << " / " << dathuc1 / dathuc2 << endl;
    return 0;
}
