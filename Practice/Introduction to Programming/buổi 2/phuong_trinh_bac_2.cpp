/*
Viết chương trình Giải phương trình bậc hai ax^2 + bx^2 + c = 0
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float delta = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b != 0)
        {
            float x = -c / b;
            if (x == 0)
                x = int(x);
            cout << "{" << x << "}";
        }
        else
        {
            if (c == 0)
                cout << "ℝ";
            else
                cout << "Ø";
        }
    }
    else
    {
        if (delta < 0)
            cout << "Ø";
        else
        {
            if (delta == 0)
            {
                float x = -b / (2 * a);
                if (x == 0)
                    x = int(x);
                cout << "{" << x << "}";
            }
            else
            {
                float x1 = (-b - sqrt(delta)) / (2 * a);
                float x2 = (-b + sqrt(delta)) / (2 * a);
                if (x1 == 0)
                    x1 = int(x1);
                if (x2 == 0)
                    x2 = int(x2);
                if (x1 > x2)
                    swap(x1, x2);
                cout << "{" << x1 << ", " << x2 << "}";
            }
        }
    }
    return 0;
}