#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i;
    long l;
    long long ll;

    i = atoi("37");
    printf("%d\n", i);

    l = atol("327875885868");
    printf("%ld\n", l);

    ll = atoll("8923764828768368282");
    printf("%lld\n", ll);

    i = atoi("0");
    printf("%d\n", i);

    i = atoi("garbage");
    printf("%d\n", i);

    return 0;
}
