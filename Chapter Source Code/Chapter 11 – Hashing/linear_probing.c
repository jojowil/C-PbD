#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

int KnR_1st(const char *s);
int KnR_2nd(const char *s);

typedef struct ht {
    int num_buckets;
    char **buckets;
    int count;
} HT;

/* Hash wrapper */
int hash(const char *s, int b) {
    return KnR_1st(s) % b;
}

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
int KnR_2nd(const char *s) {
    int h = 0;
    const size_t l = strlen(s);

    for (int x = 0; x < l; x++)
        h = (h << 5) - h + s[x]; // h * 31 + c

    if (h < 0)
        h = -h;

    return h;
}

HT *ht_new(int num_buckets) {
    if (num_buckets <= 0)
        return NULL;
    HT *new_ht = malloc(sizeof(HT));
    if (new_ht != NULL) {
        new_ht->num_buckets = num_buckets;
        new_ht->count = 0;
        new_ht->buckets = calloc((size_t)num_buckets, sizeof(char *));
    }
    return new_ht;
}

size_t ht_size(const HT *ht) {
    return ht->num_buckets;
}

void ht_add(HT *ht, const char *s) {
    int b = hash(s, ht->num_buckets);
    while (b < ht->num_buckets && ht->buckets[b] != NULL)
        b++;
    if (b >= ht->num_buckets) {
        errno = ENOMEM;
        return;
    }
    ht->buckets[b] = strdup(s);
    ht->count++;
    printf("%s added to bucket %d.\n", s, b);
}

bool ht_exists(const HT *ht, const char *s) {
    int b = hash(s, ht->num_buckets);
    while (b < ht->num_buckets && ht->buckets[b] != NULL) {
        if (strcmp(ht->buckets[b],s) == 0)
            return true;
        b++;
    }
    return false;
}

void ht_remove(HT *ht, const char *s) {
    int b = hash(s, ht->num_buckets);
    while (b < ht->num_buckets && ht->buckets[b] != NULL) {
        if (strcmp(ht->buckets[b],s) == 0) {
            ht->buckets[b] = NULL;
            ht->count--;
            return;
        }
        b++;
    }
}

void ht_dump(const HT *ht) {
    printf("Hash Table: size %d, buckets %d:\n", ht->count, ht->num_buckets);
    for (int x = 0; x < ht->num_buckets; x++)
        printf("bucket[%d] -> %s\n", x, ht->buckets[x]);
}

void ht_free(HT *ht) {
    for (int x = 0; x < ht->num_buckets; x++)
        free(ht->buckets[x]);
    free(ht);
}

int main(void) {
    const int BUCKETS = 11;
    char *words[] = {
        "192.168.10.2", "192.168.2.10", "192.168.1.3", "192.168.3.1",
        "192.168.1.6", "192.168.6.1"
    };
    int num_words = sizeof(words) / sizeof(*words);

    HT *ht = ht_new(BUCKETS);
    if (ht) {
        for (int x = 0; x < num_words; x++)
            ht_add(ht, words[x]);

        ht_dump(ht);
        ht_free(ht);
    }
}