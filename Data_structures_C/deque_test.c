#include <stdio.h>
#include "deque.c"

// program for testing the deque ADT
int main() {
	// define and initialize the deque
	Deque deque;
	init(&deque);

	// add some elements
	printf("add 1 to FRONT\n");
	push(&deque, FRONT, 1);
	printf("add 2 to BACK\n");
	push(&deque, BACK, 2);
	printf("add 5 to FRONT\n");
	push(&deque, FRONT, 5);
	printf("add 8 to FRONT\n");
	push(&deque, FRONT, 8);
	printf("add 12 to FRONT\n");
	push(&deque, FRONT, 12);
	printf("add -7 to BACK\n");
	push(&deque, BACK, -7);

	// pop some elements
	printf("Popped %d from FRONT.\n", pop(&deque, FRONT));
	printf("Popped %d from FRONT.\n", pop(&deque, FRONT));
	printf("Popped %d from BACK.\n", pop(&deque, BACK));

	// destory deque
	printf("destroying deque\n");
	destroy(&deque);

	return 0;
}