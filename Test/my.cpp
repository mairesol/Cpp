#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;
    int tinh1()
    {
        return num + den;
    }

public:
    Fraction(int a, int b)
    {
        num = a;
        den = b;
    }
    ~Fraction()
    {
    }
    int tinh2();
};

int Fraction::tinh2()
{
    cout << tinh1();
    cout << num;
    return this->tinh1() + num;
}

int main()
{
    Fraction a(2, 3);
    cout << a.tinh2();
    return 0;
}