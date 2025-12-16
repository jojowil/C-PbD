#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // pointers to characters.
    char *concat, *another;

    // an initialized string (compile-time).
    char astring[] = "A string of characters";

    // runtime allocation of memory.
    another = strdup(", plus a few more.");

    // calculate total space and allocate enough storage for concatenation.
    size_t total = strlen(astring) + strlen(another) + 1;
    concat = malloc(total * sizeof(char));

    // perform concatenation.
    snprintf(concat, total, "%s%s", astring, another);

    printf("astring (%p) = %s\n", astring, astring);
    printf("another (%p) = %s\n", another, another);
    printf("concat  (%p) = %s\n", concat, concat);

    // free everything we allocated at runtime.
    free(concat);
    free(another);

    return 0;
}
