#include <iostream>
typedef unsigned long long ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;
    cin >> n;
    ull A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int phepxor = A[0];
    for (int i = 1; i < n; i++)
    {
        phepxor ^= A[i];
    }
    cout << phepxor;
    return 0;
}
