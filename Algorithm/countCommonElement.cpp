// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
bitset<MAX> bit1, bit2, bit3;

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

// Driver code
int main()
{

    int a[] = {1, 4, 7, 2, 3};
    int b[] = {2, 11, 7, 4, 15, 20, 24};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << count_common(a, n, b, m);

    return 0;
}