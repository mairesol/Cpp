#include <iostream>
using namespace std;
void check_triangle(int a, int b, int c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "Invalid edges. Plesse check again!" << endl;
    }
    else
    {
        cout << "This is ";
        if ((a == b) && (b == c))
        {
            cout << "equilateral triangle." << endl;
        }
        else
        {
            if (a * a + b * b == c * c || a * c + c * c == b * b || b * b + c * c == a * c)
            {
                cout << "right triangle." << endl;
            }
            if (a == b || a == c || b == c)
            {
                cout << "isosceles triangle." << endl;
            }
            else
            {
                cout << "common triangle." << endl;
            }
        }
    }
}
void Equation_2_2(float a, float b, float c, float d, float e, float f)
{
    float det = a * e - b * d;
    float det1 = c * e - b * f;
    float det2 = a * f - c * d;
    if (det != 0)
    {
        float x = det1 / det;
        float y = det2 / det;
        cout << "Roots of equations: " << x << "\t" << y << endl;
    }
    else if (det1 != 0 || det2 != 0)
        cout << "Roots of equations: No solution" << endl;
    else if (det1 == 0 && det2 == 0)
        cout << "Roots of equations: Undetermined" << endl;
}
bool checkNam_nhuan(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int Ngay_trong_thang(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (checkNam_nhuan(year) == 1)
            return 29;
        else
            return 28;
    default:
        break;
    }
}
int findNgay_tiep_theo(int day, int month, int year)
{
    if (day < Ngay_trong_thang(month, year))
        ++day;
    else if (month < 12)
    {
        day = 1;
        ++month;
    }
    else
    {
        day = 1;
        month = 1;
        ++year;
    }
    cout << "Next day: " << day << "/" << month << "/" << year << endl;
}
void findNgay_truoc_do(int day, int month, int year)
{
    if (day == 1)
        if (month == 1)
        {
            day = 31;
            month = 12;
            --year;
        }
        else
        {
            --month;
            day = Ngay_trong_thang(month, year);
        }
    else
        --day;
    cout << "Yesterday: " << day << "/" << month << "/" << year << endl;
}
int main()
{
    // // Xuất các ký tự từ a -> z
    // for (char kytu = 'a'; kytu <= 'z'; kytu++)
    // {
    //     cout << kytu << '\t';
    // }
    // // Viết chương trình tìm số nguyên dương m lớn nhất sao cho 1 + 2 + … + m < N
    // cout << "1 + 2 + … + m < N" << endl;
    // int N;
    // cout << "N: ";
    // cin >> N;
    // int sum = 0, m = 0;
    // while (sum + m + 1 < N)
    // {
    //     m++;
    //     sum += m;
    // };
    // cout << "m = " << m << endl;
    // // Kiem tra loai tam giac
    // float a, b, c;
    // cout << "Nhap 3 canh: ";
    // cin >> a >> b >> c;
    // check_triangle(a, b, c);
    // // Hệ phương trình: ax + by = c, dx + ey = f
    // cout << "Equations:" << endl;
    // cout << "ax + by = c" << endl;
    // cout << "dx + ey = f" << endl;
    // float a, b, c, d, e, f;
    // cout << "Enter coefficient:";
    // cin >> a >> b >> c >> d >> e >> f;
    // Equation_2_2(a, b, c, d, e, f);
    // Ngày tiếp theo
    int day, month, year;
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    findNgay_tiep_theo(day, month, year);
    // Ngày trước đó
    findNgay_truoc_do(day, month, year);
    return 0;
}