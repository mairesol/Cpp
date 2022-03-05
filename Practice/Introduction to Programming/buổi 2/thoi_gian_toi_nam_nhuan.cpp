#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    // Quy tac chung
    int time;
    if (year % 4 != 0)
        time = 4 - (year % 4);
    else
        time = 0;
    int so_du = year % 100;
    // Quy tac rieng
    // Xet cac nam tan cung 97 den 99
    int tram = year / 100;
    int hang_chuc = year % 100;
    if (hang_chuc >= 97 && hang_chuc <= 99 && (tram + 1) % 4 != 0)
        time += 4;
    // Xet cac nam tan cung 00 va khong chia het cho 400
    if (year % 400 != 0 && hang_chuc == 0)
        time += 4;
    cout << time;
    return 0;
}