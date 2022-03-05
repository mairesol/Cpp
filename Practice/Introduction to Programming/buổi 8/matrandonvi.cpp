#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(int arr[][MAXC], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}
bool isMaTranDonVi(int arr[][MAXC], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
                    return false;
            }
            else
            {
                if (arr[i][j] != 0 || arr[j][i] != 0)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout << std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
