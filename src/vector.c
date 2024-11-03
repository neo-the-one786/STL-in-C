#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/vector.h"

Vector *construct() {
    Vector *this = (Vector *) malloc(sizeof(Vector));
    this->cpty = 10;
    this->arr = (int *) malloc(this->cpty * sizeof(int));
    this->length = 0;
    return this;
}

Vector *constructLen(int len) {
    Vector *this = (Vector *) malloc(sizeof(Vector));
    this->length = this->cpty = len;
    this->arr = (int *) calloc(this->cpty, sizeof(int));
    return this;
}

Vector *constructFill(int len, int dat) {
    Vector *this = (Vector *) malloc(sizeof(Vector));
    this->length = this->cpty = len;
    this->arr = (int *) calloc(this->cpty, sizeof(int));
    for (int i = 0; i < this->length; i++) {
        this->arr[i] = dat;
    }
    return this;
}

bool isEmpty(Vector *this) {
    return this->length == 0;
}

int get(Vector *this, int idx) {
    if (idx >= this->cpty || isEmpty(this)) {
        fprintf(stderr, "Index out of bounds!");
        exit(1);
    }
    return this->arr[idx];
}

void setAll(Vector *this, int dat) {
    if (isEmpty(this)) {
        fprintf(stderr, "Null pointer!");
        exit(1);
    }
    for (int i = 0; i < this->length; i++) {
        this->arr[i] = dat;
    }
}

void set(Vector *this, int idx, int dat) {
    if (idx >= this->cpty || isEmpty(this)) {
        fprintf(stderr, "Index out of bounds!");
        exit(1);
    }
    this->arr[idx] = dat;
}

void prepend(Vector *this, int dat) {
    if (this->length == this->cpty) {
        this->cpty *= 2;
        this->arr = realloc(this->arr, sizeof(int) * this->cpty);
    }
    for (int i = this->length; i > 0; --i) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[0] = dat;
    this->length++;
}

void append(Vector *this, int dat) {
    if (this->length == this->cpty) {
        this->cpty *= 2;
        this->arr = realloc(this->arr, sizeof(int) * this->cpty);
    }
    this->arr[this->length++] = dat;
}

int poll(Vector *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "Null pointer!");
        return INT_MIN;
    }
    int dat = this->arr[0];
    for (size_t i = 0; i < this->length - 1; ++i) {
        this->arr[i] = this->arr[i + 1];
    }
    this->length--;
    return dat;
}

int dock(Vector *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "\nNull pointer!");
        return INT_MIN;
    }
    int dat = this->arr[this->length - 1];
    this->length--;
    return dat;
}

void print(Vector *this) {
    printf("\n[");
    for (int i = 0; i < this->length; i++) {
        if (i < this->length - 1) {
            printf("%d, ", this->arr[i]);
        } else {
            printf("%d", this->arr[i]);
        }
    }
    printf("]\n");
}

void insert(Vector *this, int dat, int idx) {
    if (idx > this->length || this->length == this->cpty) {
        printf("Index Out of Bounds");
        return;
    }
    if (this->length == this->cpty) {
        this->cpty *= 2;
        this->arr = realloc(this->arr, sizeof(int) * this->cpty);
    }
    for (int i = this->length; i >= idx; i--) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[idx] = dat;
    this->length++;
}

void delete(Vector *this, int idx) {
    if (isEmpty(this)) {
        fprintf(stderr, "Null pointer!");
        exit(1);
    }
    if (idx >= this->cpty || isEmpty(this)) {
        printf("Index Out of Bounds!");
        return;
    }
    for (int i = idx; i < this->length - 1; i++) {
        this->arr[i] = this->arr[i + 1];
    }
    this->length--;
}

int linearSearch(Vector *this, int dat) {
    for (int i = 0; i < this->length; i++) {
        if (this->arr[i] == dat) {
            return i;
        }
    }
    return -1;
}

int binarySearch(Vector *this, int dat) {
    sort(this);
    int start = 0, end = this->length - 1, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (this->arr[mid] == dat) {
            return mid;
        } else if (dat < this->arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

void swap(Vector *this, int i, int j) {
    int temp = get(this, i);
    set(this, i, get(this, j));
    set(this, j, temp);
}

int sum(Vector *this) {
    int total = 0;
    for (int i = 0; i < this->length; i++) {
        total += this->arr[i];
    }
    return total;
}

int max(Vector *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "Vector is empty!");
        exit(1);
    }
    int maximum = this->arr[0];
    for (int i = 1; i < this->length; i++) {
        if (this->arr[i] > maximum) {
            maximum = this->arr[i];
        }
    }
    return maximum;
}

int min(Vector *this) {
    if (isEmpty(this)) {
        fprintf(stderr, "Vector is empty!");
        exit(1);
    }
    int minimum = this->arr[0];
    for (int i = 1; i < this->length; i++) {
        if (this->arr[i] < minimum) {
            minimum = this->arr[i];
        }
    }
    return minimum;
}

Vector *map(Vector *this, int (*func)(int)) {
    Vector *result = constructLen(this->length);
    for (int i = 0; i < this->length; i++) {
        result->arr[i] = func(this->arr[i]);
    }
    return result;
}

Vector *filter(Vector *this, bool (*predicate)(int)) {
    Vector *result = construct();
    for (int i = 0; i < this->length; i++) {
        if (predicate(this->arr[i])) {
            append(result, this->arr[i]);
        }
    }
    return result;
}

int reduce(Vector *this, int (*func)(int, int), int initial) {
    int accumulator = initial;
    for (int i = 0; i < this->length; i++) {
        accumulator = func(accumulator, this->arr[i]);
    }
    return accumulator;
}

void heapify(Vector *v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && v->arr[left] > v->arr[largest]) {
        largest = left;
    }
    if (right < n && v->arr[right] > v->arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int swap = v->arr[i];
        v->arr[i] = v->arr[largest];
        v->arr[largest] = swap;
        heapify(v, n, largest);
    }
}

void heapsort(Vector *v) {
    int n = v->length;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = v->arr[0];
        v->arr[0] = v->arr[i];
        v->arr[i] = temp;
        heapify(v, i, 0);
    }
}

void quicksort(Vector *v, int start, int end) {
    if (end - start <= 1) return;
    int pivot = v->arr[start + (end - start) / 2];
    int i = start;
    int j = end - 1;

    while (i <= j) {
        while (v->arr[i] < pivot) i++;
        while (v->arr[j] > pivot) j--;
        if (i <= j) {
            int temp = v->arr[i];
            v->arr[i] = v->arr[j];
            v->arr[j] = temp;
            i++;
            j--;
        }
    }
    introsort(v, start, j + 1, (int) log2(end - start));
    introsort(v, i, end, (int) log2(end - start));
}

void introsort(Vector *v, int start, int end, int maxDepth) {
    if (end - start <= 1) return;
    if (maxDepth == 0) {
        heapsort(v);
    } else {
        quicksort(v, start, end);
    }
}

void sort(Vector *v) {
    int depthLimit = 2 * (int) log(v->length);
    introsort(v, 0, v->length, depthLimit);
}

void destruct(Vector *this) {
    free(this->arr);
    free(this);
}