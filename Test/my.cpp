#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

using namespace std;

bool menu_yet = false;
int menu();

void rand_array(int *, int);
void rand_array_inc(int *, int);
void output(int *, int);
int max_element(int *, int);

int linear_search(int *, int, int);
int advanced_linear_search(int *, int, int);
int interpolation_search(int *, int, int, int);
void interchange_sort(int *, int);
void selection_sort(int *, int);
void quick_sort(int *, int, int);

int partition(int *, int, int);

int main()
{
    int n, x, k, l;
    clock_t start, end;
    double time_use;

    cout << "Nhap N: ";
    do
    {
        cin >> n;
    } while (n <= 0);
    int arr[MAX];
    rand_array(arr, n);

    int choice;
    bool flag = true;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "\nCac phan tu cua mang: ";
            output(arr, n);
            break;
        case 2:
            cout << "\nPhan tu lon nhat: " << max_element(arr, n);
            break;
        case 3:
            cout << "\nVi tri phan tu lon nhat: " << advanced_linear_search(arr, n, max_element(arr, n));
            break;
        case 4:
            cout << "\nTat ca vi tri co chua gia tri lon nhat: ";
            k = max_element(arr, n);
            for (int i = 0; i < n; i++)
                if (arr[i] == k)
                    cout << i << " ";
            break;
        case 5:
            cout << "\nNhap x: ";
            cin >> x;
            start = clock();
            k = linear_search(arr, n, x);
            if (k != -1)
                cout << "\nVi tri cua x: " << k;
            else
                cout << "\nKhong tim thay x.";
            end = clock();
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";
            break;
        case 6:
            cout << "\nNhap x: ";
            cin >> x;
            start = clock();
            k = advanced_linear_search(arr, n, x);
            if (k != -1)
                cout << "\nVi tri cua x: " << k;
            else
                cout << "\nKhong tim thay x.";
            end = clock();
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";
            break;
        case 7:
            cout << "\nNhap x: ";
            cin >> x;
            cout << "\nTat ca vi tri co gia tri x: ";
            for (int i = 0; i < n; i++)
                if (arr[i] == x)
                    cout << i << " ";
            break;
        case 8:
            rand_array_inc(arr, n);
            cout << "\nCac phan tu cua mang: ";
            output(arr, n);

            cout << "\nNhap x: ";
            cin >> x;
            start = clock();
            k = 0;
            while (x > arr[k] && k < n)
                k++;
            if (x == arr[k] && k < n)
                cout << "\nVi tri cua x: " << k;
            else
                cout << "\nKhong tim thay x.";
            end = clock();
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";

            cout << "\nTat ca vi tri co gia tri x: ";
            for (int i = k; i < n; i++)
                if (arr[i] == x)
                    cout << i << " ";
                else
                    break;
            break;
        case 9:
            rand_array_inc(arr, n);
            cout << "\nCac phan tu cua mang: ";
            output(arr, n);

            cout << "\nNhap x: ";
            cin >> x;
            start = clock();
            k = interpolation_search(arr, 0, n - 1, x);
            if (k == -1)
                cout << "\nKhong tim thay x.";
            else
            {
                while (k > 0 && x == arr[k - 1])
                    k--;
                cout << "\nVi tri cua x: " << k;
            }
            end = clock();
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";

            cout << "\nTat ca vi tri co gia tri x: ";
            for (int i = k; i < n; i++)
                if (arr[i] == x)
                    cout << i << " ";
                else
                    break;
            break;
        case 10:
            cout << "\nCac cap gia tri trong mang: ";
            quick_sort(arr, 0, n - 1);
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] == arr[i - 1])
                    continue;
                k = -1;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] - arr[i] != k)
                    {
                        cout << " (" << arr[i] << "," << arr[j] << ") ";
                        k = arr[j] - arr[i];
                    }
                }
            }
            break;
        case 11:
            start = clock();
            interchange_sort(arr, n);
            end = clock();
            cout << "Mang sau khi sap xep bang Interchange Sort: ";
            output(arr, n);
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";

            break;
        case 12:
            start = clock();
            selection_sort(arr, n);
            end = clock();
            cout << "Mang sau khi sap xep bang Selection Sort: ";
            output(arr, n);
            time_use = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "\nThoi gian thuc thi: " << time_use << " giay.";
            break;
        case 13:
            ::menu_yet = false;
            break;
        case 14:
            cout << "Chuong trinh ngung hoat dong.\n";
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }

    return 0;
}
// ------------------------------------array------------------------------------ //
void rand_array(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % MAX;
}
void rand_array_inc(int *arr, int n)
{
    srand(time(NULL));
    arr[0] = rand() % MAX;
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + rand() % MAX;
}

void output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int max_element(int *arr, int n)
{
    int re = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > re)
            re = arr[i];

    return re;
}
// ------------------------------------array------------------------------------ //

// ------------------------------------search------------------------------------ //
int linear_search(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int advanced_linear_search(int *arr, int n, int x)
{
    arr[n] = x;
    int i = 0;
    while (arr[i] != x)
        i++;
    if (i < n)
        return i;
    return -1;
}
int interpolation_search(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + ((double)(right - left) * (x - arr[left]) / (arr[right] - arr[left]));
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return interpolation_search(arr, left, mid - 1, x);
        return interpolation_search(arr, mid + 1, right, x);
    }
    return -1;
}
// ------------------------------------search------------------------------------ //

// ------------------------------------sort------------------------------------ //
void interchange_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}
void selection_sort(int *arr, int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
// ------------------------------------sort------------------------------------ //
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[high], arr[i + 1]);
    return i + 1;
}

// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 1. In ra mang.";
        cout << "\n 2. Tim gia tri lon nhat trong mang.";
        cout << "\n 3. Tim vi tri ma tai do co chua gia tri lon nhat.";
        cout << "\n 4. Tim tat ca vi tri co  chua gia tri lon nhat.";
        cout << "\n 5. Tim vi tri co gia tri x duoc nhap tu ban phim bang tim kiem tuyen tinh - tinh thoi gian thuc hien thuat toan.";
        cout << "\n 6. Tim vi tri co gia tri x duoc nhap tu ban phim bang tim kiem tuyen tinh cai tien - tinh thoi gian thuc hien thuat toan.";
        cout << "\n 6. Tim vi tri co gia tri x duoc nhap tu ban phim bang tim kiem tuyen tinh cai tien - tinh thoi gian thuc hien thuat toan.";
        cout << "\n 7. Tim tat ca vi tri co gia tri x duoc nhap tu ban phim.";
        cout << "\n 8. Phat sinh lai mang mot chieu cac so nguyen theo chieu tang dan va su dung cac thuat toan tim kiem tuyen tinh de lam lai cau 5, 6, 7.";
        cout << "\n 9. Phat sinh lai mang mot chieu cac so nguyen theo chieu tang dan va su dung cac thuat toan tim kiem noi suy de lam lai cau 5, 6, 7.";
        cout << "\n 10. Liet ke cac cap gia tri trong mang.";
        cout << "\n 11. Sap xep lai mang ban dau bang thuat toan Interchange Sort - tinh thoi gian thuc hien thuat toan.";
        cout << "\n 12. Sap xep lai mang ban dau bang thuat toan Selection Sort - tinh thoi gian thuc hien thuat toan.";
        cout << "\n 13. Xem lai menu.";
        cout << "\n 14. Thoat chuong trinh.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //