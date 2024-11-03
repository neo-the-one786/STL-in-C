#ifndef STL_MAX_HEAP_H
#define STL_MAX_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int *arr, rear;
} MaxHeap;

MaxHeap *maxHeap();

bool isEmpty(MaxHeap *this);

void insert(MaxHeap *this, int dat);

int extractMax(MaxHeap *this);

void maxHeapify(MaxHeap *this, int i);

void heapSort(MaxHeap *this);

#endif //STL_MAX_HEAP_H