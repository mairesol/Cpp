/*
    returnType functionName (parameter1, parameter2,...) {
        // function body
    }
*/
#include <iostream>
using namespace std;
void greet()
{
    cout << "Hello World\n";
}
void Swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int add(int a = 0, int b = 0)
{
    return (a + b);
}
inline int cube(int s)
{
    return s * s * s;
}
int main()
{
    greet();
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    swap(a, b);
    cout << "Sau khi hoan vi\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << add(a, b) << endl;
    cout << "The cube of 3 is: " << cube(3) << "\n";
    return 0;
}
