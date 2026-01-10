#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char *fname = "quotes.txt";
    char buf[255];
    FILE *in;

    // Attempt to open file. Report error on NULL.
    in = fopen(fname, "r");
    if (in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fname);
        return 1;
    }

    while (fgets(buf, sizeof(buf), in) != NULL)
        printf("%s", buf);

    // close the file
    fclose(in);

    return 0;
}
