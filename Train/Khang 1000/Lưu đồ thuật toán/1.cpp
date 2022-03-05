#include <iostream>
#include <math.h>
using namespace std;
void S1(int n)
{
    static int s1;
    for (int i = 0; i <= n; i++)
    {
        s1 += i;
    }
    cout << "S1 = " << s1 << endl;
}
void S2(int n)
{
    static int S2;
    for (int i = 0; i <= n; i++)
    {
        S2 += pow(i, 2);
    }
    cout << "S2 = " << S2 << endl;
}
void S3(int n)
{
    static float s3;
    for (int i = 1; i <= n; i++)
    {
        s3 += pow(i, -1);
    }
    cout << "S3 = " << s3 << endl;
}
void S4(int n)
{
    static float s4;
    for (int i = 1; i <= n; i++)
    {
        s4 += pow(2 * i, -1);
    }
    cout << "S4 = " << s4 << endl;
}
float S5(int n)
{
    static float s5;
    for (int i = 1; i <= n; i++)
    {
        s5 += pow(2 * i + 1, -1);
    }
    cout << "S5 = " << s5 << endl;
}
void S6(int n)
{
    static float s6;
    for (int i = 1; i <= n; i++)
    {
        s6 += pow(i * (i + 1), -1);
    }
    cout << "S6 = " << s6 << endl;
}
void S7(int n)
{
    static float s7;
    for (float i = 1; i <= n; i++)
    { // Khai bao i float
        s7 += i / (i + 1);
    }
    cout << "S7 = " << s7 << endl;
}
void S8(int n)
{
    static float s8;
    for (float i = 1; i <= n; i++)
    { // Khai bao i float
        s8 += (2 * i + 1) / (2 * i + 2);
    }
    cout << "S8 = " << s8 << endl;
}
int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
main()
{
    int n;
    do
    {
        cout << "Nhap n: ";
        cin >> n;
    } while (n < 1 || n != int(n));
    // S1(n) = 1 + 2 + 3 + … + n
    S1(n);
    // S2(n) = 1^2 + 2^2 + … + n^2
    S2(n);
    // S3(n) = 1 + 1/2 + 1/3 + … + 1/n
    S3(n);
    // S4(n) = 1/2 + 1/4 + … + 1/2n
    S4(n);
    // S5(n) = 1 + 1/3 + 1/5 + … + 1/(2n + 1)
    S5(n);
    // S6(n) = 1/1×2 + 1/2×3 +…+ 1/n x (n + 1)
    S6(n);
    // S7(n) = 1/2 + 2/3 + 3/4 + …. + n / n + 1
    S7(n);
    // Tính S8(n) = 1/2 + 3/4 + 5/6 + … + 2n + 1/ 2n + 2
    S8(n);
    // T9(n) = 1 x 2 x 3…x n
    int t9 = factorial(n);
    cout << "T9 = " << t9 << endl;

    return 0;
}
