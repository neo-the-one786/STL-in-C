#ifndef STL_DEQUE_H
#define STL_DEQUE_H

#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *front, *rear;
} Deque;

Node *constructNode(int data);

Deque *constructDeque();

bool isEmpty(Deque *this);

void prepend(Deque *this, int data);

void append(Deque *this, int data);

int poll(Deque *this);

int detach(Deque *this);

void traverse(Deque *this);

#endif //STL_DEQUE_H