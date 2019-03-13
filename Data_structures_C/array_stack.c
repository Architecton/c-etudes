#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// defines
#define STACK_SIZE 100

// structs
typedef struct Stack {
	int* stack_array;
	int top_pointer;
} *Stack;

// static variables

// function prototypes
void init_stack(Stack *stack);
int stack_full(Stack *stack);
int stack_empty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
void print_stack(Stack *stack);

// main function
int main() {
	// defining and initializing a new Stack
	Stack stack;
	init_stack(&stack);

	// push elements to stack
	printf("pushing 1 to the stack:\n");
	push(&stack, 1);
	printf("pushing 4 to the stack:\n");
	push(&stack, 4);
	printf("pushing 7 to the stack:\n");
	push(&stack, 7);
	printf("current state of stack:");

	// print Stack
	print_stack(&stack);

	// pop elements from Stack
	printf("popped %d from stack\n", pop(&stack));

	// print Stack
	printf("current state of stack:");

	// print stack
	print_stack(&stack);

	// continue popping from Stack
	printf("popped %d from stack\n", pop(&stack));
	printf("popped %d from stack\n", pop(&stack));

	return 0;

}

// init_stack: initialize the array representing the stack and allocate memory
// also set top_pointer to bottom of stack
void init_stack(Stack *stack) {
	(*stack)->stack_array = (int*)malloc(STACK_SIZE*sizeof(int));
	(*stack)->top_pointer = 0;
}

// stack_full: check if the array representing the stack
// in the Stack pointed to by stack is full
int stack_full(Stack *stack) {
	return (*stack)->top_pointer == STACK_SIZE - 1;
}

// stack_empty: check if the Stack pointed to by stack is empty
// (empty if top_pointer points to 0)
int stack_empty(Stack *stack) {
	return (*stack)->top_pointer == 0;
}

// push: pushes value value to the Stack pointed to by stack
// it does nothing if the stack is already full
void push(Stack *stack, int value) {
	if(!stack_full(stack)) {
		(*stack)->stack_array[(*stack)->top_pointer] = value;
		(*stack)->top_pointer++;
	}
}

// pop: pops the value from the top of the Stack pointed to by stack
// returns the minimum value of int as a signal of popping an empty stack
int pop(Stack *stack) {
	if(!stack_empty(stack)) {
		return (*stack)->stack_array[--((*stack)->top_pointer)];
	}
	return INT_MIN;
}

// print_stack: prints the contents of the Stack pointed to by stack
void print_stack(Stack *stack) {
	for(int i = 0; i < (*stack)->top_pointer; i++) {
		printf((i == (*stack)->top_pointer - 1) ? "%d\n" : "%d, ", ((*stack)->stack_array)[i]);
	}
}