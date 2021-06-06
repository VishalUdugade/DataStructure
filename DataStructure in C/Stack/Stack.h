#ifndef _STACK_H 
#define _STACK_H

/* Symbolic constants */ 
#define SUCCESS 1 
#define STACK_FULL -1 
#define STACK_EMPTY -2
#define INVALID_INPUT -3 
#define TRUE 1 
#define FALSE 0 

/* Data type layout definition */ 
struct stack{
	/* array based implementation */ 
	int* p_arr; 
	int size; 
	int top; 
}; 

/* 	1. One function to allow client to create stack instance 
	2. One function to allow cleint to destroy created stack instance 	
	3. One / More functions to allow Use stack 
		(i)	push 
		(ii) pop 
		(iii) top 
		(iv) is_empty 
*/ 

/* Data Instance Manipulation functions */ 
struct stack* create_stack(int size); 

int push(struct stack* p_stack, int new_data); 
int pop(struct stack* p_stack); 
int top(struct stack* p_stack); 
int is_empty(struct stack* p_stack); 

void destroy_stack(struct stack* p_stack); 

#endif _STACK_H