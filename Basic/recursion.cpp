

#include <iostream>
using namespace std;

int factorial(int n);
int fibonacci(int n);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;
    // Factorial of n = 1*2*3*...*n
    cout << "Factorial of " << n << " = " << factorial(n);
     // Factorial of Fi(n) 
    cout << "\nFibonacci of Fi(" << n << ") = " << fibonacci(n);
    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
int fibonacci(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) +fibonacci(n-2);
    }
}