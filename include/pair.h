#ifndef STL_PAIR_H
#define STL_PAIR_H

typedef struct {
    int first;
    int second;
} Pair;

Pair *newPair(int first, int second);

void print(Pair *this);

#endif //STL_PAIR_H