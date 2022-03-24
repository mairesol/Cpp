#include <iostream>
#include <algorithm>

using namespace std;

void interchange_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main()
{
    int arr[10] = {8, 4, 1, 6, 5, 14, 45, 66, 2, 14};
    interchange_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}