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
    return 0;
}