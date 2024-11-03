#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/array.h"

Array *newArray(int length) {
    Array *this = malloc(sizeof(Array) + length * sizeof(int));
    this->length = length;
    for (int i = 0; i < length; ++i) {
        this->arr[i] = 0;
    }
    return this;
}

void fill(Array *this, int value) {
    for (int i = 0; i < this->length; ++i) {
        this->arr[i] = value;
    }
}

void setAll(Array *this, int value) {
    fill(this, value);
}

void swapArray(Array *this, int index1, int index2) {
    if (index1 < this->length && index2 < this->length) {
        int temp = this->arr[index1];
        this->arr[index1] = this->arr[index2];
        this->arr[index2] = temp;
    }
}

int sumArray(Array *this) {
    int sum = 0;
    for (int i = 0; i < this->length; ++i) {
        sum += this->arr[i];
    }
    return sum;
}

int maxArray(Array *this) {
    int maxVal = INT_MIN;
    for (int i = 0; i < this->length; ++i) {
        if (this->arr[i] > maxVal) {
            maxVal = this->arr[i];
        }
    }
    return maxVal;
}

int minArray(Array *this) {
    int minVal = INT_MAX;
    for (int i = 0; i < this->length; ++i) {
        if (this->arr[i] < minVal) {
            minVal = this->arr[i];
        }
    }
    return minVal;
}

Array *copyArray(Array *this) {
    Array *copy = newArray(this->length);
    for (int i = 0; i < this->length; ++i) {
        copy->arr[i] = this->arr[i];
    }
    return copy;
}

void sortArray(Array *this) {
    for (int i = 0; i < this->length - 1; ++i) {
        for (int j = 0; j < this->length - 1 - i; ++j) {
            if (this->arr[j] > this->arr[j + 1]) {
                swapArray(this, j, j + 1);
            }
        }
    }
}

void print(Array *this) {
    printf("[");
    for (int i = 0; i < this->length; ++i) {
        printf("%d", this->arr[i]);
        if (i < this->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void freeArray(Array *this) {
    free(this);
}