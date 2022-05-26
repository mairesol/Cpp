/*
<cctype>(ctype.h)

Character handling functions

This header declares a set of functions to classify and transform individual characters.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main()
{

    //----------------------------------------Character classification functions----------------------------------------//
    // isalnum      Check if character is alphanumeric:  int isalnum(int c);
    int i;
    char str[] = "c3po...";
    i = 0;
    while (isalnum(str[i]))
        i++;
    printf("The first %d characters are alphanumeric.\n", i);
    // The first 4 characters are alphanumeric.

    // isalpha      Check if character is alphabetic:  int isalpha(int c);
    int i = 0;
    char str[] = "C++";
    while (str[i])
    {
        if (isalpha(str[i]))
            printf("character %c is alphabetic\n", str[i]);
        else
            printf("character %c is not alphabetic\n", str[i]);
        i++;
    }
    // character C is alphabetic
    // character + is not alphabetic
    // character + is not alphabetic

    // isblank      Check if character is blank:  int isblank(int c);
    char c;
    int i = 0;
    char str[] = "Example sentence to test isblank\n";
    while (str[i])
    {
        c = str[i];
        if (isblank(c))
            c = '\n';
        putchar(c);
        i++;
    }
    // Example
    // sentence
    // to
    // test
    // isblank

    // iscntrl      Check if character is a control character:   int iscntrl(int c);
    int i = 0;
    char str[] = "first line \n second line \n";
    while (!iscntrl(str[i]))
    {
        putchar(str[i]);
        i++;
    }

    // isdigit      Check if character is decimal digit:     int isdigit(int c);
    char str[] = "1776ad";
    int year;
    if (isdigit(str[0]))
    {
        year = atoi(str);
        printf("The year that followed %d was %d.\n", year, year + 1);
    }
    // The year that followed 1776 was 1777

    // isgraph      Check if character has graphical representation:     int isgraph(int c);
    FILE *pFile;
    int c;
    pFile = fopen("myfile.txt", "r");
    if (pFile)
    {
        do
        {
            c = fgetc(pFile);
            if (isgraph(c))
                putchar(c);
        } while (c != EOF);
        fclose(pFile);
    }

    // islower      Check if character is lowercase letter:  int islower(int c);
    int i = 0;
    char str[] = "Test String.\n";
    char c;
    while (str[i])
    {
        c = str[i];
        if (islower(c))
            c = toupper(c);
        putchar(c);
        i++;
    }
    // TEST STRING.

    // isprint      Check if character is printable:     int isprint(int c);
    int i = 0;
    char str[] = "first line \n second line \n";
    while (isprint(str[i]))
    {
        putchar(str[i]);
        i++;
    }

    // ispunct      Check if character is a punctuation character:   int ispunct(int c);
    int i = 0;
    int cx = 0;
    char str[] = "Hello, welcome!";
    while (str[i])
    {
        if (ispunct(str[i]))
            cx++;
        i++;
    }
    printf("Sentence contains %d punctuation characters.\n", cx);
    // Sentence contains 2 punctuation characters

    // isspace      Check if character is a white-space:     int isspace(int c);
    char c;
    int i = 0;
    char str[] = "Example sentence to test isspace\n";
    while (str[i])
    {
        c = str[i];
        if (isspace(c))
            c = '\n';
        putchar(c);
        i++;
    }
    // Example
    // sentence
    // to
    // test
    // isspace

    // isupper      Check if character is uppercase letter: int isupper(int c);
    int i = 0;
    char str[] = "Test String.\n";
    char c;
    while (str[i])
    {
        c = str[i];
        if (isupper(c))
            c = tolower(c);
        putchar(c);
        i++;
    }
    // test string.

    // isxdigit     Check if character is hexadecimal digit: int isxdigit(int c);
    char str[] = "ffff";
    long int number;
    if (isxdigit(str[0]))
    {
        number = strtol(str, NULL, 16);
        printf("The hexadecimal number %lx is %ld.\n", number, number);
    }
    // The hexadecimal number ffff is 65535.

    //----------------------------------------Character conversion functions----------------------------------------//
    // tolower      Convert uppercase letter to lowercase: int tolower(int c);

    // toupper      Convert lowercase letter to uppercase: int toupper(int c);

    return 0;
}