#include <stdio.h>

int main(void) {
    char *infname = "quotes.txt";
    char *outfname = "copy.txt";
    char buf[255];

    // Attempt to open input file. Report error on NULL.
    FILE *in = fopen(infname, "r");
    if (in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", infname);
        return 1;
    }

    // Attempt to open output file. Report error on NULL.
    FILE *out = fopen(outfname, "w");
    if (out == NULL) {
        fprintf(stderr, "Unable to open file %s\n", outfname);
        fclose(in);
        return 1;
    }

    while (fgets(buf, sizeof(buf), in) != NULL)
        fprintf(out, "%s", buf);

    // close the files
    fclose(out);
    fclose(in);

    return 0;
}
