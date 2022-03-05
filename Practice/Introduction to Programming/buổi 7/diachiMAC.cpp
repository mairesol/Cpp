#include <iostream>
#include <string.h>
using namespace std;
char characterhex[] = "0123456789ABCDEF";

int count_char(char str[], char x)
{
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == x)
            cnt++;
    }
    return cnt;
}
bool check_hyphen(char str[], int pos)
{
    if ((str[pos - 3] == 0 || str[pos - 3] == '-') && (str[pos + 3] == 0 || str[pos + 3] == '-'))
        if ((strchr(characterhex, str[pos - 2]) != NULL) && (strchr(characterhex, str[pos - 1]) != NULL) && (strchr(characterhex, str[pos + 1]) != NULL) && (strchr(characterhex, str[pos + 1]) != NULL))
            return true;
    return false;
}
int main()
{
    while (true)
    {
        char str[1000];
        cin >> str;
        if (str[0] == '.')
            break;
        bool check = true;
        // KT số lượng gạch ngang
        if (count_char(str, '-') != 5)
            check = false;
        // Kiểm tra các khoảng
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '-')
            {
                if (check_hyphen(str, i) == false)
                {
                    check = false;
                    break;
                }
            }
        }
        if (check == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
