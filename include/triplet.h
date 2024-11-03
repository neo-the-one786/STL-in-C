#ifndef STL_TRIPLET_H
#define STL_TRIPLET_H

typedef struct {
    int first, second, third;
} Triplet;

Triplet *newTriplet(int first, int second, int third);

void print(Triplet *this);

#endif //STL_TRIPLET_H