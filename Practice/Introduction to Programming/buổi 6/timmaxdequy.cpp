#include <iostream>
using namespace std;

int largest_input()
{
    int max = 0;
    int n = 0;
    cin >> n;
    if (n != 0)
    {
        int save = largest_input();
        if (n > save)
            max = n;
        else
            max = save;
        return max;
    }
    else
        return max;
}
int main()
{
    cout << largest_input();
}