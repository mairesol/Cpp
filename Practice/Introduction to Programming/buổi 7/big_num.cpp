#include <iostream>
#include <string.h>
using namespace std;
void insert_begin(char num[10000], char x)
{

    for (int i = strlen(num); i > 0; i--)
    {
        num[i] = num[i - 1];
    }
    num[0] = x;
}
void delete_begin_zeros(char num[10000])
{
    while (num[0] == '0')
    {
        for (int i = 0; i < strlen(num); i++)
        {
            num[i] = num[i + 1];
        }
    }
}
int main()
{
    char num1[10000];
    cin >> num1;
    char num2[10000];
    cin >> num2;

    // Cho 2 chuỗi dài bằng nhau bằng cách thêm 0
    while (strlen(num1) > strlen(num2))
        insert_begin(num2, '0');
    while (strlen(num2) > strlen(num1))
        insert_begin(num1, '0');

    // Tính tổng
    char sum[10000];
    int index = strlen(num1) - 1;
    int carry = 0;
    while (index >= 0)
    {
        int sum_one = carry + num1[index] + num2[index] - 48 * 2;
        if (sum_one >= 10)
        {
            carry = 1;
            sum[index] = char(sum_one % 10 + 48);
            // Thêm 1 vào trc khi quá độ dài ban đầu của chuỗi
            if (index == 0)
                insert_begin(sum, '1');
        }
        else
        {
            carry = 0;
            sum[index] = char(sum_one + 48);
        }
        index--;
    }
    delete_begin_zeros(sum);
    cout << sum;
    return 0;
}