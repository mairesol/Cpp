/*
Dãy con của một mảng là một mảng thu được bằng cách xóa đi một số phần tử của mảng ban đầu. Ví dụ mảng: [3, 2, 1] có thể có các dãy con [3, 2], [2, 1], [3, 1]

Hãy viết chương trình kiểm tra xem mảng này có phải là mảng con của mảng kia hay không.

INPUT
Hai số m, n lần lượt là số phần tử của 02 mảng. Giá trị mỗi số không quá một tỷ

Dòng tiếp theo chứa m số nguyên đây là các phần tử của mảng thứ nhất

Dòng cuối cùng của input chứa n số nguyên, đây là các phần tử của mảng thứ hai

OUTPUT
Nếu trong 02 mảng trên, mảng này là dãy con của mảng kia xuất ra màn hình chuỗi “TRUE” nếu không xuất ra chuỗi “FALSE

VÍ DỤ
Input

16 32

1 0 0 2 0 1 1 0 0 0 0 0 1 1 0 0

2 1 2 1 0 2 2 1 0 2 0 1 2 2 0 0 1 1 1 1 2 1 0 1 0 2 0 2 0 1 1 0


Output

FALSE
*/
#include <iostream>
using namespace std;
typedef long long ll;
void nhapmang(ll A[100000], ll m)
{
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
}
ll timKiemPhanTuDauTien(ll A[100000], ll m, ll x)
{
    for (ll i = 0; i < m; i++)
    {
        if (A[i] == x)
            return i;
    }
    return -1;
}
void xoanhieuPhanTuvetruoc(ll A[100000], ll &m, ll pos)
{
    m = m - pos - 1;
    for (ll i = 0; i < m; i++)
    {
        A[i] = A[i + pos + 1];
    }
}
bool KTmangcon(ll A[100000], ll m, ll B[100000], ll n)
{
    for (ll i = 0; i < n; i++) // Chạy mảng bé B
    {
        // cout << timKiemPhanTuDauTien(A, m, B[i]) << " ";
        if (timKiemPhanTuDauTien(A, m, B[i]) == -1) // Kiểm tra từng phần tử trong A đối với 1 phần tử đang xét của B
            return false;                           // Một phần tử của B không bằng phần tử nào của A
        else
            xoanhieuPhanTuvetruoc(A, m, timKiemPhanTuDauTien(A, m, B[i])); // Xoá các phần tử gồm phần tử đã xét và các phần tử trước nó trong A
    }
    return true; // B hoàn toàn là mảng con của A
}
int main()
{

    ll m, n;
    cin >> m >> n;
    ll A[m], B[n];
    nhapmang(A, m);
    nhapmang(B, n);
    if (m > n) // Kiem tra mang B có phải con của mảng A
    {
        if (KTmangcon(A, m, B, n) == 1)
            cout << "TRUE";
        else
            cout << "FALSE";
    }
    else // Kiem tra mang A có phải con của mảng B
    {

        if (KTmangcon(B, n, A, m) == 1)
            cout << "TRUE";
        else
            cout << "FALSE";
    }
    return 0;
}