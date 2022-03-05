#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<int, int> count_min(int a[], int n)
{
    int min;
    int appear;
    if (n == 1)
        return {a[0], 1};
    else
    {
        pair<int, int> save = count_min(a, n - 1);
        if (a[n - 1] < save.first)
            min = a[n - 1];
        else
            min = save.first;
        if (a[n - 1] < save.first)
            appear = 1;
        else if (a[n - 1] == save.first)
            appear = save.second + 1;
        else
            appear = save.second;
    }
    return {min, appear};
}
int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> b = count_min(a, n);
    cout << to_string(b.first) + " " + to_string(b.second);
    return 0;
}
