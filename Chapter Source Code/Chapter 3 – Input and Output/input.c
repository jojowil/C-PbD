#include <stdio.h>

int main(void) {
    int n;
    char name[30];

    printf("Please enter your name: ");
    fgets(name, sizeof name, stdin);

    printf("Please enter a whole number: ");
    scanf("%d", &n);

    printf("Hello, %s, you entered %d\n", name, n);
    return (0);
}
