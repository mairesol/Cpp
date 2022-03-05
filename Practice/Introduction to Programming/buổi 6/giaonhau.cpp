#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
bitset<MAX> bit1, bit2, bit3;
typedef long long ull;
void nhapmang(int O[10000], int o)
{
    for (int i = 0; i < o; i++)
        cin >> O[i];
}
void xuatmang(int O[10000], int o)
{
    for (int i = 0; i < o; i++)
        cout << O[i] << " ";
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Function to return the count of common elements
int count_common(int a[], int n, int b[], int m)
{

    // Traverse the first array
    for (int i = 0; i < n; i++)
    {

        // Set 1 at position a[i]
        bit1.set(a[i]);
    }

    // Traverse the second array
    for (int i = 0; i < m; i++)
    {

        // Set 1 at position b[i]
        bit2.set(b[i]);
    }

    // Bitwise AND of both the bitsets
    bit3 = bit1 & bit2;

    // Find the count of 1's
    int count = bit3.count();

    return count;
}
int main()
{

    int m, n;
    cin >> m >> n;
    int A[10000], B[10000];
    nhapmang(A, m);
    nhapmang(B, n);
    quickSort(B, 0, n - 1);
    // xuatmang(B, n);
    cout << count_common(A, m, B, n);
    return 0;
}