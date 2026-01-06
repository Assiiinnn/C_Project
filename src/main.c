#include <stdio.h>
#include <stdlib.h>
#include "LRU_Cache.h"

void assert_equal(int actual, int expected, const char* test_name) {
    if (actual != expected) {
        printf(" [ECHEC] %s : Attendu %d, Obtenu %d\n", test_name, expected, actual);
        exit(1); 
    } else {
        printf(" [SUCCES] %s\n", test_name);
    }
}

int main() {
    printf("=== Lancement des Tests Unitaires ===\n\n");
    LRUCache* cache = lRUCacheCreate(2);
    lRUCachePut(cache, 1, 10);
    lRUCachePut(cache, 2, 20);
    assert_equal(lRUCacheGet(cache, 1), 10, "Recuperation cle 1");
    lRUCachePut(cache, 1, 15);
    assert_equal(lRUCacheGet(cache, 1), 15, "Mise a jour cle 1");
    lRUCachePut(cache, 3, 30);
    assert_equal(lRUCacheGet(cache, 2), -1, "Eviction de la cle 2");
    assert_equal(lRUCacheGet(cache, 3), 30, "Presence de la cle 3");
    assert_equal(lRUCacheGet(cache, 99), -1, "Cle inexistante");
    lRUCacheFree(cache);
    printf("\n TOUS LES TESTS SONT PASSES !\n");
    return 0;
}

