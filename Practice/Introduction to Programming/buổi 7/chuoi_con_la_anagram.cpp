#include <iostream>
#include <string.h>

typedef long long ll;
using namespace std;

void delete_char(char str[100000], int pos)
{
    int len = strlen(str);
    for (int i = pos; i < len; i++)
    {
        str[i] = str[i + 1]; // Trong đó str[strlen - 1] = \0
    }
}
bool check_char_and_delete_in_string(char str[100000], char x)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == x)
        {
            delete_char(str, i);
            return true;
        }
    return false;
}
bool check_anagram(char str1[100000], char str2[100000])
{
    char temp[100000];
    strcpy(temp, str1);
    if (strlen(str1) != strlen(str2))
        return 0;
    else
    {
        for (int i = 0; i < strlen(str2); i++)
            if (check_char_and_delete_in_string(temp, str2[i]) == false) // Xoá phần tử vừa tìm dc trong temp
                return 0;
        return 1;
    }
}
void part(char A[100000], char save[100000], int begin, int end)
{
    int j = 0;
    for (int i = begin; i <= end; i++)
    {
        save[j] = A[i];
        j++;
    }
}
int main()
{
    char A[100000];
    char B[100000];
    cin.getline(A, 100000);
    cin.getline(B, 100000);
    for (int i = 0; i < strlen(A); i++)
    {
        char save[100000];
        part(A, save, i, i + strlen(B) - 1);
        if (check_anagram(B, save) == 1)
            cout << save << endl;
    }
}
