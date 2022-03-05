#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (number > 0)
        cout << "You entered a positive number.\n";
    else if (number < 0)
        cout << "You entered a negative number.\n";
    else
        cout << "You entered zero.\n";

    int num;
    cout << "Enter an integer: ";
    cin >> num;

    // outer if condition
    if (num != 0)
    {

        // inner if condition
        if ((num % 2) == 0)
        {
            cout << "The number is even." << endl;
        }
        // inner else condition
        else
        {
            cout << "The number is odd." << endl;
        }
    }
    // outer else condition
    else
    {
        cout << "The number is 0 and it is neither even nor odd." << endl;
    }
    cout << "This line is always printed." << endl;

    // Ternary Operator
    // condition ? expression1 : expression2;
    double marks;

    // take input from users
    cout << "Enter your marks: ";
    cin >> marks;

    // ternary operator checks if
    // marks is greater than 40
    string result = (marks >= 40) ? "passed" : "failed";

    cout << "You " << result << " the exam.";

    return 0;
}