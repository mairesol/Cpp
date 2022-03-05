// Program to build a simple calculator using switch Statement
#include <iostream>
using namespace std;

int main()
{
    char oper;
    static bool select = true;
    float num1, num2;
    cout << "Enter two numbers\n";
    cout << "First: ";
    cin >> num1;
    cout << "Second: ";
    cin >> num2;
    do
    {
        select = true;
        cout << "Enter an operator (+, -, *, /): ";
        cin >> oper;
        switch (oper)
        {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct\n";
            select = false;
            break;
        }
    } while (select == false);
    return 0;
}