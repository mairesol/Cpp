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
    Student(double math = 0, double literature = 0)
    {
        this->math = math;
        this->literature = literature;
    }
    ~Student()
    {
        this->name = "";
        this->math = this->literature = 0;
    }
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