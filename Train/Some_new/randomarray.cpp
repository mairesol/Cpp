#include <iostream> // header for printing
#include <ctime>    // header for random numbers
#include <cstdlib>  // header for rand
using namespace std;

// return a random number inside the range [min, max]
int randomRange(int min, int max);

// fill randomly the array in range [10, 40]
void fill(int *array, const int N);

// compute the sum of two arrays
int array_sum(const int *a, const int *b, const int N);

// print an array
void print(const int *array, const int N);

// compute the number of elements of the array, that are odd numbers
int number_of_odds(const int *array, const int N);

int main()
{
    int a[100], b[100], N;

    // read size of arrays
    do
    {
        cout << "Input size for arrays (between 0 and 100). Arrays will have the same size\n";
        cin >> N;
    } while (N < 0 || N > 100);

    // call this only once, to seed the random generator
    srand((unsigned int)time(NULL));

    // fill the arrays
    fill(a, N);
    fill(b, N);

    // compute sum of arrays and then print it
    cout << "Sum = " << array_sum(a, b, N) << endl;

    // print both arrays
    print(a, N);
    print(b, N);

    // compute the number of odd elements per array
    cout << "Number of odd elements in array a: " << number_of_odds(a, N) << endl;
    cout << "Number of odd elements in array b: " << number_of_odds(b, N) << endl;

    return 0;
}

// return a random number inside the range [min, max]
int randomRange(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// fill randomly the array in range [10, 40]
void fill(int *array, const int N)
{
    for (int i = 0; i < N; ++i)
        array[i] = randomRange(10, 40);
}

// compute the sum of two arrays
int array_sum(const int *a, const int *b, const int N)
{
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += a[i] + b[i];
    return sum;
}

// print an array
void print(const int *array, const int N)
{
    for (int i = 0; i < N; ++i)
        cout << array[i] << " ";
    cout << endl;
}

// compute the number of elements of the array, that are odd numbers
int number_of_odds(const int *array, const int N)
{
    int number_of_odds = 0;
    for (int i = 0; i < N; ++i)
        if (array[i] % 2 != 0) // if array[i] is NOT even (then it's odd)
            number_of_odds++;
    return number_of_odds;
}