#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int left, int right, int x)
{
    if (right <= left)
        return (x > arr[left]) ? (left + 1) : left;

    int mid = left + (right - left) / 2;
    if (arr[mid] == x)
        return mid + 1;
    if (arr[mid] > x)
        return binary_search(arr, left, mid - 1, x);
    return binary_search(arr, mid + 1, right, x);
}

void binary_insertion_sort(int arr[], int n)
{
    int key, loc, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        loc = binary_search(arr, 0, j, key);

        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    return 0;
}