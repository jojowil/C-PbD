#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char line[120];

    printf("Enter a string (CTRL-D to end): ");
    while (fgets(line, 120, stdin) != NULL) {
        printf("Input was %lu characters long.\n", strlen(line));
        printf("Enter a string (CTRL-D to end): ");
    }
}
