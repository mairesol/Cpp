/*
Viết chương trình Nhập vào tháng và năm (năm > 1975), kiểm tra tính hợp lệ của tháng năm và cho biết tháng đó có bao nhiêu ngày. 
*/
#include <iostream>
using namespace std;

int main()
{
    int year, month;
    cin >> year >> month;
    // Kiểm tra tính hợp lệ của tháng năm
    if (year > 1975)
        cout << "Nam hop le\n";
    else
        cout << "Nam khong hop le\n";
    if (month >= 1 && month <= 12)
        cout << "Thang hop le\n";
    else
        cout << "Thang khong hop le\n";
    // Kiem tra thang do co bao nhieu ngay
    int days;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        if (year % 4 == 0 && year % 100 != 0)
            days = 29;
        else
            days = 28;
        break;
    default:
        days = -1; // Thang khong hop le
        break;
    }
    cout << days;
    return 0;
}