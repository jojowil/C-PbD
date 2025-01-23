#include <stdio.h>

int main(int argc, char *argv[]) {

    char line[100];

    // Display the prompt, loop until EOF.
    printf("cmd> ");
    while (fgets(line, sizeof line, stdin) != NULL) {
        // do something
        printf("cmd> ");
    }

    return 0;
}
