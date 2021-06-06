#include <cstdio> 
#include <cstdlib> 
#include <cassert> 
#include "stack.h"

int main(void)
{
    int data; 
    Stack* p_stack = new Stack(10); 

    assert(p_stack->is_empty() == true); 
    assert(p_stack->top(&data) == STACK_EMPTY); 
    assert(p_stack->pop(&data) == STACK_EMPTY); 

    for(data = 0; data < 10; ++data)
        assert(p_stack->push((data+1) * 10) == SUCCESS); 

    assert(p_stack->push(300) == STACK_FULL); 

    data = -1; 
    p_stack->top(&data); 
    printf("top_data = %d\n", data); 

    while(p_stack->is_empty() != true)
    {
        p_stack->pop(&data); 
        printf("poped data = %d\n", data); 
    }

    delete p_stack; 
    p_stack = 0; 

    return EXIT_SUCCESS; 
}
