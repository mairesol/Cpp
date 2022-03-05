#include <iostream>
using namespace std;
const int MAX_ROW = 100;
const int MAX_COL = 100;
// Array va string mac dinh la tham chieu
void matrix_input(int A[][MAX_COL], int nrow, int ncol); // Special
void matrix_output(int A[][MAX_COL], int nrow, int ncol);
void matrix_search(int A[][MAX_COL], int nrow, int ncol, int search);
void swap_row(int A[][MAX_COL], int nrow, int ncol, int first_row, int second_row);
void swap_col(int A[][MAX_COL], int nrow, int ncol, int first_col, int second_col);
void swap_element_transpose(int A[][MAX_COL], int nrow, int ncol, int first_element, int second_element);
void transpose(int A[][MAX_COL], int nrow, int ncol);

int main()
{
    int nrow, ncol;
    do
    {
        cout << "Nhap so hang: ";
        cin >> nrow;
        cout << "Nhap so cot: ";
        cin >> ncol;
    } while (nrow <= 0 || ncol <= 0 || nrow > MAX_ROW || ncol > MAX_COL);
    int A[MAX_ROW][MAX_COL];
    matrix_input(A, nrow, ncol);
    matrix_output(A, nrow, ncol);
    // Tim vi tri phan tu co gia tri can tim
    int search;
    cout << "Nhap gia tri can tim: ";
    cin >> search;
    cout << "Vi tri: ";
    matrix_search(A, nrow, ncol, search);
    // Hoan vi 2 hang
    cout << "\nHOAN VI 2 HANG\n";
    int first_row, second_row;
    do
    {
        cout << "Nhap hang thu nhat: ";
        cin >> first_row;
        cout << "Nhap hang thu hai: ";
        cin >> second_row;
    } while (first_row < 0 || second_row < 0 || first_row > nrow || second_row > nrow);
    swap_row(A, nrow, ncol, first_row, second_row);
    matrix_output(A, nrow, ncol);
    // Hoan vi 2 cot
    cout << "HOAN VI 2 COT\n";
    int first_col, second_col;
    do
    {
        cout << "Nhap cot thu nhat: ";
        cin >> first_col;
        cout << "Nhap cot thu hai: ";
        cin >> second_col;
    } while (first_col < 0 || second_col < 0 || first_col > ncol || second_col > ncol);
    swap_col(A, nrow, ncol, first_col, second_col);
    matrix_output(A, nrow, ncol);
    // Chuyen vi
    cout << "CHUYEN VI\n";
    transpose(A, nrow, ncol);
    return 0;
}
void matrix_input(int A[][MAX_COL], int nrow, int ncol)
{
    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}
void matrix_output(int A[][MAX_COL], int nrow, int ncol)
{
    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}
void matrix_search(int A[][MAX_COL], int nrow, int ncol, int search)
{
    int count_result = 0;
    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            if (A[i][j] == search)
            {
                cout << "[" << i << "]"
                     << "[" << j << "]\t";
                count_result += 1;
            }
        }
    }
    if (count_result == 0)
    {
        cout << "Ko co gia tri can tim.";
    }
}
void swap_row(int A[][MAX_COL], int nrow, int ncol, int first_row, int second_row)
{
    for (int i = 0; i < ncol; i++)
    {
        int temp = A[first_row][i];
        A[first_row][i] = A[second_row][i];
        A[second_row][i] = temp;
    }
}
void swap_col(int A[][MAX_COL], int nrow, int ncol, int first_col, int second_col)
{
    for (int i = 0; i < nrow; i++)
    {
        int temp = A[i][first_col];
        A[i][first_col] = A[i][second_col];
        A[i][second_col] = temp;
    }
}
void swap_element_transpose(int A[][MAX_COL], int nrow, int ncol, int row, int col)
{
    int temp = A[row][col];
    A[row][col] = A[col][row];
    A[col][row] = temp;
}
void transpose(int A[][MAX_COL], int nrow, int ncol)
{
    for (int j = 0; j < ncol; j++)
    {
        for (int i = 0; i < nrow; i++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}