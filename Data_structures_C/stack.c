#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// define value 0 as the value pointed to by bottom of stack (empty stack)
#define EMPTY_STACK 0

// define struct for Stack Node
typedef struct node {
	struct node *next;
	int value;
} *Node;

// define Stack as a Node
typedef Node Stack;

// function prototypes
void stack_push(Stack *stack, int value);
int stack_empty(Stack *stack);
int stack_pop(Stack *stack);
void print_stack(Stack *stack);
void print_stack_rev(Stack *stack);
void print_stack_rev_rec(Stack *stack);

// main function
int main(void) {

	// Declare define and initialize empty Stack
	Stack stack;
	stack = EMPTY_STACK;

	// pushing values onto stack
	printf("push 1\n");
	stack_push(&stack, 1);
	printf("push 3\n");
	stack_push(&stack, 3);
	printf("push 7\n");
	stack_push(&stack, 7);
	
	printf("Current state of stack: ");
	print_stack(&stack);
	
	printf("\nPrinting the stack in reverse: ");
	print_stack_rev(&stack);

	printf("\nPrinting the stack in reverse recursively: ");
	print_stack_rev(&stack);

	// poping  values from the stack
	int result1, result2, result3;
	result1 = stack_pop(&stack);
	printf("\nPopped %d\nstack:", result1);
	print_stack(&stack);
	result2 = stack_pop(&stack);
	printf("\nPopped %d\nstack:", result2);
	print_stack(&stack);
	result3 = stack_pop(&stack);
	printf("\nPopped %d\nstack:", result3);
	print_stack(&stack);

	// freeing memory
	free(stack);
	stack = NULL;
	
	return 0;
}

// stack_push: push value value on top of stack pointed to by stack
void stack_push(Stack *stack, int value) {

	// declare and define new Node to push to stack
	Node node;

	// allocate memory for the new node
	node = (Node)malloc(sizeof(*node));

	// set value of the new Node
	node->value = value;

	// set the new Node to point to the top of the Stack pointed to by stack
	node->next = *stack;

	// set stack to point to the new top of the Stack
	*stack = node;
}

// stack_empty: returns 1 if stack points to nil and 0 otherwise
int stack_empty(Stack *stack) {
	return (*stack == 0);
}

// stack_pop: return value at top of stack pointed to by stack
int stack_pop(Stack *stack) {

	// declare and define value for storing the popped value
	int value;

	// define auxilliary Node variable
	Node node;

	// if stack empty: return signal value (minimum value of int)
	if(stack_empty(stack)) {
		return INT_MIN;
	}

	// get value from node at top of stack
	value = (*stack)->value;

	// set node to point to top of stack
	node = *stack;

	// set stack to point to the next element in the stack
	*stack = node->next;

	// remove the element at the top of stack (free its memory location)
	free(node);

	// return the value popped from the stack
	return value;
}

// print_stack: prints the contents of the Stack pointed to by stack
void print_stack(Stack *stack) {

	// declare and define iteration variable
	Node node;

	// iterate over elements on stack
	for(node = *stack; !stack_empty(&node); node = node->next) {
		printf("%d ", node->value);
	}
}

// print_stack_rev: prints the contents of the Stack pointed to by stack in reverse order
void print_stack_rev(Stack *stack) {
	// define two auxilliary Stacks
	Stack aux1, aux2;
	// initialize the auxilliary stacks
	aux1 = aux2 = EMPTY_STACK;

	// pop elements of the passed Stack to aux1
	// aux1 will contain the elements in reverse order
	while(!stack_empty(stack)) {
		stack_push(&aux1, stack_pop(stack));
	}

	// pop elements from aux1, print them and add them to aux2
	// aux2 will contain the elements in the same order as in the passed stack
	while(!stack_empty(&aux1)) {
		int current_val = stack_pop(&aux1);
		printf("%d ", current_val);
		stack_push(&aux2, current_val);
	}

	// set the passed pointner to point to aux2
	(*stack) = aux2;
	// free pointer aux1
	free(aux1);
	aux1 = aux2 = NULL;
}

// print_stack_rev_rec: prints the contents of the Stack pointed to by stack in reverse order
// using recursion
void print_stack_rev_rec(Stack *stack) {
	// if stack is not empty
	if(!stack_empty(stack)) {
		// print the rest of the stack
		print_stack_rev_rec(&((*stack)->next));

		// print element
		printf("%d ", (*stack)->value);
	}
}