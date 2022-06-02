#include <iostream>

using namespace std;

class Vector
{
private:
    double x, y;

public:
    Vector(double = 0, double = 0);
    ~Vector();

    void nhap();
    void xuat();

    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
};

int main()
{
    Vector a, b, c;
    cout << "\nNhap vector a: ";
    a.nhap();
    cout << "\nNhap vector b: ";
    b.nhap();

    cout << "\nPhep cong: ";
    c = a + b;
    c.xuat();

    cout << "\nPhep tru: ";
    c = a - b;
    c.xuat();
    return 0;
}

Vector::Vector(double a, double b) : x(a), y(b){};
Vector::~Vector(){};

void Vector::nhap()
{
    cin >> x >> y;
}
void Vector::xuat()
{
    cout << "(" << x << ";" << y << ")";
}

Vector Vector::operator+(const Vector &obj)
{
    return Vector(x + obj.x, y + obj.y);
}
Vector Vector::operator-(const Vector &obj)
{
    return Vector(x - obj.x, y - obj.y);
}