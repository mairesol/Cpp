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

  obj.a = 10;  // Statement 3
  obj.a = 100; // Statement 4

  obj.b = 20;
  obj.c = 30;
  obj.d = 40;

  cout << "\n a : " << obj.a;
  cout << "\n b : " << obj.b;
  cout << "\n c : " << obj.c;
  cout << "\n d : " << obj.d << '\n';
  return 0;
}