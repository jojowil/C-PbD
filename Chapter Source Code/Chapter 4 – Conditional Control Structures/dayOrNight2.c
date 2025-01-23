#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    bool daytime, nighttime, sunShining;

    sunShining = true;

    if (sunShining == true) {
        daytime = true;
        nighttime = false;
    } else {
        daytime = false;
        nighttime = true;
    }

    printf("sunShining = %d\n", sunShining);
    printf("daytime = %d\n", daytime);
    printf("nighttime = %d\n", nighttime);
}
