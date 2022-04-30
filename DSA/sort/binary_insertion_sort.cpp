#include <iostream>
#include <algorithm>

using namespace std;

void binary_insertion_sort(int arr[], int n)
{
    int key, j, l, r, m;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        l = 0;
        r = i - 1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (key < arr[m])
                r = m - 1;
            else
                l = m + 1;
        }

        j = i - 1;
        while (j >= l)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[l] = key;
    }
}

int main()
{
    return 0;
}