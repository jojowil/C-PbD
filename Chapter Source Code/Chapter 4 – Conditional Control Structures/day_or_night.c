#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool daytime;
    bool sun_shining = true;

    if (sun_shining == true)
        daytime = true;
    else
        daytime = false;

    printf("sunShining = %d\n", sun_shining);
    printf("daytime = %d\n", daytime);
    return 0;
}
