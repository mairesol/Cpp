#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int jump_search(int arr[], int n, int x)
{
    int step = sqrt(1.0 * n);
    int prev = 0;

    int jump = step;
    // Find element > x
    while (arr[jump - 1] < x)
    {
        prev = jump;
        jump += step;
        if (jump > n)
            jump = n;
        if (prev > n)
            return -1;
    }

    // When found element > x.
    while (arr[prev] < x)
    {
        prev++;
        if (prev == jump)
            return -1;
    }
    if (arr[prev] == x)
        return prev;
    return -1;
}

int main()
{
    return 0;
}