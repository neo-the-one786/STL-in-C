#include <stdio.h>
#include <stdlib.h>
#include "../include/ordered_map.h"

int height(AVLNode *node) {
    return node ? node->ht : 0;
}

AVLNode *newNode(int key, int val) {
    AVLNode *node = (AVLNode *) malloc(sizeof(AVLNode));
    node->key = key;
    node->val = val;
    node->ht = 1;
    node->left = node->right = NULL;
    return node;
}

AVLNode *right_rotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->ht = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->ht = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

AVLNode *left_rotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->ht = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->ht = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}

int calcBalance(AVLNode *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode *insertNode(AVLNode *node, int key, int val) {
    if (node == NULL) {
        return newNode(key, val);
    }
    if (key < node->key) {
        node->left = insertNode(node->left, key, val);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key, val);
    } else {
        node->val = val;
        return node;
    }
    node->ht = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    int balance = calcBalance(node);
    if (balance > 1 && key < node->left->key) return right_rotate(node);
    if (balance < -1 && key > node->right->key) return left_rotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void insert(OrderedMap *map, int key, int val) {
    map->root = insertNode(map->root, key, val);
}

void inorder(AVLNode *node) {
    if (node) {
        inorder(node->left);
        printf("%d: %d\n", node->key, node->val);
        inorder(node->right);
    }
}

OrderedMap *newOrderedMap() {
    OrderedMap *map = (OrderedMap *) malloc(sizeof(OrderedMap));
    map->root = NULL;
    return map;
}

void freeTree(AVLNode *node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void freeMap(OrderedMap *map) {
    freeTree(map->root);
    free(map);
}