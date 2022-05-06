#include <iostream>

using namespace std;

class Box
{
private:
    int length;

public:
    Box(int length = 0)
    {
        this->length = length;
    }
    friend int printLength(Box);
};

int printLength(Box b)
{
    b.length += 10;
    return b.length;
}

class A
{
    friend class B;

private:
    int x = 5;
};
class B
{
public:
    void display(A &a)
    {
        cout << "Gia tri cua x la: " << a.x;
    }
};
int main()
{
    Box c;
    cout << "Chieu dai cua box: " << printLength(c) << endl;

    A a;
    B b;
    b.display(a);
    return 0;
}