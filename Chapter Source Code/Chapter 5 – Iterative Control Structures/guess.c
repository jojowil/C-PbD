#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int randomNumber, guess;
    bool found;

    srand(time(NULL));
    // random number between 1 and 20
    randomNumber = rand() % 20 + 1;

    printf("I'm thinking of a number between 1 and 20.\n");

    found = false;
    while (!found) {
        printf("Guess the value between 1 and 20: ");
        scanf("%d", &guess);

        if (guess == randomNumber)
            found = true;
        else
            printf("It's not %d.\n", guess);
    }

    printf("\nYou got it!\n");
}
