#ifndef STL_VECTOR_H
#define STL_VECTOR_H

#include <stdbool.h>
#include <math.h>

typedef struct {
    int *arr, length, cpty;
} Vector;

Vector *construct();

Vector *constructLen(int cpty);

Vector *constructFill(int cpty, int val);

void prepend(Vector *v, int value);

void append(Vector *v, int value);

int poll(Vector *v);

int dock(Vector *v);

int get(Vector *v, int idx);

void set(Vector *v, int idx, int val);

void print(Vector *v);

void swap(Vector *this, int i, int j);

int sum(Vector *v);

int max(Vector *v);

int min(Vector *v);

Vector *map(Vector *v, int (*func)(int));

Vector *filter(Vector *v, bool (*predicate)(int));

int reduce(Vector *v, int (*func)(int, int), int initial);

void destruct(Vector *v);

void introsort(Vector *v, int start, int end, int maxDepth);

void quicksort(Vector *v, int start, int end);

void heapsort(Vector *v);

void heapify(Vector *v, int n, int i);

void sort(Vector *v);

#endif //STL_VECTOR_H