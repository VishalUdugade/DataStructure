#include <iostream> 

#include "list_exceptions.h"
#include "list.h"

node::node(data_t new_data) : data(new_data), prev(0), next(0)
{    
}

void list::generic_insert(node* p_beg, node* p_mid, node* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void list::generic_delete(node* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
    p_delete_node = 0; 
}

node* list::search_node(data_t s_data)
{
    for(node* p_run = this->p_head_node->next; p_run != this->p_head_node; p_run = p_run->next)
        if(p_run->data == s_data)
            return p_run; 
    return 0; 
}

// create_list() in C
list::list()
{
    this->p_head_node = new node(0); 
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 
}

// destroy_list() in C 
list::~list()
{
    for(node* p_run = this->p_head_node->next, *p_run_next = 0; p_run != this->p_head_node; p_run = p_run_next)
    {
        p_run_next = p_run->next; 
        delete p_run; 
    }

    delete p_head_node; 
    p_head_node = 0; 
}

// insertion routines in C 
ret_t list::insert_start(data_t new_data)
{
    generic_insert(this->p_head_node, new node(new_data), this->p_head_node->next); 
    return (SUCCESS); 
}

ret_t list::insert_end(data_t new_data)
{
    generic_insert(this->p_head_node->prev, new node(new_data), this->p_head_node); 
    return (SUCCESS); 
}

ret_t list::insert_after(data_t e_data, data_t new_data)
{
    node* e_node = this->search_node(e_data); 
    if(!e_node)
        throw list_data_not_found(); 
    generic_insert(e_node, new node(new_data), e_node->next); 
    return (SUCCESS); 
}

ret_t list::insert_before(data_t e_data, data_t new_data)
{
    node* e_node = this->search_node(e_data); 
    if(!e_node)
        throw list_data_not_found(); 
    generic_insert(e_node->prev, new node(new_data), e_node); 
    return (SUCCESS); 
}

// get / pop routines in C 
ret_t list::get_start(data_t* p_start_data)
{
    if(this->is_empty())
        throw list_empty(); 
    *p_start_data = this->p_head_node->next->data; 
    return SUCCESS; 
}

ret_t list::get_end(data_t* p_end_data)
{
    if(this->is_empty())
        throw list_empty(); 
    *p_end_data = this->p_head_node->prev->data; 
    return (SUCCESS); 
}

ret_t list::pop_start(data_t* p_start_data)
{
    if(this->is_empty())
        throw list_empty(); 
    *p_start_data = this->p_head_node->next->data; 
    generic_delete(p_head_node->next); 
    return (SUCCESS); 
}

ret_t list::pop_end(data_t* p_end_data)
{   
    if(this->is_empty())
        throw list_empty(); 
    *p_end_data = this->p_head_node->prev->data; 
    generic_delete(p_head_node->prev); 
    return (SUCCESS); 
}

// Removal routines in C 
ret_t list::remove_beg()
{
    if(this->is_empty())
        throw list_empty(); 
    generic_delete(this->p_head_node->next); 
    return (SUCCESS); 
}

ret_t list::remove_end()
{
    if(this->is_empty())
        throw list_empty(); 
    generic_delete(this->p_head_node->prev);
    return (SUCCESS); 
}

ret_t list::remove_data(data_t r_data)
{
    node* e_node = this->search_node(r_data); 
    if(!e_node)
        throw list_data_not_found();
    generic_delete(e_node); 
    return (SUCCESS); 
}

// Misc routines in C 
bool list::find_list(data_t f_data) 
{
    return this->search_node(f_data) != 0; 
}

len_t list::get_length() const
{
    len_t lst_length = 0; 
    for(node* p_run = this->p_head_node->next; p_run != this->p_head_node; p_run = p_run->next)
        ++lst_length; 
    return lst_length; 
}

bool list::is_empty() const
{
    return ((this->p_head_node == this->p_head_node->next) && (this->p_head_node == this->p_head_node->prev)); 
}

std::ostream& operator<<(std::ostream& os, const list& list_object)
{
    os << "[START]<->"; 
    for(node* p_run = list_object.p_head_node->next; p_run != list_object.p_head_node; p_run = p_run->next)
        os << "[" << p_run->data << "]<->"; 
    os << "[END]" << std::endl; 
    return os; 
}
