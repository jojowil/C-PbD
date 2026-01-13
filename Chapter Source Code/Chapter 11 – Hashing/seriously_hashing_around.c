#include <stdio.h>
#include <string.h>

/* K&R 1st edition Hash */
int KnR_1st(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = h + s[x];

    if (h < 0)
        h = -h;

    return h;
}

/* K&R 2nd edition Hash */
int KnR_2nd(const char * s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 5) - h + s[x]; // h * 31 + c

    if (h < 0)
        h = -h;

    return h;
}

/* sdbm Hash - Historically from Sleepycat's Berkeley DB. */
int sdbm(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 6) + (h << 16) - h + s[x]; // h * 65599 + c

    if (h < 0)
        h = -h;

    return h;
}

/* Knuth's Multiplicative Hash - good for numeric key distribution. */
int Knuth_mult(int i) {
    // 1001 1110 0011 0111 0111 1001 1011 0001
    return i * 0x9E3779B1;
}

/* Dan Bernstein's djb2 Hash starting at 5381 with 33 multiplier. */
int djb2_Bernstein(const char * s) {
    int h = 5381;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 5) + h + s[x]; // h * 33 + c

    if (h < 0)
        h = -h;

    return h;
}

int main(void) {
    const int BUCKETS = 181;
    char *words[] = {"XYLOPHONE", "POTATO", "BOOTPRINT", "RING", "Ring", "ring", "COMMIT"};
    int n = sizeof(words) / sizeof(char *);

    for (int i = 0; i < n; i++) {
        char *w = words[i];
        // change the hash function to see how things move around.
        int h = sdbm(w);
        int b = h % BUCKETS;

        printf("%s has a hash value of %d and exists in bucket %d.\n", w, h, b);
    }
    return 0;
}
