#include <iostream>
#include <algorithm>

using namespace std;

void cocktail_sort(int arr[], int n)
{
    int left = 0, right = n - 1;
    int k = 0;
    while (left < right)
    {
        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
            k = i;
        }
        left = k;

        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
            k = i;
        }
        right = k;
    }
}

int main()
{

    return 0;
}