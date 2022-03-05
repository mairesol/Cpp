/*
Tuy không phổ biến trong tiếng Việt nhưng anagram là một trò chơi quen thuộc trong nhiều ngôn ngữ châu Âu.
Trò chơi này đơn giản là sắp xếp lại thứ tự các chữ cái trong một từ để tạo ra từ mới và
đôi khi có thể tạo ra nhiều với dụ có ý nghĩa ví dụ như trong tiếng Anh,
nếu bạn muốn lắng nghe (listen) thì bạn phải im lặng (silent), trong đó 02 từ silent và listen có cùng các ký tự nhưng được sắp xếp khác nhau.

Bé Cúc mới học tiếng Anh và đang rất thích trò anagram. Tuy nhiên với những từ quá dài
thì việc phát hiện 02 từ có phải là anagram của nhau hay không không phải dễ với con người.
Hai từ muốn là anagram của nhau thì chúng phải được tạo thành từ duy nhất một bộ ký tự, nghĩa là
ký tự này xuất hiện ở từ này bao nhiêu lần cũng phải xuất hiện ở từ kia đúng bấy nhiêu lần.
Hãy viết chương trình kiểm tra anagram giúp bé Cúc

INPUT
02 chuỗi, mỗi chuỗi viết trên một hàng và không có khoảng trắng, tất cả là chữ thường với không quá 100 ký tự

OUTPUT
Nếu 02 chuỗi là anagram, xuất ra YES ngược lại xuất ra NO

VÍ DỤ
Input           Output

waste           YES
sweat

lessened        NO
needlese

*/
#include <iostream>
#include <string.h>
using namespace std;
void delete_char(char str[], int strlen, int pos)
{
    for (int i = pos; i < strlen; i++)
    {
        str[i] = str[i + 1]; // Trong đó str[strlen - 1] = \0
    }
}
bool check_char_and_delete_in_string(char str[], int strlen, char x)
{
    for (int i = 0; i < strlen; i++)
        if (str[i] == x)
        {
            delete_char(str, strlen, i);
            return true;
        }
    return false;
}
bool check_anagram(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
        return 0;
    else
    {
        for (int i = 0; i < strlen(str2); i++)
            if (check_char_and_delete_in_string(str1, strlen(str1), str2[i]) == false)
                return 0;
        return 1;
    }
}
int main()
{
    char str1[10000];
    cin.getline(str1, 10000);
    char str2[10000];
    cin.getline(str2, 10000);
    // Kiem tra tung ki tu cua str2 trong str1
    if (check_anagram(str1, str2) == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}