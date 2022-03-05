#include <iostream>
typedef long long ll;
using namespace std;

void list0(ll number)
{
    cout << number << endl;
    for (int i = 1; i <= number; i++)
    {
        if (i != number)
            cout << i << " ";
        else
            cout << i << endl;
    }
}
void list1(ll number)
{
    if (number == 1)
    {
        cout << 1 << endl
             << 1 << endl;
    }
    else
    {
        cout << number - 1 << endl;
        for (int i = 1; i <= number; i++)
        {
            if (i == number - 1)
                continue;
            if (i != number)
                cout << i << " ";
            else
                cout << i << endl;
        }
    }
}
void list2(ll number)
{
    cout << number - 1 << endl;
    for (int i = 2; i <= number; i++)
    {
        if (i != number)
            cout << i << " ";
        else
            cout << i << endl;
    }
}
void list3(ll number)
{
    cout << number - 1 << endl;
    for (int i = 1; i < number; i++)
    {
        if (i != number - 1)
            cout << i << " ";
        else
            cout << i << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m;
        cin >> m;
        int sodu = m % 4;
        switch (sodu)
        {
        case 0:
            list0(m);
            break;
        case 1:
            list1(m);
            break;
        case 2:
            list2(m);
            break;
        case 3:
            list3(m);
            break;
        default:
            break;
        }
    }
}