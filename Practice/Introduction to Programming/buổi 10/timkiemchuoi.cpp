#include <bits/stdc++.h>

using namespace std;

#define MAXROW 10000
#define MAXCOL 205
#define MAX 205

void insert(char str[MAX], char ch, int pos)
{
    for (int i = strlen(str); i > pos; i--)
        str[i] = str[i - 1];
    str[pos] = ch;
}
void lower(char str[MAX])
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}
int main()
{
    char books[MAXROW][MAXCOL];
    int n = 0;
    while (true)
    {
        cin.getline(books[n], MAX);
        if (books[n][0] == '.' && books[n][1] == 0)
            break;
        n++;
    }
    char search[MAX];
    cin.getline(search, MAX);
    lower(search);

    strlen(search);

    for (int i = 0; i < n; i++)
    {
        int leng = strlen(books[i]);

        char temp[MAX] = "";
        strcpy(temp, books[i]);
        lower(temp);
        char *pch = strstr(temp, search);
        if (pch != NULL)
        {
            int first = pch - temp;
            int last = first + strlen(search);
            insert(books[i], ']', last);
            insert(books[i], '[', first);
        }
        cout << books[i] << endl;
    }
    return 0;
}
