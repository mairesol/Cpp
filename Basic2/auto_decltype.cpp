#include <iostream>
using namespace std;

int main()
{
    auto x = 0;
    auto max_of_int64 = INT64_MAX;
    auto PI = 3.14;
    auto character = 'V';
    auto my_name = "Le Tran Dat";

    cout << "Type of x: " << typeid(x).name() << endl;
    cout << "Type of max_of_int64: " << typeid(max_of_int64).name() << endl;
    cout << "Type of PI: " << typeid(PI).name() << endl;
    cout << "Type of character: " << typeid(character).name() << endl;
    cout << "Type of my_name: " << typeid(my_name).name() << endl;

    int i_value;
    decltype(i_value) what_is_this = 5;

    cout << typeid(what_is_this).name() << endl; // int
}