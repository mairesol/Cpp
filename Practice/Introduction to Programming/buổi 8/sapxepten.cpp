#include <iostream>
#include <string.h>
using namespace std;

#define MAXROW 100
#define MAXCOL 205
#define MAXCHAR 10000

void input(char A[][MAXCOL], int &n)
{
    n = 0;
    while (true)
    {
        cin.getline(A[n], MAXCOL);
        if (A[n][0] == '.')
            break;
        n++;
    }
}

int first_space(char A[MAXCHAR])
{
    for (int i = 0; i < strlen(A); i++)
        if (A[i] == ' ')
            return i;
    return -1;
}

int last_space(char A[MAXCHAR])
{
    for (int i = strlen(A); i >= 0; i--)
        if (A[i] == ' ')
            return i;
    return -1;
}

void part(char A[MAXCHAR], char a[MAXCHAR], int begin, int end)
{
    int ii = 0;
    for (int i = begin; i <= end; i++)
    {
        a[ii] = A[i];
        ii++;
    }
}
int compare_name(char name1[MAXCHAR], char name2[MAXCHAR])
{
    char sub1[MAXCHAR] = "";
    char sub2[MAXCHAR] = "";
    int start1 = last_space(name1) + 1;
    int start2 = last_space(name2) + 1;
    memmove(sub1, name1 + start1, strlen(name1));
    memmove(sub2, name2 + start2, strlen(name2));

    if (strcmp(sub1, sub2) != 0)
        return strcmp(sub1, sub2);
    else
    {
        char sub1[MAXCHAR] = "";
        char sub2[MAXCHAR] = "";
        memmove(sub1, name1, first_space(name1));
        memmove(sub2, name2, first_space(name2));

        if (strcmp(sub1, sub2) != 0)
            return strcmp(sub1, sub2);
        else
            return strcmp(name1, name2);
    }
}

void first(char A[][MAXCOL], int n)
{
    char first[MAXCHAR];
    strcpy(first, A[0]);
    for (int i = 1; i < n; i++)
        if (compare_name(A[i], first) < 0)
            strcpy(first, A[i]);
    cout << first;
}

void last(char A[][MAXCOL], int n)
{
    char last[MAXCHAR];
    strcpy(last, A[0]);
    for (int i = 1; i < n; i++)
        if (compare_name(A[i], last) > 0)
            strcpy(last, A[i]);
    cout << last;
}

int main()
{
    int n;
    char names[MAXROW][MAXCOL];
    input(names, n);

    first(names, n);
    cout << endl;
    last(names, n);

    return 0;
}
