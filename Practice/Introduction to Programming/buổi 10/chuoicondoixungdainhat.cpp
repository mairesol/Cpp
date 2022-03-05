#include <iostream>
#include <string.h>

#define MAX 1000000

typedef long long ll;

using namespace std;

int main()
{
    char str[MAX];
    cin.getline(str, MAX);
    int leng = strlen(str);
    ll i = 0;
    ll max = 1;

    ll center = 0;
    ll r;
    while (i < leng)
    {
        if (str[i - 1] == str[i + 1])
        {
            r = 1;
            while (str[i - r - 1] == str[i + r + 1])
                r++;
            if (2 * r + 1 > max)
            {
                max = 2 * r + 1;
                center = i;
            }
        }
        else if (str[i] == str[i + 1])
        {
            r = 1;
            while (str[i - r] == str[i + r + 1])
                r++;
            if (2 * r > max)
            {
                max = 2 * r;
                center = i;
            }
        }
        i++;
    }
    if (max % 2 != 0)
    {
        max /= 2;
        ll a = center - max;
        ll b = center + max;
        for (ll j = a; j <= b; j++)
            cout << str[j];
    }
    else
    {
        max /= 2;
        ll a = center - max + 1;
        ll b = center + max;
        for (ll j = a; j <= b; j++)
            cout << str[j];
    }
    return 0;
}