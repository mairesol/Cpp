#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

void shuffle(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        swap(arr[i], arr[rand() % n]);
}

void bogo_sort(int arr[], int n)
{
    while (!isSorted(arr, n))
        shuffle(arr, n);
}

int main()
{
    int arr[10];
    int n = 10;
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    bogo_sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}