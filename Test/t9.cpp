#include <stdio.h>
#include <math.h>

int max(int arr[10000], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        max = (arr[i] > max) ? arr[i] : max;
    return max;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[10000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Xác định thành phần dương, âm, không
    int arrpos[10000];
    int arrnega[10000];
    int arrzero[10000];
    int posindex = -1;
    int negaindex = -1;
    int zeroindex = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            posindex++;
            arrpos[posindex] = arr[i];
        }
        else if (arr[i] < 0)
        {
            negaindex++;
            arrnega[negaindex] = arr[i];
        }
        else
        {
            zeroindex++;
            arrzero[zeroindex] = arr[i];
        }
    }

    // Tính toán dựa trên các thành phần
    int multipos = 1;
    for (int i = 0; i <= posindex; i++)
        multipos *= arrpos[i];

    int multinega = 1;
    for (int i = 0; i <= negaindex; i++)
        multinega *= arrnega[i];

    if (negaindex % 2 == 0 && negaindex >= 0) // Trường hợp số lượng số âm là số lẻ
        multinega = multinega / max(arrnega, negaindex + 1);

    if (posindex < 0 && (negaindex % 2 == 0 && negaindex >= 0) && zeroindex >= 0) // Trường hợp không có số dương, số lượng số âm là số lẻ và có số 0
    {
        printf("%d", 0);
    }
    else
        printf("%d", multipos * multinega);
}