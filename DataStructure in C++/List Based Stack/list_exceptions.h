#ifndef _LIST_EXCEPTIONS_H 
#define _LIST_EXCEPTIONS_H 

#include <stdexcept> 

class list_empty : public std::runtime_error
{
    public: 
        list_empty() : std::runtime_error("List is empty") 
        {
        }
}; 

class list_data_not_found : public std::runtime_error
{
    public: 
        list_data_not_found() : std::runtime_error("data not found")
        {     
        }
};

#endif /* _LIST_EXCEPTIONS_H */ 