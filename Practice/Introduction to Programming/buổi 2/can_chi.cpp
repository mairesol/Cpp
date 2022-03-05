#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    int key1;
    if (year > 0)
        key1 = year % 10;
    else
        key1 = (year % 10) - 1; // Vi không thể lấy dc phần dư là - 12

    int key2;
    if (year > 0)
        key2 = year % 12;
    else
        key2 = (year % 12) - 1; // Vi không thể lấy dc phần dư là - 12
    if (year != 0)
    {
        switch (key1) // (0-9)(Canh tới kỷ),(-10,-1)(Nhâm tới Tân)
        {
        case 0:
        case -2:
            cout << "CANH ";
            break;
        case 1:
        case -1:
            cout << "TAN ";
            break;
        case 2:
        case -10:
            cout << "NHAM ";
            break;
        case 3:
        case -9:
            cout << "QUY ";
            break;
        case 4:
        case -8:
            cout << "GIAP ";
            break;
        case 5:
        case -7:
            cout << "AT ";
            break;
        case 6:
        case -6:
            cout << "BINH ";
            break;
        case 7:
        case -5:
            cout << "DINH ";
            break;
        case 8:
        case -4:
            cout << "MAU ";
            break;
        case 9:
        case -3:
            cout << "KY ";
            break;
        default:
            break;
        }
        switch (key2) // (0-11)(Thân tới Mùi),(-12--1)(Tuát tới Dậu)
        {
        case 0:
        case -2:
            cout << "THAN";
            break;
        case 1:
        case -1:
            cout << "DAU";
            break;
        case 2:
        case -12:
            cout << "TUAT";
            break;
        case 3:
        case -11:
            cout << "HOI";
            break;
        case 4:
        case -10:
            cout << "TY'";
            break;
        case 5:
        case -9:
            cout << "SUU";
            break;
        case 6:
        case -8:
            cout << "DAN";
            break;
        case 7:
        case -7:
            cout << "MEO";
            break;
        case 8:
        case -6:
            cout << "THIN";
            break;
        case 9:
        case -5:
            cout << "TY.";
            break;
        case 10:
        case -4:
            cout << "NGO";
            break;
        case 11:
        case -3:
            cout << "MUI";
            break;
        default:
            break;
        }
    }
}