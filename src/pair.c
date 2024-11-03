#include <stdio.h>
#include <stdlib.h>
#include "../include/pair.h"

Pair *newPair(int first, int second) {
    Pair *this = (Pair *) malloc(sizeof(Pair));
    this->first = first;
    this->second = second;
    return this;
}

void print(Pair *this) {
    printf("Pair(%d, %d)\n", this->first, this->second);
}