#ifndef STL_STACK_H
#define STL_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Node *constructNode(int data);

Stack *constructStack();

void push(Stack *stack, int data);

int pop(Stack *stack);

int peek(Stack *stack);

int get(Stack *stack, int pos);

int bottom(Stack *stack);

void print(Stack *stack);

#endif //STL_STACK_H
