#include <stdio.h>
#include "LRU_Cache.h"

int main() {
    printf("--- Test LRU Cache ---\n");
    LRUCache* cache = lRUCacheCreate(2); 
    lRUCachePut(cache, 1, 10);
    lRUCachePut(cache, 2, 20);
    printf("Get 1: %d\n", lRUCacheGet(cache, 1)); 
    lRUCachePut(cache, 3, 30); 
    printf("Get 2: %d (attendu -1)\n", lRUCacheGet(cache, 2)); 
    lRUCacheFree(cache);
    return 0;
}
