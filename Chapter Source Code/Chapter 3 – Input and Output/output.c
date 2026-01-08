#include <stdio.h>

int main(int argc, char *argv[]) {
    char name[30];
    snprintf(name, sizeof name, "%s", "John Smith");

    char c = 'L';
    fputc(c, stdout);
    fputc('\n', stdout);

    puts(name);
    printf("%s", name);
    fputs(name, stdout);

    return 0;
}
