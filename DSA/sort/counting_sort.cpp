#include <iostream>
#include <algorithm>

using namespace std;

void counting_sort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    int size = max - min + 1;
    int *count = new int[size]{0};
    int *output = new int[n];

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    for (int i = 1; i < size; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    return 0;
}