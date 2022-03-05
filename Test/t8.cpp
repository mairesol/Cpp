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
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if (arr[i][j] != 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0)
            break;
    }
    return flag;
}
int main()
{
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout << std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
