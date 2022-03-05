/*
Phát hiện va chạm là một trong những bài toán có rất nhiều ứng dụng trong thực tế. Từ những thứ tầm thường như các mini game
đơn giản hay đến những thứ rùng rợn như hệ thống kiểm soát không lưu. Trong những môi trường cụ thể, bài toán phát hiện va chạm
có thể rất phức tạp với những vật thể hình dạng lồi lõm khác nhau. Tuy nhiên, ở dạng đơn giản nhất bài toán phát hiện va chạm
có thể được quy về việc phát hiện va chạm giữa các vật thể hình tròn trên mặt phẳng tọa độ. Hãy viết một chương trình giải quyết bài toán phát hiện va chạm đơn giản này.

INPUT
Hàng đầu tiên chứa số n (n < 1.000), đây là số lượng vật thể cần xét.

n hàng tiếp theo, mỗi hàng chứa 3 con số nguyên lần lượt là tung độ, hoành đồ của tâm đường tròn và bán kính đường tròn. Giá trị mỗi số này không quá 1.000.000

OUTPUT
Số lượng hình tròn đang va chạm với các hình tròn khác

INPUT                           OUTPUT

4                               2

408195 88811 72693

-158730 100875 183434

314824 -316000 7564

-27220 -21160 235500

*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
void nhapmang(ll A[10000], int o)
{
    for (int i = 0; i < o; i++)
        cin >> A[i];
}
void xuatmang(ll A[10000], int o)
{
    for (int i = 0; i < o; i++)
        cout << A[i];
}

bool giaonhau(ll A[], int m, int tungdo, int hoanhdo, int bankinh, int tungdokhac, int hoanhdokhac, int bankinhkhac)
{
    // Cong thuc va cham: R-r < d <= R+r || d < R-r
    if (tungdo == tungdokhac && hoanhdo == hoanhdokhac && bankinh == bankinhkhac)
    {
        tungdokhac += 3;
        hoanhdokhac += 3;
        bankinhkhac += 3;
    }
    if (bankinhkhac < m)
    {
        ll khoangcachtungdo = A[tungdo] - A[tungdokhac];
        ll khoangcachhoanhdo = A[hoanhdo] - A[hoanhdokhac];
        ll tongbankinh = A[bankinh] + A[bankinhkhac];
        ll hieubankinh = abs(A[bankinh] - A[bankinhkhac]);
        float khoangcach2tam = sqrt(khoangcachtungdo * khoangcachtungdo + khoangcachhoanhdo * khoangcachhoanhdo);
        // cout << khoangcach2tam << " " << tongbankinh << " " << hieubankinh << endl;
        if (((khoangcach2tam >= hieubankinh) && (khoangcach2tam <= tongbankinh)) || (khoangcach2tam < hieubankinh) || khoangcach2tam == 0)
            return true;
        else
            return giaonhau(A, m, tungdo, hoanhdo, bankinh, tungdokhac + 3, hoanhdokhac + 3, bankinhkhac + 3);
    }
    else
        return false;
}
int main()
{

    int m;
    cin >> m;
    ll A[10000];
    // Cứ một cặp 3 biểu thì cho 1 đường tròn
    m *= 3;
    nhapmang(A, m);
    int cnt = 0;
    for (int i = 0; i < m; i += 3)
    {
        if (giaonhau(A, m, i, i + 1, i + 2, 0, 1, 2) == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}