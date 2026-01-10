#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char *fname = "quotes.txt";
    char buf[80], *line, *p;
    int inuse = 0;
    int count = 0, words = 0, total_words = 0;

    // Attempt to open file. Report error on NULL.
    FILE *in = fopen(fname, "r");
    if (in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fname);
        return 1;
    }

    int len = sizeof buf;
    if (!(line = malloc(len * sizeof(char)))) {
        fprintf(stderr, "Cannot allocate initial buffer of %d chars.\n", len);
        return 1;
    }

    while (fgets(buf, sizeof(buf), in) != NULL) {
        printf("%s", buf);

        // check we have enough room.
        int l = strlen(buf);
        if (len - inuse < l) {
            len += sizeof buf;
            if (!(p = realloc(line, len * sizeof(char)))) {
                fprintf(stderr, "Cannot realloc buffer to %d chars.\n", len);
                free(line);
                return 1;
            }
            line = p;
        }

        // add to line
        snprintf(line + inuse, l, "%s", buf);
        inuse += l;

        // when we see a newline, we can start looking for words!
        if (strchr(buf, '\n')) {
            count++;

            // state: 1 means we are in a word.
            int state = 0;
            p = line;
            while (*p) {
                if (isspace(*p))
                    state = 0;
                else if (!state) {
                    state = 1;
                    words++;
                }
                p++;
            }
            printf("Words in this line is %d\n", words);
            total_words += words;

            // reset to empty line
            line[0] = '\0';
            inuse = 0;
            words = 0;
        }
    }

    // close the file
    fclose(in);
    free(line);
    printf("Total number of lines is %d\n", count);
    printf("Total number of words is %d\n", total_words);

    return 0;
}
