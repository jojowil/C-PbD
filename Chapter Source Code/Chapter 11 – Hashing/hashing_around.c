#include <stdio.h>
#include <string.h>

int hashValue(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 5) - h + s[x]; // h * 31 + c

    if (h < 0)
        h = -h;

    return h;
}

int main(void) {
    int BUCKETS = 181;
    char *words[] = {"XYLOPHONE", "POTATO", "BOOTPRINT", "RING", "Ring", "ring", "COMMIT"};
    int numberOfWords = sizeof(words) / sizeof(char *);

    for (int i = 0; i < numberOfWords; i++) {
        char *w = words[i];
        int hv = hashValue(words[i]);
        int b = hv % BUCKETS;

        printf("%s has a hash value of %d and exists in bucket %d.\n", w, hv, b);
    }
    return 0;
}
