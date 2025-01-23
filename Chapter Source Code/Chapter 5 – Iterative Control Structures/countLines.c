#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *fname = "quotes.txt";
    char buf[80];
    int count = 0;
    FILE *in;

    in = fopen(fname, "r");
    if (in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fname);
        return 1;
    }

    while (fgets(buf, sizeof(buf), in) != NULL) {
        printf("%s", buf);
        if (strchr(buf, '\n'))
            count++;
    }

    fclose(in);
    printf("\nNumber of lines is %d\n", count);

    return 0;
}
