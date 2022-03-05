#include <iostream>
using namespace std;
typedef long long ll;
typedef double d;
#define MAX 1000000
void nhapmang(ll A[MAX], ll &n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}
bool ktuoc(ll A[MAX], ll index, ll x)
{
    for (ll k = 0; k < index; k++)
    {
        if (A[k] % x == 0)
            return true;
    }
    return false;
}
bool ktboi(ll A[MAX], ll index, ll x)
{
    for (ll k = 0; k < index; k++)
    {
        if (x % A[k] == 0)
            return true;
    }
    return false;
}

int main()
{
    ll n;
    cin >> n;
    ll A[n];
    nhapmang(A, n);
    ll result = -1;
    for (ll i = 1; i < n; i++)
    {
        if (ktuoc(A, i, A[i]) == false && ktboi(A, i, A[i]) == false)
        {
            cout << A[i];
            return 0;
        }
    }
    cout << result;
    return 0;
}