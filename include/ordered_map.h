#ifndef STL_ORDERED_MAP_H
#define STL_ORDERED_MAP_H

typedef struct AVLNode {
    int key;
    int val;
    int ht;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

typedef struct {
    AVLNode *root;
} OrderedMap;

OrderedMap *newOrderedMap();

void insert(OrderedMap *map, int key, int val);

void inorder(AVLNode *node);

void freeMap(OrderedMap *map);

AVLNode *insertNode(AVLNode *node, int key, int val);

void freeTree(AVLNode *node);

#endif //STL_ORDERED_MAP_H