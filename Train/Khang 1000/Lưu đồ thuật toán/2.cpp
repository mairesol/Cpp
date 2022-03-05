#include <iostream>
#include <math.h>
using namespace std;
void divisors(int number)
{
    int divisors_sum = 0;
    long int divisors_product = 1;
    int count = 0;
    cout << "Divisors: ";
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            cout << i << " ";
            divisors_sum += i;
            divisors_product *= i;
            count++;
        }
    }
    cout << "\nDivisors's sum: " << divisors_sum << endl;
    cout << "Divisors's product: " << divisors_product << endl;
    cout << "Number of divisors: " << count << endl;
}
void perfect_number(int number)
{
    int divisors_sumless = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            divisors_sumless += i;
        }
    }
    if (number == divisors_sumless)
    {
        cout << number << " is perfect number\n";
    }
}
void prime_number(int number)
{
    if (number == 2)
    {
        cout << " 2 is prime number\n";
    }
    else
    {
        bool check = true;
        for (int i = 3; i < number; i++)
        {
            if (number % i == 0)
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            cout << number << " is prime number\n";
        }
    }
}
void square_number(int number)
{
    for (int i = 1; i <= number / 2; i++)
    {
        if (pow(i, 2) == number)
        {
            cout << number << " is square number\n";
        }
    }
}
int sum(int number)
{
    return number * (number + 1) / 2;
}
void count(int number)
{
    int count = 0;
    int temp = number;
    while (temp != 0)
    {
        count++;
        temp /= 10;
    }
    cout << number << " have " << count << " digits\n";
}
void ascending_digits_number(int number)
{
    bool check = true;
    int temp = number;
    int big_digit = 10, next_digit;
    while (temp != 0)
    {
        next_digit = temp % 10;
        temp /= 10;
        if (big_digit < next_digit) // Kiem tra 2 so lien ke
        {
            check = false;
            break;
        }
        else
        {
            big_digit = next_digit; // Cập nhật lại chữ số cho lần so sánh tiếp theo
        }
    }
    if (check == true)
    {
        cout << number << " have ascending digits\n";
    }
}
void descending_digits_number(int number)
{
    bool check = true;
    int temp = number;
    int small_digit = -1, next_digit;
    while (temp != 0)
    {
        next_digit = temp % 10;
        temp /= 10;
        if (small_digit > next_digit) // Kiem tra 2 so lien ke
        {
            check = false;
            break;
        }
        else
        {
            small_digit = next_digit; // Cập nhật lại chữ số cho lần so sánh tiếp theo
        }
    }
    if (check == true)
    {
        cout << number << " have descending digits\n";
    }
}

int main()
{
    int n;
    do
    {
        cout << "Enter positive number: ";
        cin >> n;
    } while (n <= 0);
    // Uoc so
    divisors(n);
    // So hoan thien
    perfect_number(n);
    // So nguyen to
    prime_number(n);
    // So chinh phuong
    square_number(n);
    // Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao cho S(k)  < n. Trong đó chuỗi k được định nghĩa như sau: S(k) = 1 + 2 + 3 + … + k
    int k;
    for (int i = 1; i < n; i++)
    {
        if (sum(i) < n)
        {
            k = i;
        }
    }
    cout << "k = " << k << endl;
    // Dem so luong chu so cua n
    count(n);
    // Chu so tang dan tu trai sang phai
    ascending_digits_number(n);
    // Chu so tang dan tu trai sang phai
    descending_digits_number(n);
    return 0;
}