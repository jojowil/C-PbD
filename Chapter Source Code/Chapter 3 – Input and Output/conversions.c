#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = atoi("37");
    printf("%d\n", i);

    long l = atol("327875885868");
    printf("%ld\n", l);

    long long ll = atoll("8923764828768368282");
    printf("%lld\n", ll);

    i = atoi("0");
    printf("%d\n", i);

    i = atoi("garbage");
    printf("%d\n", i);

    return 0;
}
