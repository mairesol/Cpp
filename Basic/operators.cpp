#include <iostream>
using namespace std;

int main()
{
    int a, b;
    a = 1;
    b = 2;

    // printing the sum of a and b
    cout << "a + b = " << (a + b) << endl;

    // printing the difference of a and b
    cout << "a - b = " << (a - b) << endl;

    // printing the product of a and b
    cout << "a * b = " << (a * b) << endl;

    // printing the division of a by b
    cout << "a / b = " << (a / b) << endl;

    // printing the modulo of a by b
    cout << "a % b = " << (a % b) << endl;

    a = 10;
    b = 100;
    int result_a, result_b;

    // incrementing a by 1 and storing the result in result_a
    result_a = ++a;
    cout << "result_a = " << result_a << endl;

    // decrementing b by 1 and storing the result in result_b
    result_b = --b;
    cout << "result_b = " << result_b << endl;

    a = 3;
    b = 5;
    bool result;

    result = (a == b); // false
    cout << "3 == 5 is " << result << endl;

    result = (a != b); // true
    cout << "3 != 5 is " << result << endl;

    result = a > b; // false
    cout << "3 > 5 is " << result << endl;

    result = a < b; // true
    cout << "3 < 5 is " << result << endl;

    result = a >= b; // false
    cout << "3 >= 5 is " << result << endl;

    result = a <= b; // true
    cout << "3 <= 5 is " << result << endl;

    result = (3 != 5) && (3 < 5); // true
    cout << "(3 != 5) && (3 < 5) is " << result << endl;

    result = (3 == 5) && (3 < 5); // false
    cout << "(3 == 5) && (3 < 5) is " << result << endl;

    result = (3 == 5) && (3 > 5); // false
    cout << "(3 == 5) && (3 > 5) is " << result << endl;

    result = (3 != 5) || (3 < 5); // true
    cout << "(3 != 5) || (3 < 5) is " << result << endl;

    result = (3 != 5) || (3 > 5); // true
    cout << "(3 != 5) || (3 > 5) is " << result << endl;

    result = (3 == 5) || (3 > 5); // false
    cout << "(3 == 5) || (3 > 5) is " << result << endl;

    result = !(5 == 2); // true
    cout << "!(5 == 2) is " << result << endl;

    result = !(5 == 5); // false
    cout << "!(5 == 5) is " << result << endl;

    // Toan tu hon hop
    // 'sizeof': returns the size of data type
    cout << "Size of int : " << sizeof(int) << endl;
    // '?:': returns value based on the condition
    string result = (5 > 0) ? "even" : "odd";
    // '&': represents memory address of the operand
    int num = 0;
    int *n = &num;
    // '.': accesses members of struct variables or class objects
    /*s1.marks = 92;*/
    // '->': used with pointers to access the class or struct variables
    /*ptr->marks = 92;*/
    // '<<': prints the output value
    // '>>': gets the input value
    return 0;
}