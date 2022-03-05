/*
<cstdio> (stdio.h)

C library to perform Input/Output operations

Input and Output operations can also be performed in C++ using the C Standard Input and Output Library (cstdio, known as stdio.h in the C language).
This library uses what are called streams to operate with physical devices such as keyboards, printers,
terminals or with any other type of files supported by the system. Streams are an abstraction to interact with these in an uniform way;
All streams have similar properties independently of the individual characteristics of the physical media they are associated with.

Streams are handled in the cstdio library as pointers to FILE objects.
A pointer to a FILE object uniquely identifies a stream, and is used as a parameter in the operations involving that stream.

There also exist three standard streams: stdin, stdout and stderr, which are automatically created and opened for all programs using the library.
*/

/*
Types:
FILE: Object containing information to control a stream

fpos_t: Object containing information to specify a position within a file

size_t: Unsigned integral type
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    Operations on files:
    remove      Remove file:  int remove ( const char * filename );

    rename      Rename file:  int rename ( const char * oldname, const char * newname );

    tmpfile     Open a temporary file:   FILE * tmpfile ( void );

    tmpnam      Generate temporary filename:  char * tmpnam ( char * str );
    */

    if (remove("myfile.txt") != 0)
        perror("Error deleting file: No such file or directory");
    else
        puts("File successfully deleted");

    int result;
    char oldname[] = "oldname.txt";
    char newname[] = "newname.txt";
    result = rename(oldname, newname);
    if (result == 0)
        puts("File successfully renamed");
    else
        perror("Error renaming file: Permission denied");

    /*
    File access:
    fclose      Close file:   int fclose ( FILE * stream );

    fflush      Flush stream:     int fflush ( FILE * stream );

    fopen       Open file:  FILE * fopen ( const char * filename, const char * mode );
                                                                "r"	read
                                                                "w"	write
                                                                "a"	append
                                                                "r+" read/update
                                                                "w+" write/update
                                                                "a+" append/update

    freopen     Reopen stream with different file or mode:   FILE * freopen ( const char * filename, const char * mode, FILE * stream );

    setbuf      Set stream buffer:    void setbuf ( FILE * stream, char * buffer );

    setvbuf    Change stream buffering:     int setvbuf ( FILE * stream, char * buffer, int mode, size_t size );
    */

    FILE *pFile;
    char mybuffer[80];
    pFile = fopen("example.txt", "r+");
    if (pFile == NULL)
        perror("Error opening file");
    else
    {
        fputs("test", pFile);
        fflush(pFile); // flushing or repositioning required
        fgets(mybuffer, 80, pFile);
        puts(mybuffer);
        fclose(pFile);
    }

    freopen("myfile.txt", "w", stdout);
    printf("This sentence is redirected to a file.");
    fclose(stdout);

    /*
    Formatted input/output:
    fprintf     Write formatted data to stream:  int fprintf ( FILE * stream, const char * format, ... );

    fscanf      Read formatted data from stream:  int fscanf ( FILE * stream, const char * format, ... );

    printf      Print formatted data to stdout:   int printf ( const char * format, ... );

    scanf       Read formatted data from stdin:    int scanf ( const char * format, ... );

    snprintf    Write formatted output to sized buffer:     int snprintf ( char * s, size_t n, const char * format, ... );

    sprintf     Write formatted data to string:  int sprintf ( char * str, const char * format, ... );

    sscanf      Read formatted data from string:  int sscanf ( const char * s, const char * format, ...);

    vfprintf    Write formatted data from variable argument list to stream:   int vfprintf ( FILE * stream, const char * format, va_list arg );

    vfscanf     Read formatted data from stream into variable argument list:   int vfscanf ( FILE * stream, const char * format, va_list arg );

    vprintf     Print formatted data from variable argument list to stdout:  int vprintf ( const char * format, va_list arg );

    vscanf      Read formatted data into variable argument list:  int vscanf ( const char * format, va_list arg );

    vsnprintf   Write formatted data from variable argument list to sized buffer:  int vsnprintf (char * s, size_t n, const char * format, va_list arg );

    vsprintf    Write formatted data from variable argument list to string:   int vsprintf (char * s, const char * format, va_list arg );

    vsscanf     Read formatted data from string into variable argument list:   int vsscanf ( const char * s, const char * format, va_list arg );
    */

    /*
    Character input/output:
    fgetc       Get character from stream:     int fgetc ( FILE * stream );

    fgets       Get string from stream:    char * fgets ( char * str, int num, FILE * stream );

    fputc       character to stream:     int fputc ( int character, FILE * stream );

    fputs       string to stream:    int fputs ( const char * str, FILE * stream );

    getc        Get character from stream:  int getc ( FILE * stream );

    getchar     Get character from stdin:    int getchar ( void );

    gets        Get string from stdin:  char * gets ( char * str );

    putc        Write character to stream:  int putc ( int character, FILE * stream );

    putchar     Write character to stdout:   int putchar ( int character );

    puts        Write string to stdout:  int puts ( const char * str );

    ungetc      Unget character from stream:  int ungetc ( int character, FILE * stream );
    */

    /*
    fread       Read block of data from stream:    size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );

    fwrite      Write block of data to stream:    size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
    */

    /*
    File positioning:
    fgetpos    Get current position in stream:  int fgetpos ( FILE * stream, fpos_t * pos );

    fseek       Reposition stream position indicator:  int fseek ( FILE * stream, long int offset, int origin );

    fsetpos    Set position indicator of stream:    int fsetpos ( FILE * stream, const fpos_t * pos );

    ftell      Get current position in stream:    long int ftell ( FILE * stream );

    rewind     Set position of stream to the beginning:  void rewind ( FILE * stream );
    */

    /*
    Error-handling:
    clearerr    Clear error indicators:     void clearerr ( FILE * stream );

    feof        Check end-of-file indicator:    int feof ( FILE * stream );

    ferror      Check error indicator:    int ferror ( FILE * stream );

    perror      Print error message:  void perror ( const char * str );
    */

    return 0;
}