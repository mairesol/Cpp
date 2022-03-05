#include <iostream>
#include <algorithm>
#include <string.h>

#define MAXROW 1000
#define MAXCOL 1000
#define MAXCHAR 1000

char NUM[MAXCHAR] = "0123456789";

using namespace std;

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

void swapstr(char A[MAXCOL], char B[MAXCOL])
{
    int max_length = (strlen(A) > strlen(B)) ? strlen(A) : strlen(B);
    char temp;
    for (int i = 0; i < max_length; i++)
    {
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }
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

int compare_string(char str1[MAXCHAR], char str2[MAXCHAR])
{
    int i = 0;
    while (strchr(NUM, str1[i]) == NULL && strchr(NUM, str2[i]) == NULL)
    {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        i++;
    }
    char num1[MAXCHAR] = "";
    char num2[MAXCHAR] = "";
    int j1 = i, j2 = i;
    while (strchr(NUM, str1[j1]) != NULL)
        j1++;
    while (strchr(NUM, str2[j2]) != NULL)
        j2++;
    part(str1, num1, i, j1 - 1);
    part(str2, num2, i, j2 - 1);
    long long s1 = atoi(num1), s2 = atoi(num2);
    if (s1 < s2)
        return -1;
    else if (s1 > s2)
        return 1;
    else
        return strcmp(str1, str2);
}

void first(char A[][MAXCOL], int n)
{
    char first[MAXCHAR] = "";
    strcpy(first, A[0]);
    for (int i = 1; i < n; i++)
        if (compare_string(A[i], first) < 0)
            strcpy(first, A[i]);
    cout << first;
}

void last(char A[][MAXCOL], int n)
{
    char last[MAXCHAR] = "";
    strcpy(last, A[0]);
    for (int i = 1; i < n; i++)
        if (compare_string(A[i], last) > 0)
            strcpy(last, A[i]);
    cout << last;
}

int main()
{
    int n;
    char files[MAXROW][MAXCOL];
    input(files, n);
    // output(files, n);
    first(files, n);
    cout << endl;
    last(files, n);
    return 0;
}

/*
hinh 82.jpeg
hinh 10 0.png
hinh @.jpg
anh 68.jpg
hinh 67.jpg
hinh 67.png
hinh 3.jpegf
anh 333.png
anh 0402.png
anh 94.jpeg
anh 45.jpg
hinh 15.jpeg
anh 33.jpeg
hinh 5h.png
.

hinh 82.jpeg
hinh 100.png
hinh 3.jpg
anh 68.jpg
hinh 67.jpg
hinh 67.png
hinh 3.jpeg
anh 33.png
anh 94.jpeg
anh 45.jpg
hinh 15.jpeg
anh 33.jpeg
.

hinh3.jpg
hinh1.jpg
hinh30.jpg
hinh10.jpg
hinh9.jpg
.
 */