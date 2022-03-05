/*
Bạn Bình rất là thích chơi ô chữ. Nhưng vì chưa học tới phần string nên bạn chuyển qua chơi "ô số".
Bạn Bình muốn làm cái ô số đơn giản hình chữ nhật gồm có 4 số, mỗi số nằm trên một cạnh.
Các cạnh này tạo thành 4 cặp cạnh cắt nhau và cắt tại một chữ số chung giữa hai số trên cạnh này.
Số được đọc từ trên xuống dưới trên cạnh dọc và từ trái qua phải trên cạnh ngang.
Diện tích hình chữ nhật bên trong của ô số phải khác 0

INPUT
4 số tự nhiên

OUTPUT
Số cách xếp ô số

4 hình chữ nhật đó như sau:
123456
45678
64321
89053

4 5 6 7 8
    4   9
    3   0
    2   5
    1 2 3 4 5 6

    6
    4 5 6 7 8
    3       9
    2       0
    1 2 3 4 5 6
            3

4
5
6 4 3 2 1
7       2
8 9 0 5 3
        4
        5
        6



6 4 3 2 1
  5     2
  6     3
  7     4
  8 9 0 5 3
        6

*/
#include <iostream>
#include <math.h>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;

ull before(ull n, int i)
{
    while (i > 0)
    {
        n /= 10;
        i--;
    }
    return n;
}
int digit(ull n, int i)
{
    return before(n, i) % 10;
}
void sapsoxuoi(ull n1, ull n2, ull n3, ull n4, int &count)
{
    // n1 trên, n2 dưới, n3 trái, n4 phải
    int index1 = log10(n1), index2 = log10(n2), index3 = log10(n3), index4 = log10(n4);
    for (int ix = index1; ix >= 2; ix--) // Chay xuoi n1
    {
        for (int j = index3; j >= 0; j--) // Chay n3
        {
            if (digit(n3, j) == digit(n1, ix))
            {
                for (int in = 0; in < ix - 1; in++) // Chay nguoc n1
                {
                    for (int k = index4; k >= 0; k--) // Chay n4
                    {
                        if (digit(n4, k) == digit(n1, in))
                        {
                            int start3 = j - 2, start4 = k - 2;
                            while (start3 >= 0 && start4 >= 0)
                            {
                                for (int m = index2; m >= ix - in; m--) // Chay n2
                                {
                                    if (digit(n2, m) == digit(n3, start3) && digit(n2, m - (ix - in)) == digit(n4, start4))
                                        count++;
                                }
                                start3--;
                                start4--;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ull n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    int count = 0;
    ull myints[] = {n1, n2, n3, n4};
    sort(myints, myints + 4); // Khi hoan vi can sap xep
    do
    {
        sapsoxuoi(myints[0], myints[1], myints[2], myints[3], count);
    } while (next_permutation(myints, myints + 4));
    cout << count;
    return 0;
}