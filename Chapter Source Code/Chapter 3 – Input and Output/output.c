#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char c;
    char name[30];

    snprintf(name, sizeof name, "%s", "John Smith");
    c = 'L';

    fputc(c, stdout);
    fputc('\n', stdout);

    puts(name);
    printf("%s", name);
    fputs(name, stdout);

    return 0;
}
