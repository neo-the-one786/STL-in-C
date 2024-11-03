#ifndef STL_BST_H
#define STL_BST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *construct(int data);

bool isBST(Node *root);

bool isBSTHelper(Node *root, int prev);

Node *search(Node *root, int data);

Node *searchIter(Node *root, int data);

Node *insertRecur(Node *root, int data);

void insertIter(Node **root, int data);

Node *delete(Node *root);

void print(Node *root);

#endif //STL_BST_H