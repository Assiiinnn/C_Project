#ifndef LRU_CACHE_H
#define LRU_CACHE_H

typedef struct Node{
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** map;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* cache, int key);
void lRUCachePut(LRUCache* cache, int key, int value);
void lRUCacheFree(LRUCache* cache);

#endif
