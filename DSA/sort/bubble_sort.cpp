#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int arr[], int n)
{
    bool swaped;
    for (int i = 0; i < n - 1; i++)
    {
        swaped = false;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        if (swaped == false)
            break;
    }
}

int main()
{
    int arr[10] = {8, 4, 6, 5, 66, 14, 45, 100, 2, 14};
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}