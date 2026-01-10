#include <stdio.h>

int main(void) {
    const int guesses = 1;
    char response[80];

    snprintf(response, sizeof response, "You have %d %s remaining.", guesses, guesses > 1 ? "guesses" : "guess");
    printf("%s\n", response);
    return 0;
}
