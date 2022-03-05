/*
Ngày 16/12/2107 là ngày THỨ BẢY. Ngày 16/12 năm sau 16/12/2018 sẽ là CHỦ NHẬT. Và phải 6 năm sau, ngày 16/12/2023 mới trở lại là thứ bảy.

Cho một ngày tháng năm bất kỳ hỏi sau bao nhiêu năm nữa thì ngày tháng đó mới trùng ngày thứ với ngày hiện tại.

INPUT
Dòng đầu tiên chứa số nguyên dương n, đay là số lượng test case.

n dòng tiếp theo, mỗi dòng là một test case, chứa 03 con số tương ứng lần lượt là ngày, tháng, năm hiện tại

OUTPUT
Ứng với mỗi test case, xuất ra số năm để ngày tháng đó trùng "ngày thứ trong tuần" với ngày hiện tại. Nếu ngày tháng năm hiên tại không hợp lệ, xuất ra chuỗi SAI
*/
#include <iostream>
using namespace std;

int dates[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ldates[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

bool isValid(int date, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    else
    {
        if (isLeapYear(year) == 0)
            return (date > 0 && date < dates[month - 1]);
        else
            return (date > 0 && date < ldates[month - 1]);
    }
}

int day(int date, int month, int year)
{
    if (isValid(date, month, year) == true)
    {
        int rst = date + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) + (365 * (year + 4800 - ((14 - month) / 12))) + ((year + 4800 - ((14 - month) / 12)) / 4) - ((year + 4800 - ((14 - month) / 12)) / 100) + ((year + 4800 - ((14 - month) / 12)) / 400) - 32045;
        return (rst + 1) % 7;
    }
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    int date[10000];
    int month[10000];
    int year[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
        cin >> month[i];
        cin >> year[i];
        if (isValid(date[i], month[i], year[i]) == true)
        {
            int time = 1;
            while (day(date[i], month[i], year[i]) != day(date[i], month[i], year[i] + time))
                time++;
            cout << time << endl;
        }
        else
            cout << "SAI" << endl;
    }
    return 0;
}