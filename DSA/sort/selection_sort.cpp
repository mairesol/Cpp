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
    int arr[10] = {8, 4, 6, 5, 66, 14, 45, 66, 2, 14};
    selection_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}