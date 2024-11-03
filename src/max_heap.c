#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "../include/max_heap.h"

MaxHeap *maxHeap() {
    MaxHeap *this = (MaxHeap *) malloc(sizeof(MaxHeap));
    this->arr = (int *) calloc(100, sizeof(int));
    this->rear = -1;
    return this;
}

bool isEmpty(MaxHeap *this) {
    return this->rear == -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MaxHeap *this, int dat) {
    this->arr[++this->rear] = dat;
    int i = this->rear;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (this->arr[parent] < this->arr[i]) {
            swap(&this->arr[i], &this->arr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int extractMax(MaxHeap *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nNull pointer");
        return INT_MIN;
    }
    int dat = this->arr[0];
    this->arr[0] = this->arr[this->rear--];
    int i = 0;
    while (i < this->rear) {
        int lChild = 2 * i + 1, rChild = 2 * i + 2;
        int maxChild;
        if (lChild <= this->rear && rChild <= this->rear) {
            maxChild = this->arr[lChild] > this->arr[rChild] ? lChild : rChild;
        } else if (lChild <= this->rear) {
            maxChild = lChild;
        } else if (rChild <= this->rear) {
            maxChild = rChild;
        } else {
            maxChild = i;
        }
        if (maxChild != i && this->arr[i] < this->arr[maxChild]) {
            swap(&this->arr[i], &this->arr[maxChild]);
            i = maxChild;
        } else {
            break;
        }
    }
    return dat;
}

void maxHeapify(MaxHeap *this, int i) {
    if (isEmpty(this)) {
        return;
    }
    int lChild = 2 * i + 1, rChild = 2 * i + 2;
    int maxChild;
    if (lChild <= this->rear && rChild <= this->rear) {
        maxChild = this->arr[lChild] > this->arr[rChild] ? lChild : rChild;
    } else if (lChild <= this->rear) {
        maxChild = lChild;
    } else if (rChild <= this->rear) {
        maxChild = rChild;
    } else {
        maxChild = i;
    }
    if (maxChild == i || this->arr[i] > this->arr[maxChild]) {
        return;
    }
    swap(&this->arr[i], &this->arr[maxChild]);
    maxHeapify(this, maxChild);
}

void heapSort(MaxHeap *this) {
    if (isEmpty(this) || this->rear == 0) {
        return;
    }
    int ogRear = this->rear;
    for (int i = this->rear; i > 0; i--) {
        swap(&this->arr[0], &this->arr[this->rear]);
        this->rear--;
        maxHeapify(this, 0);
    }
    this->rear = ogRear;
}