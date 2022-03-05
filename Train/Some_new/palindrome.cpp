#include <iostream>
#include <math.h>
using namespace std;
int count(int number);
int reverse(int number, int count);
void check_palindrome(int num, int reverse);

int main()
{
    // int n, num, digit, rev = 0;

    // cout << "Enter a positive number: ";
    // cin >> num;
    // n = num;
    // do{
    //     digit = num % 10;
    //     rev = (rev * 10) + digit;
    //     num = num / 10;
    // } while (num != 0);
    // cout << "The reverse of the number is: " << reverse << endl;
    // if (number == reverse)
    //     cout << "The number is a palindrome.";
    // else
    //     cout << "The number is not a palindrome.";

    // //My solution
    int number;
    do
    {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number < 0);
    // Kiem tra
    check_palindrome(number, reverse(number, count(number)));
    return 0;
}
int count(int number)
{
    int count = 0;
    do
    {
        number = number / 10;
        count += 1;
    } while (number != 0);
    return count;
}
int reverse(int number, int count)
{
    int reverse = 0;
    for (int i = 1; i <= count; i++)
    {
        reverse += (number % 10) * pow(10, count - i);
        number = number / 10;
    }
    return reverse;
}
void check_palindrome(int number, int reverse)
{
    cout << "The reverse of the number is: " << reverse << endl;
    if (number == reverse)
        cout << "The number is a palindrome.";
    else
        cout << "The number is not a palindrome.";
}