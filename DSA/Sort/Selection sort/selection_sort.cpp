#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    return 0;
}