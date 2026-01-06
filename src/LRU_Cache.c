#include <stdio.h>
#include <stdlib.h>
#include "LRU_Cache.h"

void add_node(LRUCache* cache, Node* node){
    node->prev = cache->head;
    node->next =cache->head->next;
    cache->head->next->prev=node;
    cache->head->next =node;
}
void remove_node(Node* node){
    Node* prev_int = node->prev;
    Node* next_int = node->next;
    prev_int->next = next_int;
    next_int->prev =prev_int;
}
void move_to_head(LRUCache* cache,Node* node){
    remove_node(node);
    add_node(cache,node);
}
Node* pop_tail(LRUCache* cache){
    Node* last_node =cache->tail->prev;
    remove_node(last_node);
    return last_node;
}
LRUCache* lRUCacheCreate(int capacity){
    LRUCache* cache=(LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity=capacity;
    cache->size=0;
    cache->head=(Node*)malloc(sizeof(Node));
    cache->tail=(Node*)malloc(sizeof(Node));
    cache->head->next=cache->tail;
    cache->tail->prev=cache->head;
    cache->head->prev=NULL;
    cache->tail->next=NULL;
    cache->map =(Node**)calloc(10001,sizeof(Node*));
    return cache;
}
int lRUCacheGet (LRUCache* cache, int key){
    if (cache->map[key]==NULL){
        return -1;
    }
    Node* node=cache->map[key];
    move_to_head(cache,node);
    return node->value;
}
void lRUCachePut(LRUCache* cache, int key, int value){
    Node* node = cache->map[key];
    if (node != NULL){
        node->value=value;
        move_to_head(cache,node);
    }else{
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode -> key = key;
        newNode->value = value;
        cache->map[key]=newNode;
        add_node(cache,newNode);
        cache->size++;
        if (cache->size > cache -> capacity){
            Node* tail=pop_tail(cache);
            cache->map[tail->key]=NULL;
            free(tail);
            cache->size--;
        }
    }
}
void lRUCacheFree(LRUCache* cache){
    Node* current = cache->head;
    while(current != NULL){
        Node* temp = current;
        current =current->next;
        free(temp);
    }
    free(cache->map);
    free(cache);
}


