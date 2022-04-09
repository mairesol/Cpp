#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArray[i] = arr[mid + i + 1];

    int leftIndex = 0, rightIndex = 0;
    int mergeIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            arr[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftSize)
    {
        arr[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightSize)
    {
        arr[mergeIndex] = rightArray[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    return 0;
}