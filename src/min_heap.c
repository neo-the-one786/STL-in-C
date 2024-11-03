#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "../include/min_heap.h"

MinHeap *minHeap() {
    MinHeap *this = (MinHeap *) malloc(sizeof(MinHeap));
    this->arr = (int *) calloc(100, sizeof(int));
    this->rear = -1;
    return this;
}

bool isEmpty(MinHeap *this) {
    return this->rear == -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *this, int dat) {
    this->arr[++this->rear] = dat;
    int i = this->rear;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (this->arr[parent] > this->arr[i]) {  // Changed to ">" for MinHeap
            swap(&this->arr[i], &this->arr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int extractMin(MinHeap *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nHeap is empty");
        return INT_MAX; // Use INT_MAX for MinHeap
    }
    int dat = this->arr[0];
    this->arr[0] = this->arr[this->rear--];
    int i = 0;
    while (i <= this->rear) {
        int lChild = 2 * i + 1, rChild = 2 * i + 2;
        int minChild;
        if (lChild <= this->rear && rChild <= this->rear) {
            minChild = this->arr[lChild] < this->arr[rChild] ? lChild : rChild; // Min child selection
        } else if (lChild <= this->rear) {
            minChild = lChild;
        } else if (rChild <= this->rear) {
            minChild = rChild;
        } else {
            minChild = i;
        }
        if (minChild != i && this->arr[i] > this->arr[minChild]) {  // Changed to ">" for MinHeap
            swap(&this->arr[i], &this->arr[minChild]);
            i = minChild;
        } else {
            break;
        }
    }
    return dat;
}

void minHeapify(MinHeap *this, int i) {
    if (isEmpty(this)) {
        return;
    }
    int lChild = 2 * i + 1, rChild = 2 * i + 2;
    int minChild;
    if (lChild <= this->rear && rChild <= this->rear) {
        minChild = this->arr[lChild] < this->arr[rChild] ? lChild : rChild; // Min child selection
    } else if (lChild <= this->rear) {
        minChild = lChild;
    } else if (rChild <= this->rear) {
        minChild = rChild;
    } else {
        minChild = i;
    }
    if (minChild == i || this->arr[i] < this->arr[minChild]) { // Changed to "<" for MinHeap
        return;
    }
    swap(&this->arr[i], &this->arr[minChild]);
    minHeapify(this, minChild);
}

void heapSort(MinHeap *this) {
    if (isEmpty(this) || this->rear == 0) {
        return;
    }
    int ogRear = this->rear;
    for (int i = this->rear; i > 0; i--) {
        swap(&this->arr[0], &this->arr[this->rear]);
        this->rear--;
        minHeapify(this, 0);
    }
    this->rear = ogRear;
}