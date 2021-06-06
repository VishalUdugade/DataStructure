#include <stdio.h>
#include <assert.h> 
#include "Stack.h"

int main(void){
	int data; 
	int ret_value;
	struct stack* p_stack = NULL; 

	p_stack = create_stack(-10); 
	assert(p_stack == NULL); 

	p_stack = create_stack(5); 

	ret_value = is_empty(p_stack); 
	assert(ret_value == TRUE); 

	data = pop(p_stack); 
	assert(data == STACK_EMPTY);  

	data = top(p_stack); 
	assert(data == STACK_EMPTY); 

	for(data = 0; data < 5; ++data){
		ret_value = push(p_stack, (data + 1) * 10); 
		assert(ret_value == SUCCESS); 
	}

	ret_value = push(p_stack, 60); 
	assert(ret_value == STACK_FULL); 

	ret_value = is_empty(p_stack); 
	assert(ret_value == FALSE); 

	data = top(p_stack); 
	printf("top = %d\n", data); 

	while((data = pop(p_stack)) != STACK_EMPTY){
		printf("poped data = %d\n", data); 
	}

	destroy_stack(p_stack); 
	p_stack = NULL; 

	return (0); 
}