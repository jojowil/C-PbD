#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char *fname = "quotes.txt";
    char buf[80];
    int lines = 0, words = 0;
    FILE *in;

    // Attempt to open file. Report error on NULL.
    in = fopen(fname, "r");
    if (in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fname);
        return 1;
    }

    // read words - skipping whitespace
    while (fscanf(in, "%79s", buf) == 1) {
        printf("%s ", buf);
        words++;

        // have 5 words been printed?
        if (words > 0 && words % 5 == 0) {
            printf("\n");
            lines++;

            // ok, have 5 lines been printed?
            if (lines % 5 == 0)
                printf("\n");
        }

    }

    // close the file
    fclose(in);

    return 0;
}
