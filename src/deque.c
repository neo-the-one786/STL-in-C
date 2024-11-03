#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/deque.h"

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
    return this;
}

Deque *constructDeque() {
    Deque *this = (Deque *) malloc(sizeof(Deque));
    this->front = NULL;
    this->rear = NULL;
    return this;
}

bool isEmpty(Deque *this) {
    return this->front == NULL;
}

void prepend(Deque *this, int data) {
    Node *newNode = constructNode(data);
    if (isEmpty(this)) {
        this->front = this->rear = newNode;
        return;
    }
    newNode->next = this->front;
    this->front->prev = newNode;
    this->front = newNode;
}

void append(Deque *this, int data) {
    Node *newNode = constructNode(data);
    if (isEmpty(this)) {
        this->front = this->rear = newNode;
        return;
    }
    this->rear->next = newNode;
    newNode->prev = this->rear;
    this->rear = newNode;
}

int poll(Deque *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nDeque Empty!");
        return INT_MIN;
    }
    Node *dump = this->front;
    int data = dump->data;
    if (this->front == this->rear) {
        this->front = this->rear = NULL;
    } else {
        this->front = this->front->next;
        this->front = NULL;
    }
    free(dump);
    return data;
}

int detach(Deque *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nDeque Empty!");
        return INT_MIN;
    }
    Node *dump = this->rear;
    int data = dump->data;
    if (this->front == this->rear) {
        this->front = this->rear = NULL;
    } else {
        this->rear = this->rear->prev;
        this->rear->next = NULL;
    }
    free(dump);
    return data;
}

void traverse(Deque *this) {
    printf("\n[");
    Node *ptr = this->front;
    while (ptr != NULL) {
        if (ptr->next != NULL) {
            printf("%d, ", ptr->data);
        } else {
            printf("%d", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("]\n");
}