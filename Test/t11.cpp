#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void input(char A[][1000], int &n)
{
    n = 0;
    while (true)
    {
        cin.getline(A[n], 1000);
        if (A[n][0] == '.')
            break;
        n++;
    }
}
void swapstr(char A[1000], char B[1000])
{
    int max_length = (strlen(A) > strlen(B)) ? strlen(A) : strlen(B);
    char temp;
    for (int i = 0; i < max_length; i++)
    {
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }
}

int compare_string(char str1[1000], char str2[1000])
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; str1[i] != 0 || str2[i] != 0; i++)
    {
        if ((str1[i] >= '0' && str1[i] <= '9') && (str2[i] >= '0' && str2[i] <= '9'))
        {
            int cnt1 = 0;
            int cnt2 = 0;
            do
            {
                if (str1[i] >= '0' && str1[i] <= '9')
                {
                    cnt1++;
                    sum1 = 10 * sum1 + str1[i] - 48;
                }
                if (str2[i] >= '0' && str2[i] <= '9')
                {
                    cnt2++;
                    sum2 = 10 * sum2 + str2[i] - 48;
                }
                i++;
            } while ((str1[i] >= '0' && str1[i] <= '9') || (str2[i] >= '0' && str2[i] <= '9'));
            // cout << sum1 << " " << sum2 << endl;
            // So sánh thông thường
            if (sum1 > sum2)
                return 1;
            else if (sum1 < sum2)
                return -1;
            else // So sánh voi dai 000....a
            {
                if (cnt1 < cnt2)
                    return 1;
                else if (cnt1 > cnt2)
                    return -1;
            }
        }
        if (str1[i] != str2[i])
        {
            // cout << "here" << endl;
            if (str1[i] > str2[i])
                return 1;
            else
                return -1;
        }
    }
    return 0;
}
void sort_files(char A[][1000], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare_string(A[i], A[j]) > 0)
                swapstr(A[i], A[j]);
        }
    }
}
void output(char A[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}
/*

hinh 82.jpeg
hinh 10 0.png
hinh @.jpg
anh 68.jpg
hinh 67.jpg
hinh 67.png
hinh 3.jpegf
anh 333.png
anh 0402.png
anh 94.jpeg
anh 45.jpg
hinh 15.jpeg
anh 33.jpeg
hinh 5h.png
.
 */
int main()
{
    int n;
    char files[1000][1000];
    input(files, n);
    sort_files(files, n);
    // output(files, n);
    cout << files[0] << endl;
    cout << files[n - 1];
    return 0;
}