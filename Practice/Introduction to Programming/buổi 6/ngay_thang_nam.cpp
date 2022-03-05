#include <iostream>

int main()
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, year;
    std::cin >> month >> year;
    std::cout << day_of_month[month - 1] + ((month == 2) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
    return 0;
}
