#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Creating a double type variable
    double a = 3.912348239293;

    // Creating a float type variable
    float b = 3.912348239293f;

    // Setting the precision to 12 decimal places
    cout << setprecision(13);

    // Printing the two variables
    cout << "Double Type Number = " << a << endl;
    cout << "Float Type Number = " << b << endl;

    // Creating an exponential double type variable
    double ex1 = 325e+2;

    // Creating an exponential float type variable
    float ex2 = 325e+2f;

    // Displaying output with fixed
    cout << "Displaying Output With fixed:" << endl;
    cout << "Double Type Number 1 = " << fixed << a << endl;
    cout << "Double Type Number 2 = " << fixed << ex1 << endl;
    cout << "Float Type Number 1  = " << fixed << b << endl;
    cout << "Float Type Number 2  = " << fixed << ex2 << endl;

    // Displaying output with scientific
    cout << "\nDisplaying Output With scientific:" << endl;
    cout << "Double Type Number 1 = " << scientific << a << endl;
    cout << "Double Type Number 2 = " << scientific << ex1 << endl;
    cout << "Float Type Number 1  = " << scientific << b << endl;
    cout << "Float Type Number 2  = " << scientific << ex2 << endl;
    return 0;
}