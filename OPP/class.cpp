#include <iostream>
using namespace std;

class Room
{
private:
    double length;
    double breadth;
    double height;

public:
    void initData(double len = 0, double brth = 0, double hgt = 0)
    {
        length = len;
        breadth = brth;
        height = hgt;
    }

    double calculateArea();
    double calculateVolume();
};
double Room::calculateArea()
{
    return length * breadth;
}

double Room::calculateVolume()
{
    return length * breadth * height;
}

class Account
{
public:
    int accno;
    string name;
    static int count;
    Account(int accno = 0, string name = "")
    {
        this->accno = accno;
        this->name = name;
        count++;
    }
    void display()
    {
        cout << accno << " " << name << endl;
    }
};
int Account::count = 0;

int main()
{
    Room room1;
    room1.initData(42.5, 30.8, 19.2);

    cout << "Area of Room =  " << room1.calculateArea() << endl;
    cout << "Volume of Room =  " << room1.calculateVolume() << endl;

    Account a1 = Account(201, "Phan Van Vinh");
    Account a2 = Account(202, "Dao Van Hoa");
    Account a3 = Account(203, "Tran Van Phu");
    a1.display();
    a2.display();
    a3.display();
    cout << "Tong cac doi tuong la: " << Account::count;
    return 0;
}