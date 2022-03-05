#include <iostream>
using namespace std;
#define MAX 10000
void nhapmang(long long A[MAX], long long &n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

int demsoduocchon(long long A[MAX], long long &n, long long target)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (A[i] == target)
            cnt++;
    return cnt;
}

int main()
{
    long long n;
    cin >> n;
    long long A[n];
    nhapmang(A, n);
    long long x;
    cin >> x;
    cout << demsoduocchon(A, n, x);
}