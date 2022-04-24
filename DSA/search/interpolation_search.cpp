#include <iostream>
#include <algorithm>

using namespace std;

int interpolation_search(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + ((double)(right - left) * (x - arr[left]) / (arr[right] - arr[left]));
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return interpolation_search(arr, left, mid - 1, x);
        return interpolation_search(arr, mid + 1, right, x);
    }
    return -1;
}

int main()
{
    return 0;
}