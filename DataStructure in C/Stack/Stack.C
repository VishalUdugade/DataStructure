#include <stdio.h> 
#include <stdlib.h> 
#include "Stack.h"

struct stack* create_stack(int size){
	struct stack* p_stack = NULL; 
	int* pa = NULL; 

	if(size <= 0)
		return (NULL); 

	p_stack = (struct stack*)malloc(sizeof(struct stack)); 
	if(p_stack == NULL){
		puts("Failed to allocate memory for stack instance"); 
		return (NULL); 
	}
	memset(p_stack, 0, sizeof(struct stack)); 

	pa = (int*)malloc(size * sizeof(int)); 
	if(pa == NULL){
		puts("Failed to allocate memory to internal array"); 
		free(p_stack); 
		p_stack = NULL; 
		return (NULL); 
	}
	memset(pa, 0, size*sizeof(int)); 

	p_stack->p_arr = pa; 
	p_stack->size = size; 
	p_stack->top = -1; 

	return (p_stack); 
}

int push(struct stack* p_stack, int new_data){
	if(new_data < 0)
		return (INVALID_INPUT); 

	if(p_stack->top + 1 == p_stack->size)
		return (STACK_FULL); 

	p_stack->top = p_stack->top + 1; 
	p_stack->p_arr[p_stack->top] = new_data; 

	return (SUCCESS); 
}

int pop(struct stack* p_stack){
	int top_element; 

	if(p_stack->top == -1)
		return (STACK_EMPTY); 

	top_element = p_stack->p_arr[p_stack->top]; 
	p_stack->top = p_stack->top - 1; 
	
	return (top_element); 
}

int top(struct stack* p_stack){
	if(p_stack->top == -1)
		return (STACK_EMPTY);

	return (p_stack->p_arr[p_stack->top]); 
}

int is_empty(struct stack* p_stack){
	return (p_stack->top == -1); 
}

void destroy_stack(struct stack* p_stack){
	free(p_stack->p_arr); 
	free(p_stack); 
}
