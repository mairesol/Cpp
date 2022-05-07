#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int length = right - left + 1;
    int *temp = new int[length];
    int pos = 0, i = left, j = mid + 1;
    while (!(i > mid && j > right))
    {
        if ((i <= mid && j <= right && arr[i] < arr[j]) || j > right)
            temp[pos++] = arr[i++];
        else
            temp[pos++] = arr[j++];
    }
    for (int k = 0; k < length; k++)
        arr[left + k] = temp[k];
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    return 0;
}