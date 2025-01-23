#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char choice;
    bool valid;

    valid = false;
    do {
        printf("\nPlease select a menu option.\n\n");

        printf("Choices:\n");
        printf("\tC) County Maps\n");
        printf("\tM) Municipalities\n");
        printf("\tT) Thermal Images\n");
        printf("\tU) Utilities\n");
        printf("\n\tQ) Quit\n");

        printf("\n\nChoice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        switch (choice) {
            case 'C':
            case 'M':
            case 'T':
            case 'U':
            case 'Q':
                valid = true;
                break;
            default:
                printf("The choice \"%c\" is not valid.", choice);
                break;
        }
    } while (!valid);
}
