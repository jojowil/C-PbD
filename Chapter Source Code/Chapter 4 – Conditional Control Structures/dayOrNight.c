#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool daytime, sunShining;

    sunShining = true;

    if (sunShining == true)
        daytime = true;
    else
        daytime = false;

    printf("sunShining = %d\n", sunShining);
    printf("daytime = %d\n", daytime);
}
