// include guards
#ifndef DEQUE_H
#define DEQUE_H

#include <limits.h>

typedef struct Deque *Deque;

// define signals for sides of access
#define FRONT (0)
#define BACK (1)

// signal value for accesing elements in an empty Deque
#define EMPTY (INT_MIN)

// init_deque: initializes an empty Deque
void init(Deque *deque);

// push: pushes an element with the specified value onto the deque in the specified side
void push(Deque *deque, int direction, int value);

// pop: pop an element from the deque from the specified direction
int pop(Deque *deque, int direction);

// empty: returns 1 if the deque is empty and 0 therwise
int empty(Deque *deque);

//destroy: frees memory occupied by the deque
void destroy(Deque *deque);

#endif