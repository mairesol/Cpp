#include <stdio.h>
#include <limits.h>

int main()
{

    printf("So bit de bieu dien mot byte la %d\n", CHAR_BIT);

    printf("Gia tri nho nhat cua SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("Gia tri lon nhat cua SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("Gia tri lon nhat cua UNSIGNED CHAR = %d\n", UCHAR_MAX);

    printf("Gia tri nho nhat cua SHORT INT = %d\n", SHRT_MIN);
    printf("Gia tri lon nhat cua SHORT INT = %d\n", SHRT_MAX);

    printf("Gia tri nho nhat cua INT = %d\n", INT_MIN);
    printf("Gia tri lon nhat cua INT = %d\n", INT_MAX);

    printf("Gia tri nho nhat cua CHAR = %d\n", CHAR_MIN);
    printf("Gia tri lon nhat cua CHAR = %d\n", CHAR_MAX);

    printf("Gia tri nho nhat cua LONG = %ld\n", LONG_MIN);
    printf("Gia tri lon nhat cua LONG = %ld\n", LONG_MAX);

    return (0);
}