#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// forward declarations
void announce(void);
void print_error(const char *);
int get_random(void);
int power(int, int);

int main(int argc, char *argv[]) {
    announce();
    printf("%d\n", get_random());
    printf("%d\n", power(2,10));
    print_error("something terrible");
}

// no args, no return
void announce(void) {
    srand(time(NULL));
    fprintf(stdout, "The process has begun!\n");
}

// some args no return
void print_error(const char *errstr) {
    fprintf(stderr, "The program encountered a \"%s\" error.\n", errstr);
}

// no args, has return
int get_random(void) {
    return rand();
}

// args and return
int power(int base, int pwr) {
    int x, total=1;
    if ( pwr == 0 )
        return 1;
    for ( x = 1; x <= pwr; x++ )
        total *= base;
    return total;
}
