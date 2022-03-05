#include <iostream>
#include <stdio.h>

using namespace std;

struct FRACTION
{
    int numerator;
    int denominator;
};
struct PERSON
{
    char fullName[25];
    struct PERSON *father, *mother;
};
struct NODE
{
    int value;
    struct NODE *pNext;
};

int *input(int n)
{
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    return p;
}
void output(int *p, int n)
{
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
}
int **allocate(int row, int col)
{
    int **p = new int *[row];
    for (int i = 0; i < row; i++)
        p[i] = new int[col];
    return p;
}

void input(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
}

void output(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    /*
    Pointer to const value: const <kiểu dữ liệu> *<tên biến>
    Const pointers: <kiểu dữ liệu>* const <tên biến>
    Const pointer to a const value: const <kiểu dữ liệu> * const <tên biến>

    */
    int value = 10;
    void *voidPtr = &value;

    // cout << *voidPtr << endl; // lỗi, không thể dereference con trỏ void

    int *intPtr = static_cast<int *>(voidPtr); // ép kiểu thành con trỏ int
    cout << *intPtr << endl;                   // ok

    // int arr[] = {20, 30, 40};
    // int *p = arr;
    // int q;
    // // value of p (20) incremented by 1
    // // and returned
    // q = ++*p;
    // printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d \n",
    //     arr[0], arr[1], *p, q);
    // // value of p (21) is returned
    // // pointer incremented by 1
    // q = *(p++);
    // printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d \n",
    //     arr[0], arr[1], *p, q);
    // // pointer incremented by 1
    // // value returned
    // q = *(++p);
    // printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d \n",
    //     arr[0], arr[1], *p, q);

    // Mảng động 1 chiều
    int size = 3;
    int *arr = new int[size]{3, 5, 7};

    int newSize = 6;
    int *newArr = new int[newSize];

    // Sao chép phần tử
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;   // Xóa mảng hiện tại
    arr = newArr;   // Trỏ sang mảng đã resize
    size = newSize; // Kích thước mảng mới
    /* ... */
    // Giải phóng vùng nhớ
    delete[] arr;
    arr = NULL;

    // // Mảng động 2 chiều
    // // Cấp phát bộ nhớ cho mảng 2 chiều
    // int row, col;
    // cin >> row >> col;
    // int **matrix = allocate(row, col);
    // // Nhập và xuất
    // input(matrix, row, col);
    // output(matrix, row, col);
    // // Giải phóng vùng nhớ
    // for (int i = 0; i < row; i++)
    //     delete[] matrix[i];
    // delete[] matrix;

    // // Con trỏ và struct
    // FRACTION x;
    // x.numerator = 1;
    // x.denominator = 2;
    // cout << x.numerator << "/" << x.denominator << endl;
    // FRACTION *p = &x, *q;
    // p->numerator = 3;
    // p->denominator = 4;
    // cout << x.numerator << "/" << x.denominator << endl;
    // q = p;
    // q->numerator = 2;
    // q->denominator = 3;
    // cout << x.numerator << "/" << x.denominator << endl;
    return 0;
}
