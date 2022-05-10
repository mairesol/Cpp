#include <algorithm>
#include <iostream>

using namespace std;

void oddEvenSort(int arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted

    while (!isSorted)
    {
        isSorted = true;

        // Perform Bubble sort on odd indexed element
        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        // Perform Bubble sort on even indexed element
        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main()
{
    return 0;
}