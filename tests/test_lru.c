#include <stdio.h>
#include <assert.h>
#include "LRU_Cache.h"

void test_basic_operations() {
    LRUCache* cache = lRUCacheCreate(2);
    
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    assert(lRUCacheGet(cache, 1) == 1);
    
    lRUCachePut(cache, 3, 3);  // Evicts key 2
    assert(lRUCacheGet(cache, 2) == -1);
    assert(lRUCacheGet(cache, 3) == 3);
    assert(lRUCacheGet(cache, 1) == 1);
    
    lRUCacheFree(cache);
    printf("✓ Basic operations test passed\n");
}

void test_single_capacity() {
    LRUCache* cache = lRUCacheCreate(1);
    
    lRUCachePut(cache, 1, 1);
    assert(lRUCacheGet(cache, 1) == 1);
    
    lRUCachePut(cache, 2, 2);  // Evicts key 1
    assert(lRUCacheGet(cache, 1) == -1);
    assert(lRUCacheGet(cache, 2) == 2);
    
    lRUCacheFree(cache);
    printf("✓ Single capacity test passed\n");
}

void test_update_existing() {
    LRUCache* cache = lRUCacheCreate(2);
    
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    
    // Update existing key
    lRUCachePut(cache, 1, 10);
    assert(lRUCacheGet(cache, 1) == 10);
    
    // Key 1 should be most recently used, so key 2 gets evicted
    lRUCachePut(cache, 3, 3);
    assert(lRUCacheGet(cache, 2) == -1);
    assert(lRUCacheGet(cache, 1) == 10);
    assert(lRUCacheGet(cache, 3) == 3);
    
    lRUCacheFree(cache);
    printf("✓ Update existing test passed\n");
}

void test_empty_cache() {
    LRUCache* cache = lRUCacheCreate(2);
    
    // Get from empty cache
    assert(lRUCacheGet(cache, 1) == -1);
    assert(lRUCacheGet(cache, 999) == -1);
    
    lRUCacheFree(cache);
    printf("✓ Empty cache test passed\n");
}

void test_lru_order() {
    LRUCache* cache = lRUCacheCreate(3);
    
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    lRUCachePut(cache, 3, 3);
    
    // Access key 1 to make it most recently used
    assert(lRUCacheGet(cache, 1) == 1);
    
    // Add new key, should evict key 2 (least recently used)
    lRUCachePut(cache, 4, 4);
    assert(lRUCacheGet(cache, 2) == -1);
    assert(lRUCacheGet(cache, 1) == 1);
    assert(lRUCacheGet(cache, 3) == 3);
    assert(lRUCacheGet(cache, 4) == 4);
    
    lRUCacheFree(cache);
    printf("✓ LRU order test passed\n");
}

int main() {
    printf("Running LRU Cache Tests...\n\n");
    
    test_basic_operations();
    test_single_capacity();
    test_update_existing();
    test_empty_cache();
    test_lru_order();
    
    printf("\n✅ All tests passed!\n");
    return 0;
}
