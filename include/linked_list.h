#ifndef STL_LINKED_LIST_H
#define STL_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *construct(int data);

void print(Node *this);

int search(Node *this, int data);

void prepend(Node **this, int data);

void append(Node **this, int data);

void insertAt(Node **this, int data, int pos);

void insertAfter(Node *this, int data);

void poll(Node **this);

void dock(Node **this);

void deleteAt(Node **this, int pos);

void deleteAfter(Node **this);

void sort(Node **this);

#endif //STL_LINKED_LIST_H