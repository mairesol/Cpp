#include <iostream>
#include <algorithm>
#include <string.h>
typedef long long ll;
using namespace std;
bool is_symmetrical(char str[10000], int begin)
{
    ll length = strlen(str);
    for (int i = 0; i < (length - begin) / 2; i++)
    {
        if (str[i + begin] != str[length - i - 1])
            return false;
    }
    return true;
}
void reverse(char str[10000])
{
    for (int i = 0; i < strlen(str) / 2; i++)
        swap(str[i], str[strlen(str) - i - 1]);
}

int main()
{
    char str[10000];
    cin.getline(str, 10000);
    char storage[10000];
    int index = 0;
    while (is_symmetrical(str, index) == false)
    {
        // Bỏ phần tử đầu vào storage
        storage[index] = str[index];
        index++;
    }
    // Đảo storage
    reverse(storage);
    cout << storage;
}