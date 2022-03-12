#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

bool menu_yet = false;

int search(int *, int, int);
int search_min(int *, int);
void search_max_all(int *arr, int n);
int menu();
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Cac chuc nang
    int ans;
    bool flag = true;

    while (flag)
    {
        int choice = menu();
        Sleep(500);
        switch (choice)
        {
        case 1:
            // Xuat
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            break;
        case 2:
            // Tim kiem x
            int x;
            cout << "Nhap x: ";
            cin >> x;
            ans = search(arr, n, x);
            if (ans == -1)
                cout << "Khong tim thay " << x;
            else
                cout << x << " o vi tri " << ans;
            break;
        case 3:
            // Tim vi tri chua gia tri nho nhat
            ans = search_min(arr, n);
            cout << "Gia tri nho nhat o vi tri " << ans;
            break;
        case 4:
            // Tim tat cac cac vi tri co gia tri lon nhat
            search_max_all(arr, n);
            break;
        case 5:
            flag = false;
            cout << "Xin chao.\n";
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
        Sleep(1000);
    }

    return 0;
}
int menu()
{
    int choice;
    if (menu_yet == false)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon chuc nang tuong ung";
        cout << "\n 1. Xuat mang 1 chieu.";
        cout << "\n 2. Tim kiem gia tri x.";
        cout << "\n 3. Tim kiem vi tri chua gia tri nho nhat.";
        cout << "\n 4. Tim tat ca vi tri chua gia tri lon nhat.";
        cout << "\n 5. Thoat chuong trinh.";
        cout << "\n ================================";
        menu_yet = true;
    }
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

int search(int *arr, int n, int x)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
int search_min(int *arr, int n)
{
    int m = *min_element(arr, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     m = min(arr[i], m);
    // }

    return search(arr, n, m);
}
void search_max_all(int *arr, int n)
{
    int m = *max_element(arr, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     m = max(arr[i], m);
    // }

    cout << "Cac vi tri cua gia tri lon nhat: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
            cout << i << " ";
    }
}