#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char name[30] = "William";

    printf("The size of name is %lu\n", sizeof name);
    printf("The value of name is %s\n", name);
    printf("The length of name is %lu.\n", strlen(name));
}
