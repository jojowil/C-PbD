#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char s[] = "Some string!";
    int x = 32, l;
    const double pi = 3.14159;

    printf("         111111111122222222223\n");
    printf("123456789012345678901234567890\n");

    printf("%10d\n", x);
    printf("%-10d\n", x);

    printf("%30s\n", s);
    printf("%-30s\n", s);

    printf("%f\n", pi);
    printf("%10.4f\n", pi);
    printf("%.4f\n", pi);

    l = strlen(s);
    printf("\nThe length of \"%s\" is %d\n", s, l);
    printf("The last char of \"%s\" is '%c'\n", s, s[l - 1]);
}
