#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool daytime, nighttime;

    bool sun_shining = true;

    if (sun_shining == true) {
        daytime = true;
        nighttime = false;
    } else {
        daytime = false;
        nighttime = true;
    }

    printf("sunShining = %d\n", sun_shining);
    printf("daytime = %d\n", daytime);
    printf("nighttime = %d\n", nighttime);
    return 0;
}
