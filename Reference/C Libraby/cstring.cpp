/*
<cstring> (string.h)

C Strings

This header file defines several functions to manipulate C strings and arrays.
*/

/*
Types:
size_t: Unsigned integral typ
*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
struct
{
    char name[40];
    int age;
} person, person_copy;

int main()
{
    /*
    Copying:
    memcpy      Copy block of memory:   void * memcpy ( void * destination, const void * source, size_t num );

    memmove     Move block of memory:    void * memmove ( void * destination, const void * source, size_t num );

    strcpy      Copy string:    char * strcpy ( char * destination, const char * source );

    strncpy     Copy characters from string:    char * strncpy ( char * destination, const char * source, size_t num );
    */

    char myname[] = "Pierre de Fermat";

    /* using memcpy to copy string: */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 46;

    /* using memcpy to copy structure: */
    memcpy(&person_copy, &person, sizeof(person));

    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
    // person_copy: Pierre de Fermat, 46

    char str[] = "memmove can be very useful......";
    memmove(str + 20, str + 15, 11);
    puts(str);
    // memmove can be very very useful.

    char str1[] = "Sample string";
    char str2[40];
    char str3[40];
    strcpy(str2, str1);
    strcpy(str3, "copy successful");
    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
    // str1: Sample string
    // str2: Sample string
    // str3: copy successful

    /*
    Concatenation:
    strcat      Concatenate strings:    char * strcat ( char * destination, const char * source );

    strncat     Append characters from string:  char * strncat ( char * destination, const char * source, size_t num );
    */
    char str[80];
    strcpy(str, "these ");
    strcat(str, "strings ");
    strcat(str, "are ");
    strcat(str, "concatenated.");
    puts(str);

    /*
    Comparison:
    memcmp      Compare two blocks of memory:   int memcmp ( const void * ptr1, const void * ptr2, size_t num );

    strcmp      Compare two strings:    int strcmp ( const char * str1, const char * str2 );

    strcoll     Compare two strings using locale:    int strcoll ( const char * str1, const char * str2 );

    strncmp     Compare characters of two strings:  int strncmp ( const char * str1, const char * str2, size_t num );

    strxfrm     Transform string using locale:  size_t strxfrm ( char * destination, const char * source, size_t num );
    */
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";

    int n;

    n = memcmp(buffer1, buffer2, sizeof(buffer1));

    if (n > 0)
        printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
    else if (n < 0)
        printf("'%s' is less than '%s'.\n", buffer1, buffer2);
    else
        printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
    // 'DWgaOtP12df0' is greater than 'DWGAOTP12DF0'.

    /*
    Searching:
    memchr      Locate character in block of memory:  const void * memchr ( const void * ptr, int value, size_t num );    void * memchr ( void * ptr, int value, size_t num );

    strchr      Locate first occurrence of character in string:   const char * strchr ( const char * str, int character );   char * strchr ( char * str, int character );

    strrchr     Locate last occurrence of character in string:   const char * strrchr ( const char * str, int character );     char * strrchr ( char * str, int character );

    strcspn     Get span until character in string:  size_t strcspn ( const char * str1, const char * str2 );

    strspn      Get span of character set in string:     size_t strspn ( const char * str1, const char * str2 );

    strpbrk     Locate characters in string:    const char * strpbrk ( const char * str1, const char * str2 );    char * strpbrk ( char * str1, const char * str2 );

    strstr      Locate substring:     const char * strstr ( const char * str1, const char * str2 );     char * strstr (       char * str1, const char * str2 );

    strtok      Split string into tokens:     char * strtok ( char * str, const char * delimiters );
    */
    char *pch;
    char str[] = "Example string";
    pch = (char *)memchr(str, 'p', strlen(str));
    if (pch != NULL)
        printf("'p' found at position %d.\n", pch - str + 1);
    else
        printf("'p' not found.\n");
    // 'p' found at position 5.

    char str[] = "This is a sample string";
    char *pch;
    printf("Looking for the 's' character in \"%s\"...\n", str);
    pch = strchr(str, 's');
    while (pch != NULL)
    {
        printf("found at %d\n", pch - str + 1);
        pch = strchr(pch + 1, 's');
    }
    // Looking for the 's' character in "This is a sample string"...
    // found at 4
    // found at 7
    // found at 11
    // found at 18

    char str[] = "This is a sample string";
    char *pch;
    pch = strrchr(str, 's');
    printf("Last occurence of 's' found at %d \n", pch - str + 1);
    // Last occurrence of 's' found at 18

    char str[] = "fcba73";
    char keys[] = "1234567890";
    int i;
    i = strcspn(str, keys);
    printf("The first number in str is at position %d.\n", i + 1);
    // The first number in str is at position 5

    int i;
    char strtext[] = "129th";
    char cset[] = "1234567890";

    i = strspn(strtext, cset);
    printf("The initial number has %d digits.\n", i);
    // The initial number has 3 digits.

    char str[] = "This is a sample string";
    char key[] = "aeiou";
    char *pch;
    printf("Vowels in '%s': ", str);
    pch = strpbrk(str, key);
    while (pch != NULL)
    {
        printf("%c ", *pch);
        pch = strpbrk(pch + 1, key);
    }
    // Vowels in 'This is a sample string': i i a a e i

    char str[] = "This is a simple string";
    char *pch;
    pch = strstr(str, "simple");
    if (pch != NULL)
        strncpy(pch, "sample", 6);
    puts(str);
    // This is a sample string

    char str[] = "- This, a sample string.";
    char *pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }
    // Splitting string "- This, a sample string." into tokens:
    // This
    // a
    // sample
    // string

    /*
    Others:
    memset      Fill block of memory:     void * memset ( void * ptr, int value, size_t num );

    strerror    Get pointer to error message string:

    strlen      Get string length:
    */
    char str[] = "almost every programmer should know memset!";
    memset(str, '-', 6);
    puts(str);
    // ------ every programmer should know memset!

    char szInput[256];
    printf("Enter a sentence: ");
    cin.getline(szInput, 256);
    printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szInput));
    // Enter sentence: just testing
    // The sentence entered is 12 characters long.
    return 0;
}