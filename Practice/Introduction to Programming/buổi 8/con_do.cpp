#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

enum Transportation
{
    civilian = 1,
    police = 2,
    army = 3,
    fire = 4,
    ambulance = 5
};
enum Position
{
    le = -1,
    ri = 1
};

typedef long long ll;

#define MAXCHAR 10000
#define MAXROW 10000
#define MAXCOL 205

void sort_in_pos(ll A[MAXCHAR], Transportation B[MAXCHAR], Position C[MAXCHAR], ll D[MAXCHAR], ll m, Position dir)
{
    for (int i = 0; i <= m - 1; i++)
    {
        if (C[i] != dir)
            continue;
        for (int j = i + 1; j <= m; j++)
        {
            if (C[j] != dir)
                continue;
            if (B[i] < B[j]) // Ưu tiên theo loại phương tiện
            {
                swap(A[i], A[j]);
                swap(B[i], B[j]);
                swap(D[i], D[j]);
            }
            if (D[i] > D[j] && B[i] == B[j]) // Ưu tiên theo thứ tự
            {
                swap(A[i], A[j]);
                swap(B[i], B[j]);
                swap(D[i], D[j]);
            }
        }
    }
}
void output(ll A[MAXCHAR], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    ll l, m;
    cin >> l >> m;
    l = l * 100; // Doi m sang cm

    ll length[MAXCHAR];
    char trans[MAXROW][MAXCOL];
    char pos[MAXROW][MAXCOL];
    ll ord[MAXCHAR];

    Transportation trans_en[MAXCHAR];
    Position pos_en[MAXCHAR];
    for (int i = 0; i < m; i++)
    {
        cin >> length[i] >> trans[i] >> pos[i];
        ord[i] = i;

        // Mã hoá thông tin
        // Phương tiện
        if (strstr(trans[i], "civilian") != NULL)
            trans_en[i] = civilian;
        else if (strstr(trans[i], "police") != NULL)
            trans_en[i] = police;
        else if (strstr(trans[i], "army") != NULL)
            trans_en[i] = army;
        else if (strstr(trans[i], "fire") != NULL)
            trans_en[i] = fire;
        else if (strstr(trans[i], "ambulance") != NULL)
            trans_en[i] = ambulance;
        // Vị trí
        if (strstr(pos[i], "left") != NULL)
            pos_en[i] = le;
        else if (strstr(pos[i], "right") != NULL)
            pos_en[i] = ri;
    }

    sort_in_pos(length, trans_en, pos_en, ord, m, le);
    sort_in_pos(length, trans_en, pos_en, ord, m, ri);

    // Tạo mảng chứa dộ dài bên trái và bên phải
    ll left_length[MAXCHAR];
    ll right_length[MAXCHAR];
    int left = 0, right = 0;
    for (int i = 0; i < m; i++)
    {
        if (pos_en[i] == le)
        {
            left_length[left] = length[i];
            left++;
        }
        else
        {
            right_length[right] = length[i];
            right++;
        }
    }

    ll cntle = 0, cntri = 0;
    // Đếm bên trái
    for (int i = 0; i < left; i++)
    {
        ll sum = left_length[i];
        while (sum + left_length[i + 1] <= l)
        {
            sum += left_length[i + 1];
            i++;
        }
        cntle++;
    }

    // Đếm bên phải
    for (int i = 0; i < right; i++)
    {
        ll sum = right_length[i];
        while (sum + right_length[i + 1] <= l)
        {
            sum += right_length[i + 1];
            i++;
        }
        cntri++;
    }
    if (cntle == cntri)
        cout << cntle + cntri;
    else if (cntle > cntri)
        cout << 2 * cntle - 1;
    else
        cout << 2 * cntri;

    return 0;
}