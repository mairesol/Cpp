#include <iostream>
using namespace std;
void input(char strs[][1000], int &n)
{
    n = 0;
    while (true)
    {
        cin >> strs[n];
        if (strs[n][0] == '.')
            break;
        n++;
    }
}
bool compare_string(char strs[][1000], int str1, int str2)
{
    for (int i = 0; strs[str1][i] != '\0' || strs[str2][i] != '\0'; i++) // So sánh trong chiều dài của chuỗi dài nhất
        if (strs[str1][i] != strs[str2][i])
            return false;
    return true;
}

int main()
{
    char strs[1000][1000];
    int n;
    input(strs, n);
    for (int i = 0; i < n; i++) // Chạy mảng chuỗi
    {
        bool flag = 1;
        for (int j = 0; j < i; j++) // So sánh với các chuỗi trước
        {
            if (compare_string(strs, j, i) == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << strs[i] << endl;
    }
    return 0;
}
