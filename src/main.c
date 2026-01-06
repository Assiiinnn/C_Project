#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRU_Cache.h"

int main(int argc, char *argv[]) {
    // 1. Lire la capacité (par défaut 2)
    int capacity = (argc > 1) ? atoi(argv[1]) : 2;
    LRUCache* cache = lRUCacheCreate(capacity);
    
    char command[10];
    int key, value;

    // 2. Boucle d'écoute (Attend les ordres de Python)
    while (scanf("%s", command) != EOF) {
        
        if (strcmp(command, "PUT") == 0) {
            scanf("%d %d", &key, &value);
            lRUCachePut(cache, key, value);
        } 
        else if (strcmp(command, "GET") == 0) {
            scanf("%d", &key);
            int result = lRUCacheGet(cache, key);
            
            // 3. Réponse immédiate
            printf("%d\n", result);
            fflush(stdout); // CRUCIAL pour que le test ne bloque pas
        }
    }

    lRUCacheFree(cache);
    return 0;
}
