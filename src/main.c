#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRU_Cache.h"

int main(int argc, char *argv[]) {
    // 1. Définir la capacité (argument ou défaut)
    int capacity = (argc > 1) ? atoi(argv[1]) : 2;
    LRUCache* cache = lRUCacheCreate(capacity);
    
    char command[10];
    int key, value;

    // 2. Boucle : Attend les ordres du script de test Python
    // (Le script "écrit" dans le clavier virtuel du programme)
    while (scanf("%s", command) != EOF) {
        
        if (strcmp(command, "PUT") == 0) {
            scanf("%d %d", &key, &value);
            lRUCachePut(cache, key, value);
        } 
        else if (strcmp(command, "GET") == 0) {
            scanf("%d", &key);
            int result = lRUCacheGet(cache, key);
            
            // 3. Répondre au script Python
            printf("%d\n", result);
            fflush(stdout); // OBLIGATOIRE : Envoie la réponse tout de suite
        }
    }

    lRUCacheFree(cache);
    return 0;
}
