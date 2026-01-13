#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define num_buckets 11
char *buckets[num_buckets] = {NULL};
int count = 0;

/* K&R 1st edition Hash */
static int KnR_1st(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = h + s[x];

    if (h < 0)
        h = -h;

    return h % num_buckets;
}

/* K&R 2nd edition Hash */
int KnR_2nd(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 5) - h + s[x]; // h * 31 + c

    if (h < 0)
        h = -h;

    return h % num_buckets;
}

// The KnR_2nd() method is a hash function described later.
void put_word(const char *s) {
    int b = KnR_2nd(s);
    buckets[b] = strdup(s);
    printf("%s added to bucket %d.\n", s, b);
    count++;
}

bool exists(const char *s) {
    int b = KnR_2nd(s);
    if (buckets[b] != NULL)
        return true;
    return false;
}

void remove_word(const char *s) {
    int b = KnR_2nd(s);
    buckets[b] = NULL;
}

void hash_dump() {
    printf("Hash Table: size %d, buckets %d:\n", count, num_buckets);
    for (int x = 0; x < num_buckets; x++)
        printf("bucket[%d] -> %s\n", x, buckets[x]);
}

void tear_down() {
    for (int x = 0; x < num_buckets; x++)
        free(buckets[x]);
}

int main(void) {
    char *words[] = {
        "192.168.10.2", "192.168.2.10", "192.168.1.3", "192.168.3.1",
        "192.168.1.6", "192.168.6.1"
    };
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++)
        put_word(words[i]);

    hash_dump();
    tear_down();
    return 0;
}
