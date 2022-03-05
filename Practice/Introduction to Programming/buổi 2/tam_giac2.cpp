/*
Viết chương trình Nhập ba số a, b, c.
Kiểm tra xem chúng có thê là độ dài của các cạnh của một tam giác hay không.
Nếu có thì cho biết đó là tam giác gì: NHON, VUONG, TU 
*/
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // Kiem tra 3 canh
    if (a + b <= c || a + c <= b || b + c <= a)
        cout << "KHONG PHAI TAM GIAC";
    // Tam giac gi ?
    else
    {
        // Theo goc
        if (a * a + b * b == c * c || a * c + c * c == b * b || b * b + c * c == a * c)
            cout << "VUONG";
        if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b)
            cout << "TU";
        if (a * a < b * b + c * c && b * b < a * a + c * c && c * c < a * a + b * b)
            cout << "NHON";
        // Theo canh
        if ((a == b) && (b == c))
            cout << " DEU";
        else
        {
            if (a == b || a == c || b == c)
                cout << " CAN";
        }
    }
    return 0;
}
