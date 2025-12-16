#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int reverse(char *s) {
    if (!s) return 0;

    int l = strlen(s);
    if ( l < 1 ) return 0;

    int m = l / 2;
    for (int x = 0; x < m; x++)
        swap(&s[x], &s[l-x-1]);

    return 1;
}

int main(int argc, char *argv[]) {
    char line[] = "Time to save the day!";

    printf("%s\n", line);
    if ( reverse(line) )
        printf("%s\n", line);
    else
        printf("Well, something was not good...\n");
}
