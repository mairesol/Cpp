#include <bits/stdc++.h>

using namespace std;

class fract
{
private:
    long long numer, denom;

public:
    void input()
    {
        cin >> numer >> denom;
    }

    friend fract operator==(fract a, fract b)
    {
        if (a.numer * b.denom == a.denom * b.numer)
            return 1;
        return 0;
    }
};

int main()
{

    int n;
    cin >> n;
    fract *a = new fract[n];

    int wrong = 0;

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        try
        {
            a[index++].input();
        }
        catch (exception e)
        {
            wrong++;
            index--;
        }
    }

    n = index;

    fract min = a[0];
    int _count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].smaller_than(min))
        {
            min = a[i];
            _count = 1;
        }
        else if (a[i] == min)
        {
            _count++;
        }
    }

    cout << min << " is the smallest and appears " << _count << " time(s)";
}
