#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

int KnR_1st(const char *s);
int KnR_2nd(const char *s);

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

typedef struct htn {
    char *data;
    struct htn *next;
} HTNODE;

typedef struct ht {
    int num_buckets;
    HTNODE **buckets;
} HT;

HT *ht_new(int num_buckets) {
    if (num_buckets <= 0)
        return NULL;
    HT *new_ht = malloc(sizeof(HT));
    if (new_ht != NULL) {
        new_ht->num_buckets = num_buckets;
        new_ht->buckets = calloc((size_t)num_buckets, sizeof(HTNODE *));
    }
    return new_ht;
}

size_t ht_size(const HT *ht) {
    return ht->num_buckets;
}

void ht_add(const HT *ht, const char *s) {
    const int b = hash(s, ht->num_buckets);
    HTNODE *n = malloc(sizeof(HTNODE));
    if (n == NULL) {
        errno = ENOMEM;
        return;
    }
    n->data = strdup(s);
    n->next = ht->buckets[b];
    ht->buckets[b] = n;
    printf("%s added to bucket %d.\n", s, b);
}

bool ht_exists(const HT *ht, const char *s) {
    const int b = hash(s, ht->num_buckets);
    const HTNODE *n = ht->buckets[b];
    while (n != NULL) {
        if (strcmp(n->data,s) == 0)
            return true;
        n = n->next;
    }
    return false;
}

void ht_remove(const HT *ht, const char *s) {
    const int b = hash(s, ht->num_buckets);
    HTNODE *n = ht->buckets[b], *p = NULL;
    while (n != NULL) {
        if (strcmp(n->data,s) == 0) {
            if (!p)
                ht->buckets[b] = n->next;
            else
                p->next = n->next;
            free(n->data);
            free(n);
            return;
        }
        p = n;
        n = n->next;
    }
}

void ht_dump(const HT *ht) {
    printf("Hash Table: buckets %d:\n", ht->num_buckets);
    for (int x = 0; x < ht->num_buckets; x++) {
        HTNODE *n = ht->buckets[x];
        printf("bucket[%d] -> ", x);
        while (n) {
            printf("%s ", n->data);
            n = n->next;
        }
        printf("\n");
    }
}

void ht_free(HT *ht) {
    for (int x = 0; x < ht->num_buckets; x++) {
        HTNODE *n = ht->buckets[x];
        while (n) {
            HTNODE *p = n;
            n = n->next;
            free(p->data);
            free(p);
        }
        free(ht->buckets);
    }
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
        ht_remove(ht, "192.168.10.2");
        ht_dump(ht);
        ht_remove(ht, "192.168.6.1");
        ht_dump(ht);
        ht_free(ht);
    }
}

