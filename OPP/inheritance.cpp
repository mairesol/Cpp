#include <iostream>

using namespace std;

// Base class
class Parent
{
public:
    int id_p;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent
{
public:
    int id_c;
};

class A
{
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

class ClassA
{
public:
    int a;
};

class ClassB : virtual public ClassA
{
public:
    int b;
};

class ClassC : virtual public ClassA
{
public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
public:
    int d;
};

class Diem
{
    double x, y;

public:
    Diem() { x = y = 0.0; }
    Diem(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
};
class HinhTron : public Diem
{
    double r;

public:
    HinhTron() { r = 0.0; }
    HinhTron(double xx, double yy, double rr) : Diem(xx, yy) { r = rr; }
};

class A
{
    //…
public:
    A &operator=(A &h)
    {
        // Gán các thuộc tính  của A
        return *this;
    }
    A *get_A()
    {
        return this;
    }
};
class B : public A
{
public:
    B &operator=(B &h)
    {
        A *u1, *u2;
        u1 = this->get_A();
        u2 = h.get_A();
        *u1 = *u2;
        // Gán các thuộc tính riêng của B
    }
};

// main function
int main()
{
    Child obj1;

    // An object of class child has all data members
    // and member functions of class parent
    obj1.id_c = 7;
    obj1.id_p = 91;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n';

    ClassD obj;

    obj.a = 100;

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << "\n a : " << obj.a;
    cout << "\n b : " << obj.b;
    cout << "\n c : " << obj.c;
    cout << "\n d : " << obj.d << '\n';
    return 0;
}