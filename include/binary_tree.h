#ifndef STL_BINARY_TREE_H
#define STL_BINARY_TREE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *construct(int data);

Node *insertRecur(Node *root, int data);

void insertIter(Node **root, int data);

Node *deleteRecur(Node *root, int data);

void preOrderRecur(Node *root);

void inOrderRecur(Node *root);

void postOrderRecur(Node *root);

typedef struct {
    int top, cpty;
    Node **arr;
} Stack;

Stack *constructStack(int cpty);

bool isEmpty(Stack *this);

bool isFull(Stack *this);

void push(Stack *this, Node *data);

Node *pop(Stack *this);

void preOrderIter(Node *root);

void inOrderIter(Node *root);

void postOrderIter(Node *root);

#endif //STL_BINARY_TREE_H