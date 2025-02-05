#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

    printf("CHARs\n");
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);

    printf("\nINTs\n");
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("LLONG_MAX   :   %lld\n", (long long) LLONG_MAX);
    printf("LLONG_MIN   :   %lld\n", (long long) LLONG_MIN);
    printf("ULLONG_MAX  :   %llu\n", (unsigned long long) ULLONG_MAX);

    printf("\nFLOATs\n");
    printf("FLT_MAX     :   %e\n", FLT_MAX);
    printf("FLT_MIN     :   %e\n", FLT_MIN);
    printf("DBL_MAX     :   %e\n", DBL_MAX);
    printf("DBL_MIN     :   %e\n", DBL_MIN);
    printf("LDBL_MAX    :   %Le\n", LDBL_MAX);
    printf("LDBL_MIN    :   %Le\n", LDBL_MIN);

    return 0;
}
