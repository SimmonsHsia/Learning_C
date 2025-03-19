#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{    
    int i = '\016';

    printf("signed char的取值范围为: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char的取值范围为: 0 ~ %u\n", UCHAR_MAX);

    printf("signed short的取值范围为: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short的取值范围为: %d ~ %u\n", 0, USHRT_MAX);

    printf("signed int的取值范围为: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("unsigned int的取值范围为: %d ~ %u\n", 0, UINT_MAX);

    printf("signed long的取值范围为: %d ~ %d\n", LONG_MIN, LONG_MAX);
    printf("unsigned long的取值范围为: %d ~ %u\n", 0, ULONG_MAX);
    return 0;
}
