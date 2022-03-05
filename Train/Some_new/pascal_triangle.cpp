#include <iostream>
using namespace std;

int factorial(int n);
int combination(int n, int k);

int main()
{
    int line;
    cin >> line;
    cout << "Pascal Triangle";
    for (int i = 0; i <= line; i++)
    {
        for (int j = line; j > i; j--)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
}
int combination(int n, int k)
{
    return factorial(n) / factorial(k) / factorial(n - k);
}