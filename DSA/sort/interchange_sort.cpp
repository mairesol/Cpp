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
    return 0;
}