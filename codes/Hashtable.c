#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct {
    int (*h)(int, int);
    int n;
    int *bucket[N];
} HashTable;

int mi_Mod(int x, int n) {
    return x % n;
}

int insert(HashTable *ht, int x) {
    int index = ht->h(x, ht->n);
    if (ht->bucket[index] == NULL) {
        ht->bucket[index] = malloc(sizeof(int));
        *(ht->bucket[index]) = x;
    } else {
        int *temp = realloc(ht->bucket[index], sizeof(int));
        if (temp == NULL) {
            return 0; 
        } else {
            ht->bucket[index] = temp;
            *(ht->bucket[index]) = x;
        }
    }
    return 1;
}

int find(HashTable *ht, int x) {
    int index = ht->h(x, ht->n);
    if (ht->bucket[index] != NULL && *(ht->bucket[index]) == x) {
        return *(ht->bucket[index]);
    }
    return -1; 
}

int randomFn(int x, int n) {
    srand((unsigned int)time(NULL) + x);  
    return rand() % n;
}

int main() {
    HashTable HT;
    HT.h = &mi_Mod;
    HT.n = N;

    for (int i = 0; i < N; i++) {
        HT.bucket[i] = NULL;
    }

    int x = 1234567;
    long long int y = 76554334234;

    insert(&HT, x);

    printf("%d\n", find(&HT, x));

    srand((unsigned int)time(NULL)); 
    printf("%d\n", randomFn(52, N));
    printf("%d\n", randomFn(3235235, N));

    for (int i = 0; i < N; i++) {
        free(HT.bucket[i]);
    }

    return 0;
}
