#include <stdlib.h>
#include "deque.h"

#define NUM_DIRECTIONS (2)

// Node structure
typedef struct Node {
	// array of pointers to linked nodes
	struct Node *links[NUM_DIRECTIONS];

	// value of node
	int value;
} *Node;

// Deque structure
typedef struct Deque {
	Node first, last;
} *Deque;

// init_deque: initializes an empty Deque
void init(Deque *deque) {
	// allocate memory to deque pointer
	(*deque) = (Deque)malloc(sizeof(**deque));
	// set first and last Node pointers to point to NULL
	(*deque)->first = (*deque)->last = NULL;
}

// push: pushes an element with the specified value onto the deque in the specified side
void push(Deque *deque, int direction, int value) {
	// define and initialize new Node pointer
	Node new_node = (Node)malloc(sizeof(*new_node));
	new_node->value = value;

	// if pushing first node (deque is empty)
	if(empty(deque)) {
		// set first and last to point to new Node
		(*deque)->first = (*deque)->last = new_node;
	// else link to front or to back
	} else if(direction == FRONT) {

		// relink current first node with the new first node
		new_node->links[FRONT] = (*deque)->first;
		((*deque)->first->links)[BACK]  = new_node;

		// set first to point to the new node
		(*deque)->first = new_node;
	} else {
		// relink current first node with the new first node
		(new_node->links)[BACK] = (*deque)->last;
		((*deque)->last->links)[FRONT] = new_node;

		// set last to point to the new node
		(*deque)->last = new_node;
	}
}

// pop: pop an element from the deque from the specified direction
int pop(Deque *deque, int direction) {

	// if deque is empty, return  signal value
	if(empty(deque)) {
		return EMPTY;
	}
	// define return variable with default value
	int result = EMPTY;
	// if direction is front
	if(direction == FRONT) {
		// get result from Node pointed to by front
		result = (*deque)->first->value;
		// if the accessed node is not the last node in the deque
		if((*deque)->first != (*deque)->last) {
			// set first pointer to next element in the deque
			(*deque)->first = ((*deque)->first->links)[FRONT]; 
			// free memory occupied by popped node
			free(((*deque)->first->links)[BACK]);
			// set the relevant pointer of the front Node to NULL
			((*deque)->first->links)[BACK] = NULL;
		} else {
			// free memory occupied by the Node
			free((*deque)->first);
			// set first and last pointers both to NULL
			(*deque)->first = (*deque)->last = NULL;
		}
	// similar for accessing the element at back of deque
	} else {
		result = (*deque)->last->value;
		if((*deque)->first != (*deque)->last) {
			(*deque)->last = ((*deque)->last->links)[BACK];
			free(((*deque)->last->links)[FRONT]);
			((*deque)->last->links)[FRONT] = NULL;
		} else {
			free((*deque)->last);
			(*deque)->first = (*deque)->last = NULL;
		}
	}
	return result;
}

// empty: returns 1 if the deque is empty and 0 otherwise
int empty(Deque *deque) {
	return (*deque)->first == NULL;
}

//destroy: frees memory occupied by the deque
void destroy(Deque *deque) {

	// if passed deque does not exist, return
	if((*deque) == NULL) {
		return;
	}

	// use first as iteration pointer
	// this while loop will execute if the deque has at least 2 elements
	while(((*deque)->first->links)[FRONT] != NULL) {
		// set first to point to next element
		(*deque)->first = ((*deque)->first->links)[FRONT];
		// free previous element
		free(((*deque)->first->links)[BACK]);
	}

	// free the last element left
	free((*deque)->first);
	
	// free memory pointed to by deque
	free(*deque);

	// set deque to NULL
	deque = NULL;
}