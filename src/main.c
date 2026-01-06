#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRU_Cache.h"

int main(int argc, char *argv[]) {
    // 1. Détermine la capacité (par défaut 2 si non spécifié)
    int capacity = (argc > 1) ? atoi(argv[1]) : 2;
    
    // 2. Crée le cache
    LRUCache* cache = lRUCacheCreate(capacity);
    
    char command[10];
    int key, value;

    // 3. Boucle principale : attend les ordres (du script Python ou de l'utilisateur)
    while (scanf("%s", command) != EOF) {
        
        if (strcmp(command, "PUT") == 0) {
            scanf("%d %d", &key, &value);
            lRUCachePut(cache, key, value);
            // PUT ne renvoie rien
        } 
        else if (strcmp(command, "GET") == 0) {
            scanf("%d", &key);
            int result = lRUCacheGet(cache, key);
            
            // Affiche le résultat et force l'envoi immédiat (IMPORTANT pour Python)
            printf("%d\n", result);
            fflush(stdout); 
        }
    }

    // 4. Nettoyage
    lRUCacheFree(cache);
    return 0;
}
