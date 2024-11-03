#ifndef STL_QUEUE_H
#define STL_QUEUE_H

#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Node *constructNode(int data);

Queue *constructQueue();

bool isEmpty(Queue *this);

void enqueue(Queue *this, int data);

int dequeue(Queue *this);

void traverse(Queue *this);

#endif //STL_QUEUE_H