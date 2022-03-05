/*
Một set tennis sẽ kết thúc khi có người đạt tới 6 điểm trước. Tuy nhiên nếu cả hai đang hòa nhau 5-5 trong một set thì set phải đánh tới điểm thứ 7 mới kết thúc. Bạn hãy viết chương trình xét xem hai số tự nhiên có phải tỷ số của một set tennis hay không

INPUT
Hai số tự nhiên

OUTPUT
Số 1 nếu đó là tỷ số của một set tennis. Ngược lại output số 0.
*/
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if ((a == 7 && (b == 6 || b == 5)) || ((a == 5 || a == 6) && b == 7) || (a == 6 && b >= 0 && b < 5) || (a >= 0 && a < 5 && b == 6))
        cout << 1;
    else
        cout << 0;
    return 0;
}
