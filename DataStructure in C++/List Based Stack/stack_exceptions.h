#ifndef _LISTEXCEPTION_H
#define _LISTEXCEPTION_H

#include <stdexcept>

class stack_empty: public std::runtime_error
{
public:
	stack_empty():std::runtime_error("Stack is Empty")
	{

	}
};

class stack_data_not_found : public std::runtime_error
{
public:
        stack_data_not_found() : std::runtime_error("Data Not Found.")
        {

        }
};

#endif _LISTEXCEPTION_H

