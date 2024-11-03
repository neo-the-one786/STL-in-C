#ifndef STL_QUARTET_H
#define STL_QUARTET_H

typedef struct {
    int first, second, third, fourth;
} Quartet;

Quartet *newQuartet(int first, int second, int third, int fourth);

void print(Quartet *this);

#endif //STL_QUARTET_H