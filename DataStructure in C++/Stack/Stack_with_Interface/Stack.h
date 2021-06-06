#include "IStack.h"

class Stack : public IStack
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