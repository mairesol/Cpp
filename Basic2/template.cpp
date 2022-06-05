
#include <iostream>

using namespace std;

// Function Templates
template <class F = double>
F myMax(F x, F y)
{
    return (x > y) ? x : y;
}

// Class Remplates
template <class C = int>
class Array
{
private:
    C *ptr;
    int size;

public:
    Array(C arr[], int s);
    void print();
};

template <class C>
Array<C>::Array(C arr[], int s)
{
    ptr = new C[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <class C>
void Array<C>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

template <class T, int max = INT_MAX>
int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];

    return m;
}

int main()
{
    cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0) << endl;
    cout << myMax<char>('g', 'e') << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();

    int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << arrMin<int, 10000>(arr1, n1) << endl;
    cout << arrMin<char, 256>(arr2, n2);
    return 0;
}