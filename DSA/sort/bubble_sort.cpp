#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
}

int main()
{
    return 0;
}