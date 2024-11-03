#ifndef STL_UNORDERED_MAP_H
#define STL_UNORDERED_MAP_H

#include <limits.h>

#define TABLE_SIZE 100

typedef struct Entry {
    int key;
    int val;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} UnorderedMap;

Entry *newEntry(int key, int val);

UnorderedMap *newUnorderedMap();

void insert(UnorderedMap *map, int key, int val);

int get(UnorderedMap *map, int key);

void delete(UnorderedMap *map, int key);

void freeMap(UnorderedMap *map);

unsigned int hash(int key);

#endif //STL_UNORDERED_MAP_H