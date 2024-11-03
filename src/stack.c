#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

Stack *constructStack() {
    Stack *this = (Stack *) malloc(sizeof(Stack));
    this->top = NULL;
    return this;
}

void push(Stack *stack, int data) {
    Node *newNode = constructNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "\nStack underflow!");
        return INT_MIN;
    }
    Node *dump = stack->top;
    stack->top = stack->top->next;
    int data = dump->data;
    free(dump);
    return data;
}

int peek(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "\nStack underflow!");
        return INT_MIN;
    }
    return stack->top->data;
}

int get(Stack *stack, int pos) {
    if (stack->top == NULL) {
        fprintf(stderr, "\nNull pointer!");
        return INT_MIN;
    }
    Node *ptr = stack->top;
    int i = 0;
    while (ptr != NULL) {
        if (i == pos) {
            return ptr->data;
        }
        ptr = ptr->next;
        i++;
    }
    fprintf(stderr, "\nNo such element!");
    return INT_MIN;
}

int bottom(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "\nStack underflow!");
        return INT_MIN;
    }

    Node *ptr = stack->top;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr->data;
}

void print(Stack *stack) {
    printf("\n[");
    Node *ptr = stack->top;
    while (ptr != NULL) {
        if(ptr->next != NULL) {
            printf("%d, ", ptr->data);
        } else {
            printf("%d", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("]\n");
}