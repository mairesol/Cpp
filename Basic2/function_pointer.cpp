#include <iostream>
using namespace std;

void swapNumber(int &, int &);

bool asc(int a, int b)
{
    return a > b;
}

bool desc(int a, int b)
{
    return a < b;
}

void selectionSort(int *arr, int n, bool (*comparisonFcn)(int, int))
{
    int i, j, find_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        find_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (comparisonFcn(arr[find_idx], arr[j]))
            {
                find_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        swapNumber(arr[find_idx], arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    void (*ptrSwap)(int &, int &) = swapNumber;

    int a = 5, b = 10;
    cout << "Before: " << a << " " << b << endl;

    // gọi hàm tường minh
    (*ptrSwap)(a, b);
    cout << "After:  " << a << " " << b << endl;

    // hoặc gọi hàm ngầm định
    ptrSwap(a, b);
    cout << "After:  " << a << " " << b << endl;

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(int);

    // Sắp xếp tăng
    selectionSort(arr, n, asc);

    cout << "Asc array: \n";
    printArray(arr, n);

    // Sắp xếp giảm
    selectionSort(arr, n, desc);

    cout << "Desc array: \n";
    printArray(arr, n);

    return 0;
}
void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
