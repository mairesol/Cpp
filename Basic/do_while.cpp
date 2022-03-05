#include <iostream>
using namespace std;

int main() {
    // program to find the sum of positive numbers
    // if the user enters a negative number, the loop ends
    // the negative number entered is not added to the sum
    int number;
    int sum = 0;
    while (number >= 0) { // take input again if the number is positive
        // all positive numbers
        sum += number;
        cout << "Enter a number: ";
        cin >> number;
    }
    // display the sum
    cout << "\nThe sum is " << sum << endl;
    
    int i = 1; 
    // do...while loop from 1 to 5
    do {
        cout << i << " ";
        ++i;
    }
    while (i <= 5);
    
    return 0;
}