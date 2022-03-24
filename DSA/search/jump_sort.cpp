#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int jump_search(int arr[], int n, int x)
{
    int step = sqrt(n);
    int prev = 0;

    // Find element > x
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // When found element > x.
    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
        {
            return -1;
        }
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int main()
{

    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = jump_search(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    return 0;
}