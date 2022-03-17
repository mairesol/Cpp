#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;

public:
    double math, literature;
    Student(double math = 0, double literature = 0)
    {
        this->math = math;
        this->literature = literature;
    }
    ~Student()
    {
        this->math = 0;
        this->literature = 0;
    }
    void input()
    {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap diem toan: ";
        cin >> math;
        cout << "Nhap diem van: ";
        cin >> literature;
    }
    double average()
    {
        return (math + literature) / 2;
    }
};

int main()
{
    Student p;
    p.input();
    cout << p.average();
    return 0;
}