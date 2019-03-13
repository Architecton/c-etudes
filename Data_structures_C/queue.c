#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Linked-list node structure prototype
typedef struct Node {
	struct Node *next;
	int value;
} *Node;

// Queue structure prototype
typedef struct Queue {
	Node head;
	Node tail;
} *Queue;

void init_queue(Queue *queue);
void enqueue(Queue *queue, int value);
int queue_empty(Queue *queue);
int dequeue(Queue *queue);
void destroy_queue(Queue *queue);
void print_queue(Queue *queue);

int main(void) {

	Queue queue;
	init_queue(&queue);

	printf("adding 1 to the queue:\n");
	enqueue(&queue, 1);
	printf("adding 2 to the queue:\n");
	enqueue(&queue, 2);
	printf("adding 4 to the queue:\n");
	enqueue(&queue, 4);

	printf("the queue now contains:");
	print_queue(&queue);

	printf("\ndequeueing %d\n", dequeue(&queue));
	printf("\ndequeueing %d\n", dequeue(&queue));

	printf("the queue now contains:");
	print_queue(&queue);

	printf("\ndestorying queue\n");

	destroy_queue(&queue);

	return 0;
}

// init_queue: initializes an empty Queue on the location pointed to by *queue
void init_queue(Queue *queue) {
	// allocate memory
	*queue = (Queue)malloc(sizeof(Queue));
	// initialize head and tail of Queue to null
	(*queue)->head = NULL;
	(*queue)->tail = NULL;
}

// enqueue: add new element to the Queue pointed to by queue
void enqueue(Queue *queue, int value) {

	// declare, define and allocate memory for a new Node structure
	Node node;
	node = (Node)malloc(sizeof(Node));

	// set the new Node's value
	node->value = value;

	// The new Node will be the tail -> no next Node
	node->next = NULL;

	// if queue was empty, the added Node becomes the head
	if((*queue)->head == NULL) {
		(*queue)->head = node;
	// else, the previous tail now points to the added Node which becomes the new tail
	} else {
		(*queue)->tail->next = node;
	}

	// the added Node becomes the new tail
	(*queue)->tail = node;
}

// queue_empty: checks if the queue pointed to by queue empty
int queue_empty(Queue *queue) {
	return (*queue)->head == NULL;
}

// dequeue: return the value in the element at the head of the queue
int dequeue(Queue *queue) {
	// declare and define result
	int result;
	Node node;

	// if queue is empty, return signal value
	if(queue_empty(queue)) {
		return INT_MIN;
	}

	// the return value is the value of the head
	result = (*queue)->head->value;

	// set node to point to the current queue head that will be removed
	node = (*queue)->head;

	// advance queue head
	(*queue)->head = (*queue)->head->next;

	// free the memory occupied by the removed head element
	free(node);

	// return the result
	return result;
}

// destroy_queue: frees all memory occupied by the queue pointed to by queue
void destroy_queue(Queue *queue) {
	while(!queue_empty(queue)) {
		dequeue(queue);
	}
	free(*queue);
}

// print_queue: prints the elements in the queue pointed to by queue starting with the head
void print_queue(Queue *queue) {

	// define and declare iteration Node
	Node node;

	// iterate over the Queue and print the values of the nodes
	for(node = (*queue)->head; node != NULL; node = node->next) {
		printf("%d ", node->value);
	}
}