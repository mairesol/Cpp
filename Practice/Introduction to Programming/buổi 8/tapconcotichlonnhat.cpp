#include <bits/stdc++.h>

int max(int arr[10000], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        max = (arr[i] > max) ? arr[i] : max;
    return max;
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Xác định thành phần dương, âm, không
    vector<int> arrpos;
    vector<int> arrnega;
    bool checkzero = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            arrpos.push_back(arr[i]);
        else if (arr[i] < 0)
            arrnega.push_back(arr[i]);
        else
            checkzero = true;
    }

    // Tính toán dựa trên các thành phần
    int multipos = 1;
    for (int i = 0; i < arrpos.size(); i++)
        multipos *= arrpos[i];

    int multinega = 1;
    for (int i = 0; i < arrnega.size(); i++)
        multinega *= arrnega[i];

    if (arrnega.size() % 2 != 0) // Trường hợp số lượng số âm là số lẻ và lớn hơn 1
        multinega = multinega / *(max_element(arrnega.begin(), arrnega.end()));

    if (arrpos.size() == 0 && arrnega.size() == 1 && checkzero == true) // Trường hợp không có số dương, số lượng số âm là 1 và có số 0
        cout << 0;
    else
        cout << multipos * multinega;
}
