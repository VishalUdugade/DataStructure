#include <cstdio> 
#include <cstdlib> 
#include <cassert> 

#include "IStack.h"
#include "stack.h"

Stack::Stack(size_t stack_size) : p_arr(new int[stack_size]), size(stack_size), top_index(-1) 
{
}

Stack::~Stack()
{
    delete[] p_arr; 
}

int Stack::push(int new_element)
{
    if(top_index + 1 == size)
        return STACK_FULL; 
    ++top_index; 
    p_arr[top_index] = new_element; 
    return SUCCESS; 
}

int Stack::top(int* p_top_element)
{
    if(top_index == -1)
        return STACK_EMPTY; 
    *p_top_element = p_arr[top_index]; 
    return SUCCESS; 
}

int Stack::pop(int* p_poped_element)
{
    if(top_index == -1)
        return STACK_EMPTY; 
    *p_poped_element = p_arr[top_index]; 
    --top_index; 
    return SUCCESS; 
}

bool Stack::is_empty() const
{
    return top_index == -1; 
}

IStack* IStack::get_stack_instance(size_t size)
{
    return new Stack(size); 
}