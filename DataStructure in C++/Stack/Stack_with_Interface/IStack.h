#ifndef _ISTACK_H 
#define _ISTACK_H 

const int SUCCESS       = 1; 
const int STACK_FULL    = 2; 
const int STACK_EMPTY   = 3; 

/* Interface to Stack */ 
class IStack
{
    public: 
        virtual int push(int new_element)       =   0; 
        virtual int pop(int* p_poped_element)   =   0; 
        virtual int top(int* p_top_element)     =   0; 
        virtual bool is_empty() const           =   0; 
        virtual ~IStack() { }
        static IStack* get_stack_instance(size_t size); 
}; 

#endif /* _ISTACK_H */ 
