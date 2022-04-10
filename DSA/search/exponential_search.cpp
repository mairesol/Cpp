#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);
        return binary_search(arr, mid + 1, right, x);
    }
    return -1;
}

// 1. Find range where element is present
// 2. Do Binary Search in above found range.

int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    //  Call binary search for the found range.
    return binary_search(arr, i / 2, min(i, n - 1), x);
}

int main()
{
    return 0;
}