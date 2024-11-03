#ifndef STL_MIN_HEAP_H
#define STL_MIN_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int *arr, rear;
} MinHeap;

MinHeap *minHeap();

bool isEmpty(MinHeap *this);

void insert(MinHeap *this, int dat);

int extractMin(MinHeap *this);

void minHeapify(MinHeap *this, int i);

void heapSort(MinHeap *this);

#endif //STL_MIN_HEAP_H