/*
Giá bán điên sinh hoạt do ngành điện quy định tháng 8/2013 được cho ở bảng sau:
0 - 100: 1.418 -> 0,1
101 - 150: 1.622 -> 2
151 - 200: 2.044 -> 3
201 - 300: 2.210 -> 4,5
301 – 400: 2.361->6,7 
401 trở lên: 2.420 -> 8 trở lên 


INPUT
Một số nguyên dương giá trị trong khoảng từ 1 đến 100000. Đây là lượng điện tiêu thụ trong tháng của gia đình. Đơn vị kWh

OUTPUT
Số tiền điện phải trả trong tháng đó. Đơn vị Việt Nam đồng
*/
#include <iostream>
using namespace std;

int main()
{
    long kWh;
    cin >> kWh;
    // Dung chia du de lay gia tri cho switch case
    int key;
    if (kWh % 50 == 0 && kWh != 0)
        key = kWh / 50 - 1;
    else
        key = kWh / 50;
    // Tinh tien
    long long money;
    switch (key)
    {
    case 0:
    case 1:
        money = 1418 * kWh;
        break;
    case 2:
        money = 1622 * (kWh - 100) + 141800;
        break;
    case 3:
        money = 2044 * (kWh - 150) + 222900;
        break;
    case 4:
    case 5:
        money = 2210 * (kWh - 200) + 325100;
        break;
    case 6:
    case 7:
        money = 2361 * (kWh - 300) + 546100;
        break;
    default:
        money = 2420 * (kWh - 400) + 782200;
        break;
    }
    cout << money;
    return 0;
}