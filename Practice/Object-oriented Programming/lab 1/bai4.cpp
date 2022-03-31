#include <iostream>

using namespace std;

class Day
{
private:
    int date, month, year;

public:
    Day(int date = 0, int month = 0, int year = 0)
    {
        this->date = date;
        this->month = month;
        this->year = year;
    }
    ~Day();
    bool isLeapYear();
    bool isValid();
    int datesInMonth();
    Day next_day();
    friend istream &operator>>(istream &, Day &);
    friend ostream &operator<<(ostream &, const Day &);
};

int main()
{
    // Viet chuong trinh nhap vao 1 ngay, tim ngay ke tiep va xuat ket qua
    Day d;
    cin >> d;
    cout << "Ngay tiep theo: " << d.next_day();
    return 0;
}
bool Day::isLeapYear()
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
bool Day::isValid()
{
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (date < 1 || date > datesInMonth())
        return false;
    return true;
}
int Day::datesInMonth()
{
    int ans;
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        ans = 30;
        break;
    case 2:
        if (isLeapYear())
            ans = 29;
        else
            ans = 28;
        break;
    default:
        ans = 31;
        break;
    }
    return ans;
}
Day Day::next_day()
{
    Day d = *this;
    d.date++;
    if (d.date > d.datesInMonth())
    {
        d.date = 1;
        d.month++;
        if (d.month > 12)
        {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}
istream &operator>>(istream &is, Day &obj)
{
    do
    {
        cout << "Nhap ngay: ";
        is >> obj.date;
        cout << "Nhap thang: ";
        is >> obj.month;
        cout << "Nhap nam: ";
        is >> obj.year;
    } while (!obj.isValid());
    return is;
}

ostream &operator<<(ostream &os, const Day &obj)
{
    os << obj.date << "/" << obj.month << "/" << obj.year;
    return os;
}