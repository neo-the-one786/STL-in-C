#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/unordered_map.h"

unsigned int hash(int key) {
    return key % 100;
}

Entry *newEntry(int key, int val) {
    Entry *entry = (Entry *) malloc(sizeof(Entry));
    entry->key = key;
    entry->val = val;
    entry->next = NULL;
    return entry;
}

UnorderedMap *newUnorderedMap() {
    UnorderedMap *map = (UnorderedMap *) malloc(sizeof(UnorderedMap));
    for (int i = 0; i < 100; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

void insert(UnorderedMap *map, int key, int val) {
    int index = hash(key);
    Entry *curr = map->buckets[index];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->val = val;
            return;
        }
        curr = curr->next;
    }
    Entry *new_entry = newEntry(key, val);
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
}

int get(UnorderedMap *map, int key) {
    int index = hash(key);
    Entry *curr = map->buckets[index];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->val;
        }
        curr = curr->next;
    }
    return INT_MIN;
}

void delete(UnorderedMap *map, int key) {
    int index = hash(key);
    Entry *curr = map->buckets[index];
    Entry *prev = NULL;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                map->buckets[index] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void freeMap(UnorderedMap *map) {
    for (int i = 0; i < 100; i++) {
        Entry *curr = map->buckets[i];
        while (curr != NULL) {
            Entry *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(map);
}
