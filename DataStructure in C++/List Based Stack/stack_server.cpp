#include <iostream>
#include <stdexcept>

#include "list.h"
#include "stack_exceptions.h"

#include "stack.h"
#include "stack_exceptions.h"

stack::stack():p_list(new list)
{
	
}

ret_t stack::push(data_t new_data)
{
	p_list->insert_end(new_data);
	return (SUCCESS);
}


ret_t stack::pop(data_t* p_poped_data)
{
    data_t data;
	if(p_list->is_empty() == true)
	   throw stack_empty();

	p_list->pop_end(&data);
	*p_poped_data = data;
	return(SUCCESS);
}

bool stack::is_empty()
{
	return p_list->is_empty();
}

bool stack::find_stack(data_t f_data)
{
	if(p_list->is_empty() == true)
		throw stack_empty();

    if(p_list->find_list(f_data) == false)
    	throw stack_data_not_found();

    return true;
}


len_t stack::get_stack_length()
{
	return p_list->get_length();
}

stack::~stack()
{
     delete p_list;	
}

std::ostream& operator<<(std::ostream& os,const stack& p_stack)
{
	os << *(p_stack.p_list) << std::endl;
	return os;
}

