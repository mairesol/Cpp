#include <iostream>
using namespace std;
int binary_search(int arr[], int left, int right, int x)
{
    if (right >= 1)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return binary_search(arr, mid + 1, right, x);
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);
    }
    else
        return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x;
    cin >> x;
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, left, right, x);
    if (result != -1)
        cout << result;
    else
        cout << "Not found";
    return 0;
}