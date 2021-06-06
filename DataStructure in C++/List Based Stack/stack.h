#ifndef _STACK_H
#define _STACK_H

#include "list.h"
#include "stack_exceptions.h"

class stack
{
	private:
	   list* p_list;
	public:
	   stack();
	   ret_t push(data_t new_data);
	   ret_t pop(data_t* p_poped_data);
	   ret_t top(data_t* p_top_data);
	   bool is_empty();
	   bool find_stack(data_t f_data);
	   len_t get_stack_length();
	   ~stack();

	   friend std::ostream& operator<<(std::ostream& ,const stack& p_stack);

};

#endif _STACK_H

