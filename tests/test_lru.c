#include <stdio.h>
   #include <assert.h>
   #include "LRU_Cache.h"
   
   void test_basic_operations() {
       LRUCache* cache = lru_cache_create(2);
       
       lru_cache_put(cache, 1, 1);
       lru_cache_put(cache, 2, 2);
       assert(lru_cache_get(cache, 1) == 1);
       
       lru_cache_put(cache, 3, 3);  // Evicts key 2
       assert(lru_cache_get(cache, 2) == -1);
       
       lru_cache_free(cache);
       printf("✓ Basic operations test passed\n");
   }
   
   void test_single_capacity() {
       // Your implementation
   }
   
   void test_update_existing() {
       // Your implementation
   }
   
   int main() {
       test_basic_operations();
       test_single_capacity();
       test_update_existing();
       printf("\n✅ All tests passed!\n");
       return 0;
   }
