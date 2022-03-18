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
    ~Day()
    {
        this->date = 0;
        this->month = 0;
        this->year = 0;
    }
    bool isLeapYear();
    bool isValid();
    int datesInMonth();
    Day operator++()
    {
        date++;
        if (date > this->datesInMonth())
        {
            date = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }
    Day operator--()
    {
        date--;
        if (date == 0)
        {
            date = this->datesInMonth();
            month--;
            if (month == 0)
            {
                month = 12;
                year--;
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &is, Day &obj)
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

    friend ostream &operator<<(ostream &os, const Day &obj)
    {
        os << obj.date << "/" << obj.month << "/" << obj.year;
        return os;
    }
};

int main()
{
    Day d;
    cout << ++d;
    return 0;
}
bool Day::isLeapYear()
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
bool Day::isValid()
{
    if (month < 1 || month > 12)
        return false;
    if (date < 1 || date > this->datesInMonth())
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
        if (this->isLeapYear())
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