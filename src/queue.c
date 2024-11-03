#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/queue.h"

Node *constructNode(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

Queue *constructQueue() {
    Queue *this = (Queue *) malloc(sizeof(Queue));
    this->front = NULL;
    this->rear = NULL;
    return this;
}

bool isEmpty(Queue *this) {
    return this->front == NULL;
}

void enqueue(Queue *this, int data) {
    Node *newNode = constructNode(data);
    if (isEmpty(this)) {
        this->front = this->rear = newNode;
        return;
    }
    this->rear->next = newNode;
    this->rear = newNode;
}

int dequeue(Queue *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nQueue Empty!");
        return INT_MIN;
    }
    Node *dump = this->front;
    int data = dump->data;
    if (this->front == this->rear) {
        this->front = this->rear = NULL;
    } else {
        this->front = this->front->next;
    }
    free(dump);
    return data;
}

void traverse(Queue *this) {
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