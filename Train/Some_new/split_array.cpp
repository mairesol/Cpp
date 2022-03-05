/*Viet mot ham split_matrix cho m, trong do, m la mot mang, xuat ra 2 mang moi la m1, m2, khi ma m1 la nua ben trai cua mang m, m2 la nua ben phai mang m.
Trong truong hop so cot la so le, thi cot o giua se thuoc ve nua ben trai. Cho rang m co it nhat 2 cot.

*/

#include <iostream>
#include <math.h>
using namespace std;
const int MAX_ROW = 100;
const int MAX_COL = 100;

void matrix_input(float A[][MAX_COL], int nrow, int ncol);
void matrix_output(float A[][MAX_COL], int nrow, int ncol);
void split_matrix(float m[][MAX_COL], int m_row, int m_col);

int main()
{
    int m_row, m_col;

    // Nhap so hang, so cot cua m
    do
    {
        cout << "Nhap so hang: ";
        cin >> m_row;
        cout << "Nhap so cot: ";
        cin >> m_col;
    } while (m_row <= 0 || m_col <= 0 || m_row > MAX_ROW || m_col > MAX_COL);

    // Nhap xuat mang m
    float m[MAX_ROW][MAX_COL];
    matrix_input(m, m_row, m_col);
    matrix_output(m, m_row, m_col);
    cout << endl; // Cach cho de nhin

    // Phan chia mang
    split_matrix(m, m_row, m_col);

    return 0;
}

// Ham
void matrix_input(float m[][MAX_COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << "m[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> m[i][j];
        }
    }
}
void matrix_output(float m[][MAX_COL], int m_row, int m_col)
{
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}
void split_matrix(float m[][MAX_COL], int m_row, int m_col)
{
    // Cot phan chia
    int split_col;
    if (m_col % 2 == 0)
    {
        split_col = m_col / 2;
    }
    else
    {
        split_col = m_col / 2 + 1;
    }
    float m1[MAX_ROW][MAX_COL], m2[MAX_ROW][MAX_COL];

    // Chep du lieu tu m vao m1
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < split_col; ++j)
        {
            m1[i][j] = m[i][j]; // Chep cac phan tu m vao m1 tu cot thu nhat toi cot split_col
        }
    }

    // In m1
    matrix_output(m1, m_row, split_col);
    cout << endl; // Cach cho de nhin

    // Chep du lieu tu m vao m2
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_col - split_col; ++j)
        {
            m2[i][j] = m[i][split_col + j]; // Chep cac phan tu m vao m2 sau cot split_col
        }
    }
    // In m2
    matrix_output(m2, m_row, m_col - split_col);
    cout << endl; // Cach cho de nhin
}