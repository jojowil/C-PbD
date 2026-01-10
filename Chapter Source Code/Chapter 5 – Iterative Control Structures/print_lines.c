#include <stdio.h>

int main(void) {
    char *fname = "quotes.txt";
    char buf[255];

    // Attempt to open file. Report error on NULL.
    FILE *in = fopen(fname, "r");
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
