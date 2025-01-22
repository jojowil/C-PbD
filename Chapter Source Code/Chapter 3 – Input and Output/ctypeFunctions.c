#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    printf("isalnum('A') = %d\n", isalnum('A'));
    printf("isalpha('A') = %d\n", isalpha('A'));
    printf("islower('A') = %d\n", islower('A'));
    printf("isupper('A') = %d\n", isupper('A'));
    printf("isdigit('A') = %d\n", isdigit('A'));
    printf("isspace('A') = %d\n", isspace('A'));
    printf("toupper('A') = %c\n", toupper('A'));
    printf("tolower('A') = %c\n", tolower('A'));

    return 0;
}
