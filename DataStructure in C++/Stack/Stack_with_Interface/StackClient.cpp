#include <cstdio> 
#include <cstdlib> 
#include "IStack.h"

int main(void)
{
    IStack* p_stack = IStack::get_stack_instance(10); 

    for(int data = 0; data < 10; ++data)
        p_stack->push((data + 1) * 100); 

    int data; 
    while(p_stack->is_empty() != true)
    {
        p_stack->pop(&data); 
        printf("poped_data = %d\n", data); 
    }

    delete p_stack; 

    return EXIT_SUCCESS; 
}
