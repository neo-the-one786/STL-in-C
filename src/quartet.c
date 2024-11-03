#include <stdio.h>
#include <stdlib.h>
#include "../include/quartet.h"

Quartet *newQuartet(int first, int second, int third, int fourth) {
    Quartet *this = (Quartet *) malloc(sizeof(Quartet));
    this->first = first;
    this->second = second;
    this->third = third;
    this->fourth = fourth;
    return this;
}

void print(Quartet *this) {
    printf("Quartet(%d, %d, %d, %d)\n", this->first, this->second, this->third, this->fourth);
}