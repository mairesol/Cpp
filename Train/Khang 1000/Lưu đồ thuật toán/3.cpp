#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int TwoSolution = 2, OneSolution = 1, NoSolution = 0, Undetermined = -1;
long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCD(int num1, int num2)
{
    return num1 * num2 / GCD(num1, num2);
}
void EqualDeg1(double a, double b)
{
    float x = 0;
    int nSolution1;
    if (a != 0)
    {
        x = -b / a;
        nSolution1 = OneSolution; // Phương trình có 1 nghiệm
    }
    else
    {
        if (b == 0)
            nSolution1 = Undetermined; // Phương trình có vô số nghiệm
        else
            nSolution1 = NoSolution; // Phương trình vô nghiệm
    }
    // Xuat ket qua
    if (nSolution1 == 1)
        cout << "Roots of equation: " << x << endl;
    if (nSolution1 == 0)
        cout << "Roots of equation: No solution" << endl;
    if (nSolution1 == -1)
        cout << "Roots of equation: Undetermined" << endl;
}
void EqualDeg2(double a, double b, double c)
{
    float x1 = 0, x2 = 0;
    int nSolution2 = -1; // Neu khong thay doi thi se xuat ket qua theo phuong trinh bac 1
    if (a == 0)
        EqualDeg1(b, c); // Phuong trinh bac 1
    else
    {
        double delta = pow(b, 2) - 4 * a * c;
        if (delta < 0)
            nSolution2 = NoSolution; // Phương trình vô nghiệm
        else if (delta == 0)
        {
            x1 = x2 = -b / (2 * a);
            nSolution2 = OneSolution; // Phương trình có 1 nghiệm kép
        }
        else
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            nSolution2 = TwoSolution; // Phương trình có 2 nghiệm phân biệt
        }
    }
    // Xuat ket qua
    if (nSolution2 == 1)
        cout << "Roots of equation: " << x1 << endl;
    if (nSolution2 == 2)
        cout << "Roots of equation: " << x1 << '\t' << x2 << endl;
    if (nSolution2 == 0)
        cout << "Roots of equation: No solution" << endl;
}
void EqualQuartic(int a, int b, int c)
{
    float x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    float y1 = 0, y2 = 0;
    if (a == 0)
        EqualDeg2(b, 0, c); // Phương trình bậc 2
    else
    {
        double delta = pow(b, 2) - 4 * a * c;
        if (delta < 0)
            cout << "Roots of equation: No solution" << endl; // Phương trình vô nghiệm
        if (delta == 0)                                       // Xet delta = 0
        {
            y1 = y2 = -b / (2 * a);
            if (y1 > 0)
            {
                x1 = sqrt(y1);
                x2 = -sqrt(y1);
                cout << "Roots of equation: " << x1 << '\t' << x2 << endl; // Phương trình có 2 nghiệm
            }
            else if (y1 == 0)
            {
                x1 = 0;
                cout << "Roots of equation: " << x1 << endl; // Phương trình có 1 nghiệm
            }
            else
                cout << "Roots of equation: No solution" << endl; // Phương trình vô nghiệm
        }
        if (delta > 0) // Xet delta > 0
        {
            y1 = (-b - sqrt(delta)) / (2 * a);
            y2 = (-b + sqrt(delta)) / (2 * a);
            if (y1 > 0 && y2 > 0)
            {
                x1 = sqrt(y1);
                x2 = -sqrt(y1);
                x3 = sqrt(y2);
                x4 = -sqrt(y2);
                cout << "Roots of equation: " << x1 << '\t' << x2 << '\t' << x3 << '\t' << x4 << endl; // Phương trình có 4 nghiệm
            }
            if (y1 > 0 && y2 == 0)
            {
                x1 = sqrt(y1);
                x2 = -sqrt(y1);
                x3 = 0;
                cout << "Roots of equation: " << x1 << '\t' << x2 << '\t' << x3 << endl; // Phương trình có 3 nghiệm
            }
            if (y1 > 0 && y2 < 0)
            {
                x1 = sqrt(y1);
                x2 = -sqrt(y1);
                cout << "Roots of equation: " << x1 << '\t' << x2 << endl; // Phương trình có 2 nghiệm
            }
            if (y1 == 0 && y2 > 0)
            {
                x1 = 0;
                x2 = sqrt(y2);
                x3 = -sqrt(y2);
                cout << "Roots of equation: " << x1 << '\t' << x2 << '\t' << x3 << endl; // Phương trình có 3 nghiệm
            }
            if (y1 == 0 && (y2 == 0 || y2 < 0))
            {
                x1 = 0;
                cout << "Roots of equation: " << x1 << endl; // Phương trình có 1 nghiệm
            }
            if (y1 < 0 && y2 > 0)
            {
                x1 = sqrt(y2);
                x2 = -sqrt(y2);
                cout << "Roots of equation: " << x1 << '\t' << x2 << endl; // Phương trình có 2 nghiệm
            }
            if (y1 < 0 && y2 == 0)
            {
                x1 = 0;
                cout << "Roots of equation: " << x1 << endl; // Phương trình có 1 nghiệm
            }
            if (y1 < 0 && y2 < 0)
                cout << "Roots of equation: No solution" << endl; // Phương trình vô nghiệm
        }
    }
}
int main()
{
    int n1, n2;
    do
    {
        cout << "n1: ";
        cin >> n1;
        cout << "n2: ";
        cin >> n2;
    } while (n1 <= 0 || n2 <= 0);
    // Uoc chung lon nhat
    cout << "Greatest common divisor: " << GCD(n1, n2) << endl;
    // Boi chung nho nhat
    cout << "Least common multiple: " << LCD(n1, n2) << endl;
    // Giai phuong trinh bac nhat
    cout << "ax + b = 0" << endl;
    double a1, b1;
    cout << "a: ";
    cin >> a1;
    cout << "b: ";
    cin >> b1;
    EqualDeg1(a1, b1);
    // Giai phuong trinh bac 2
    cout << "ax^2 + bx + c = 0" << endl;
    double a2, b2, c2, x1, x2;
    cout << "a: ";
    cin >> a2;
    cout << "b: ";
    cin >> b2;
    cout << "c: ";
    cin >> c2;
    EqualDeg2(a2, b2, c2);
    // Giai phuong trinh bac 4 trung phuong
    cout << "ax^4 + bx^2 + c = 0" << endl;
    double a4, b4, c4;
    cout << "a: ";
    cin >> a4;
    cout << "b: ";
    cin >> b4;
    cout << "c: ";
    cin >> c4;
    EqualQuartic(a4, b4, c4);
    return 0;
}