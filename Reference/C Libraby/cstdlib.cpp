/*
<cstdlib>(stdlib.h)

C Standard General Utilities Library

This header defines several general purpose functions, including dynamic memory management,
random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
*/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int compareints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    //----------------------------------------String conversion----------------------------------------//
    // atof            Convert string to double:   double atof(const char *str);
    double n, m;
    double pi = 3.1415926535;
    char buffer[256];
    printf("Enter degrees: ");
    fgets(buffer, 256, stdin);
    n = atof(buffer);
    m = sin(n * pi / 180);
    printf("The sine of %f degrees is %f\n", n, m);
    // Enter degrees: 45
    // The sine of 45.000000 degrees is 0.707101

    // atoi            Convert string to integer:  int atoi(const char *str);
    int i;
    char buffer[256];
    printf("Enter a number: ");
    fgets(buffer, 256, stdin);
    i = atoi(buffer);
    printf("The value entered is %d. Its double is %d.\n", i, i * 2);
    // Enter a number: 73
    // The value entered is 73. Its double is 146.

    // atol            Convert string to long integer:     long int atol(const char *str);

    // atoll           Convert string to long long integer:    long long int atoll(const char *str);

    // strtod          Convert string to double:   double strtod(const char *str, char * *endptr);
    char szOrbits[] = "365.24 29.53";
    char *pEnd;
    double d1, d2;
    d1 = strtod(szOrbits, &pEnd);
    d2 = strtod(pEnd, NULL);
    printf("The moon completes %.2f orbits per Earth year.\n", d1 / d2);
    // The moon completes 12.37 orbits per Earth year.

    // strtof          Convert string to float:    float strtof(const char *str, char * *endptr);

    // strtol          Convert string to long integer:     long int strtol(const char *str, char * *endptr, int base);
    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
    char *pEnd;
    long int li1, li2, li3, li4;
    li1 = strtol(szNumbers, &pEnd, 10);
    li2 = strtol(pEnd, &pEnd, 16);
    li3 = strtol(pEnd, &pEnd, 2);
    li4 = strtol(pEnd, NULL, 0);
    printf("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
    // The decimal equivalents are: 2001, 6340800, -3624224 and 7340031

    // strtold         Convert string to long double:      long double strtold(const char *str, char * *endptr);

    // strtoll         Convert string to long long integer:    long long int strtoll(const char *str, char * *endptr, int base);

    // strtoul         Convert string to unsigned long integer:    unsigned long int strtoul(const char *str, char * *endptr, int base);

    // strtoull        Convert string to unsigned long long integer:   unsigned long long int strtoull(const char *str, char * *endptr, int base);

    // itoa            Convert integer to string(non-standard function):    char * itoa(int value, char *str, int base);
    int i;
    char buffer[33];
    printf("Enter a number: ");
    scanf("%d", &i);
    itoa(i, buffer, 10);
    printf("decimal: %s\n", buffer);
    itoa(i, buffer, 16);
    printf("hexadecimal: %s\n", buffer);
    itoa(i, buffer, 2);
    printf("binary: %s\n", buffer);
    // Enter a number: 1750
    // decimal: 1750
    // hexadecimal: 6d6
    // binary: 11011010110

    //----------------------------------------Pseudo-random sequence generation----------------------------------------//
    // rand        Generate random number:     int rand(void);
    int iSecret, iGuess;
    /*initialize random seed : */
    srand(time(NULL));
    /*generate secret number between 1 and 10 : */
    iSecret = rand() % 10 + 1;
    do
    {
        printf("Guess the number(1 to 10): ");
        scanf("%d", &iGuess);
        if (iSecret < iGuess)
            puts("The secret number is lower");
        else if (iSecret > iGuess)
            puts("The secret number is higher");
    } while (iSecret != iGuess);
    puts("Congratulations!");
    // Guess the number(1 to 10): 5
    // The secret number is higher
    // Guess the number(1 to 10): 8
    // The secret number is lower
    // Guess the number(1 to 10): 7
    // Congratulations!

    // srand       Initialize random number generator:     void srand(unsigned int seed);
    printf("First number: %d\n", rand() % 100);
    srand(time(NULL));
    printf("Random number: %d\n", rand() % 100);
    srand(1);
    printf("Again the first number: %d\n", rand() % 100);
    // First number: 41
    // Random number: 13
    // Again the first number: 41

    //----------------------------------------Dynamic memory management----------------------------------------//
    // calloc      Allocate and zero-initialize array:     void *calloc(size_t num, size_t size);

    // free        Deallocate memory block:    void free(void *ptr);

    // malloc      Allocate memory block:  void *malloc(size_t size);

    // realloc     Reallocate memory block:     void *realloc(void *ptr, size_t size);
    int *buffer1, *buffer2, *buffer3;
    buffer1 = (int *)malloc(100 * sizeof(int));
    buffer2 = (int *)calloc(100, sizeof(int));
    buffer3 = (int *)realloc(buffer2, 500 * sizeof(int));
    free(buffer1);
    free(buffer3);

    //----------------------------------------Environment----------------------------------------//
    // abort               Abort current process:  void abort(void);

    // atexit              Set function to be executed on exit:    int atexit(void(*func)(void))

    // at_quick_exit       Set function to be executed on quick exit:  int at_quick_exit(void(*func)(void));

    // exit                Terminate calling process:  void exit(int status);
    FILE *pFile;
    pFile = fopen("myfile.txt", "r");
    if (pFile == NULL)
    {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }
    else
    {
        /*file operations here */
    }

    // getenv              Get environment string:     char *getenv(const char *name);

    // quick_exit          Terminate calling process quick:    _Noreturn void quick_exit(int status);

    // system              Execute system command:     int system(const char *command);
    int i;
    printf("Checking if processor is available...");
    if (system(NULL))
        puts("Ok");
    else
        exit(EXIT_FAILURE);
    printf("Executing command DIR...\n");
    i = system("dir");
    printf("The value returned was: %d.\n", i);

    // _Exit               Terminate calling process:      void _Exit(int status);

    //----------------------------------------Searching and sorting----------------------------------------//
    // bsearch     Binary search in array:     void *bsearch(const void *key, const void *base, size_t num, size_t size, int(*compar)(const void *,const void *));

    // qsort       Sort elements of array:     void qsort(void *base, size_t num, size_t size, int(*compar)(const void *,const void *));
    int values[] = {50, 20, 60, 40, 10, 30};
    int *pItem;
    int key = 40;
    qsort(values, 6, sizeof(int), compareints);
    pItem = (int *)bsearch(&key, values, 6, sizeof(int), compareints);
    if (pItem != NULL)
        printf("%d is in the array.\n", *pItem);
    else
        printf("%d is not in the array.\n", key);
    // 40 is in the array.

    return 0;
}