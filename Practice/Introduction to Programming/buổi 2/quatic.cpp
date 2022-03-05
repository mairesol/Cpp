#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    if (a == 0) // Phuong trinh bac 2: bx^2 + c = 0
    {
        if (b != 0) // x^2 = -c/b
        {
            if (-c / b > 0)
            {
                float x1 = -sqrt(-c / b), x2 = sqrt(-c / b);
                cout << "{" << x1 << ", " << x2 << "}"; // 2 nghiệm
            }
            else if (-c / b < 0)
                cout << "Ø";             // Vô nghiệm
            else                         // bx^2 = 0
                cout << "{" << 0 << "}"; // 1 nghiệm
        }
        else // c = 0
        {
            if (c == 0)
                cout << "ℝ";
            else
                cout << "Ø";
        }
    }
    else // Phuong trinh bac 4 trung phuong: ax^4 +  bx^2 + c = 0
    {

        float x1, x2, x3, x4;
        float y1, y2;
        double delta = pow(b, 2) - 4 * a * c;
        if (delta < 0)   // Xet delta < 0
            cout << "Ø"; // Vô nghiệm
        if (delta == 0)  // Xet delta = 0
        {
            y1 = -b / (2 * a);
            if (y1 > 0)
            {
                x1 = -sqrt(y1);
                x2 = sqrt(y1);
                cout << "{" << x1 << ", " << x2 << "}"; //  2 nghiệm
            }
            else if (y1 == 0)
                cout << "{" << 0 << "}"; // 1 nghiệm
            else
                cout << "Ø"; // Vô nghiệm
        }
        if (delta > 0) // Xet delta > 0
        {
            y1 = (-b - sqrt(delta)) / (2 * a);
            y2 = (-b + sqrt(delta)) / (2 * a);
            if (y1 > 0 && y2 > 0)
            {
                if (y2 > y1)
                    swap(y1, y2); // Doi cho lon be
                x1 = -sqrt(y1);
                x2 = -sqrt(y2);
                x3 = sqrt(y2);
                x4 = sqrt(y1);
                cout << "{" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << "}"; // 4 nghiệm
            }
            if (y1 > 0 && y2 == 0)
            {
                x1 = -sqrt(y1);
                x3 = sqrt(y1);
                cout << "{" << x1 << ", " << 0 << ", " << x3 << "}"; // 3 nghiệm
            }
            if (y1 > 0 && y2 < 0)
            {
                x1 = -sqrt(y1);
                x2 = sqrt(y1);
                cout << "{" << x1 << ", " << x2 << "}"; // 2 nghiệm
            }
            if (y1 == 0 && y2 > 0)
            {
                x1 = -sqrt(y2);
                x3 = sqrt(y2);
                cout << "{" << x1 << ", " << 0 << ", " << x3 << "}"; // 3 nghiệm
            }
            if ((y1 == 0 || y1 < 0) && (y2 == 0 || y2 < 0))
                cout << "{" << 0 << "}"; // 1 nghiệm
            if (y1 < 0 && y2 > 0)
            {
                x1 = -sqrt(y2);
                x2 = sqrt(y2);
                cout << "{" << x1 << ", " << x2 << "}"; // 2 nghiệm
            }
            if (y1 < 0 && y2 < 0)
                cout << "Ø"; // Vô nghiệm
        }
    }
    return 0;
}
