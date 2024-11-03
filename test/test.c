#include <stdio.h>
#include "../include/vector.h"

int main() {
    Vector *arr = constructFill(5, -1);
    print(arr);
    arr = constructLen(5);
    print(arr);
    set(arr, 0, 5);
    set(arr, 1, 4);
    set(arr, 2, 3);
    set(arr, 3, 2);
    set(arr, 4, 1);
    print(arr);
    sort(arr);
    print(arr);
    swap(arr, 0, arr->length - 1);
    print(arr);
    printf("\nsum: %d", sum(arr));
    printf("\nmax: %d", max(arr));
    destruct(arr);
    return 0;
}