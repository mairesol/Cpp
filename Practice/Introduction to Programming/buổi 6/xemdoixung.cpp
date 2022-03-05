/*
Cho một mảng xém đối xứng. Hỏi nếu ta có thể tùy ý thay đổi một số nào đó trong mảng thì ta có thể biến mảng này thành mảng đối xứng hay không

INPUT
Dòng đầu tiên chứa số n (n < 1000000). Đây là số lượng phần tử trong mảng.

n dòng tiếp theo, mỗi dòng là một số nguyên dương có giá trị không quá một tỷ.

OUTPUT
xuất ra chữ TRUE nếu có thể biến mảng thành đối xứng. Ngược lại xuất chứ FALSE.


Input	Output
5       TRUE
1
2
3
2
2
*/
#include <iostream>
using namespace std;
typedef long long ll;
void nhapmang(ll A[100000], ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}
bool xemdoixung(ll A[100000], ll n)
{
    int cnt = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (A[i] != A[n - i - 1])
            cnt++;
        if (cnt == 2)
            return false;
    }
    return true;
}
int main()
{

    ll n;
    cin >> n;
    ll A[n];
    nhapmang(A, n);
    if (xemdoixung(A, n) == true)
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}
