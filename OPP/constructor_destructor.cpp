#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    int id;
    string name;
    float salary;

public:
    Employee()
    {
        id = 0;
        name = "";
        salary = 0;
    }
    Employee(int id = 0, string name = "", float salary = 0)
    {
        id = id;
        name = name;
        salary = salary;
    }
    Employee(Employee &A)
    {
        id = A.id;
        name = A.name;
        salary = A.salary;
    }

    ~Employee()
    {
        this->id = 0;
        this->name = "";
        this->salary = 0;
    }
    void display() { cout << id << "  " << name << "  " << salary << endl; }
};

int main(void)
{
    Employee e1 = Employee(101, "Phan Van Vinh", 500);
    Employee e2 = Employee(102, "Dao Van Hoa", 1000);
    e1.display();
    e2.display();
    return 0;
}