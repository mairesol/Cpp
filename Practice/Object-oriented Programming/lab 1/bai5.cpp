#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student
{
private:
    string name;
    double math, literature;

public:
    Student(string = "", double = 0, double = 0);
    ~Student();
    void input();
    double average();
};

int main()
{
    // Nhap vao ho ten, diem toan, diem van; tinh diem trung binh va xuat ket qua
    Student p;
    p.input();
    cout << "Diem trung binh: " << setprecision(2) << p.average();
    return 0;
}
Student::Student(string n, double m, double l)
{
    math = m;
    literature = l;
}

void Student::input()
{
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap diem toan: ";
    cin >> math;
    cout << "Nhap diem van: ";
    cin >> literature;
}
double Student::average()
{
    return (math + literature) / 2;
}