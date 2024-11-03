#include <stdio.h>
#include <stdlib.h>
#include "../include/triplet.h"

Triplet *newTriplet(int first, int second, int third) {
    Triplet *this = (Triplet *) malloc(sizeof(Triplet));
    this->first = first;
    this->second = second;
    this->third = third;
    return this;
}

void print(Triplet *this) {
    printf("Triplet(%d, %d, %d)\n", this->first, this->second, this->third);
}