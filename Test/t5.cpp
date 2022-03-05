#include <iostream>
#include <algorithm>
#include <string.h>

typedef unsigned long long ull;

#define MAXROW 10000
#define MAXCOL 205
#define MAXCHAR 10000

using namespace std;

void input(char str[][MAXCOL], int n)
{
    for (int i = 0; i < n; i++)
        cin >> str[i];
}
int find(char str[MAXCHAR], char x)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == x)
            return i;
}
ull power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
        return power(a, b - 1) * a;
}
ull small(char str[MAXCHAR])
{
    int leng = strlen(str);

    // Tạo mảng chứa các kí tự khác nhau
    char arr[MAXCOL];
    int index = -1;
    for (int i = 0; i < leng; i++)
        if (strchr(arr, str[i]) == NULL)
        {
            index++;
            arr[index] = str[i];
        }

    // Đưa ra cơ số và đổi 2 kí tự đầu tiên
    int base = index + 1;
    if (base > 1)
        swap(arr[0], arr[1]);

    // Thực hiện phép cộng
    ull sum = 0;
    if (base != 1)
        for (int i = 0; i < leng; i++) // Quét các kí tự trong str trong arr để đưa ra hệ số
            sum += find(arr, str[i]) * power(base, leng - i - 1);
    else
    {
        base++;
        for (int i = 0; i < leng; i++) // Tất cả kí tự mang giá trị là 1
            sum += 1 * power(base, leng - i - 1);
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    char nums[MAXROW][MAXCOL];
    input(nums, t);

    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << small(nums[i]) << endl;

    return 0;
}

/*
5
11001001
cats
zig
phamphuoc
1111

Case #1: 201

Case #2: 75

Case #3: 11

Case #4: 6053158

*/