#include <iostream>
#include <algorithm>

using namespace std;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void comb_sort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);

        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    int arr[10] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    comb_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}