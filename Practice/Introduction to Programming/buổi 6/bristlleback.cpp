/*
Bristleback là một hero vô cùng khó chịu trong dota với bộ skill cộng hưởng tốt và vô cùng khó giết.
Một trong những skill gây sát thương chủ lực của bristleback là Quills spray. Chiêu này bắn các gai nhọn trên lưng bristleback ra xung quanh khiến các
hero địch không thể tránh né được. Tuy chỉ gây một lượng sát thương ban đầu không lớn chiêu này sẽ để lại gai nhọn cắm trên người hero địch.
Ở lần cast chiêu tiếp theo các gai nhọn được cắm sẵn này sẽ gây thêm một lượng sát thương nữa.
Các gai nhọn này tồn tại độc lập với nhau, không có cách nào gỡ ra và chỉ có thể chờ chúng tự mất đi sau một thời gian nhất định.


Cho biết các thời điểm một hero bị dính skill qullspray của bristleback. Hãy cho biết tổng lượng sát thương mà heroes đó đã nhận.

GHI CHÚ: Trường hợp hero dính đòn quillspary ngay đúng thời điểm một gai nhọn mất đi thì hero vẫn nhận lượng sát thương cộng thêm rồi gai nhọn mới mất. Để có kết quả chính xác các số thực cần được lưu bằng kiểu double


INPUT
Dòng đầu tiên chứa số n (n < 10000), đây là số lần hero dính skill quillspray.

Dòng tiếp theo chứa n số thực, đây là các thời điểm hero dính skill quillspray, xếp theo đúng thứ tự thời gian

Dòng tiếp theo chứa số x, đây là lượng sát thương cơ bản của một lần qullspray

Dòng tiếp theo chứa só y, đây là lượng sát thương tăng thêm mà mỗi gai nhọn đang dính trên người hero sẽ gây ra khi bị dính skill quillspray.

Dòng cuối cùng chứa số z. Đây là thời gian cần thiết để một gai nhọn mất đi sau khi nó được cắm trên người.

OUTPUT
Tổng lượng sát thương

Ví dụ:
Input	                        Output
5                                580
4.9 12.6 19.1 22.9 46.2
65
51
15.0
*/

#include <iostream>
#include <iomanip>
using namespace std;
typedef unsigned long long ull;
typedef double d;
#define MAX 10000
void nhapmang(d A[MAX], ull &n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
void xuatmang(d A[10000], int a)
{
    for (int i = 0; i < a; i++)
        cout << A[i] << " ";
}
ull spikes_now(d A[MAX], ull index, d spike_disappear_time)
{
    ull cnt = 0;
    d now = A[index];
    // cout << now << " " << index << " " << spike_disappear_time << " ";
    int i = 1;
    while (i <= index)
    {
        if (now - A[index - i] > spike_disappear_time)
            return cnt;
        else
            cnt++;
        i++;
    }
    return cnt;
}
int main()
{
    ull n;
    cin >> n;
    d A[n];
    nhapmang(A, n);
    d basic_dame, bonus_dame, spike_disappear_time;
    cin >> basic_dame >> bonus_dame >> spike_disappear_time;
    // Tổng sát thương nhận thêm
    d all_bonus_dame = 0;
    for (ull i = 1; i < n; i++)
        all_bonus_dame += bonus_dame * spikes_now(A, i, spike_disappear_time);
    // Tổng sát thương
    cout << basic_dame * n + all_bonus_dame;
    return 0;
}
