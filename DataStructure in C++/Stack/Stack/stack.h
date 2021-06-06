#ifndef _STACK_H 
#define _STACK_H 

const int SUCCESS       = 1; 
const int STACK_EMPTY   = 2; 
const int STACK_FULL    = 3; 

class Stack
{
    private: 
        int* p_arr; 
        size_t size; 
        int top_index; 

    public:  
        // Constructor 
        Stack(size_t size); 
        // Destructor 
        ~Stack();
        //  Other member functions 
        int     push(int new_element); 
        int     top(int* p_top_element); 
        int     pop(int* p_poped_element); 
        bool    is_empty() const; 
}; 

#endif /* _STACK_H */ 