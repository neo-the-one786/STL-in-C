#ifndef STL_ARRAY_H
#define STL_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int length;
    int arr[];
} Array;

Array *newArray(int length);

void fill(Array *this, int value);

void setAll(Array *this, int value);

void swapArray(Array *this, int index1, int index2);

int sumArray(Array *this);

int maxArray(Array *this);

int minArray(Array *this);

Array *copyArray(Array *this);

void sortArray(Array *this);

void print(Array *this);

void freeArray(Array *this);

#endif //STL_ARRAY_H