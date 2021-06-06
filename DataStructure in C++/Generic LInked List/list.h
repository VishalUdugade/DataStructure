#ifndef _LIST_H 
#define _LIST_H 

#include <iostream> 
#include "list_exceptions.h"

const int SUCCESS = 1; 

typedef int data_t; 
typedef int ret_t; 
typedef int len_t; 

class node
{
    friend class list; 
    friend std::ostream& operator<<(std::ostream&, const list& list_object); 
private: 
    data_t data;
    node* prev; 
    node* next; 
    node(data_t new_data); 
};

class list
{
    private: 
        node* p_head_node; 

        // private routines in C 
        static void generic_insert(node* p_beg, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(data_t s_data); 
    public: 
        // create_list() in C
        list(); 

        // destroy_list() in C 
        ~list(); 

        // insertion routines in C 
        ret_t insert_start(data_t new_data); 
        ret_t insert_end(data_t new_data); 
        ret_t insert_after(data_t e_data, data_t new_data); 
        ret_t insert_before(data_t e_data, data_t new_data); 

        // get / pop routines in C 
        ret_t get_start(data_t* p_start_data); 
        ret_t get_end(data_t* p_end_data); 
        ret_t pop_start(data_t* p_start_data); 
        ret_t pop_end(data_t* p_end_data); 
        
        // Removal routines in C 
        ret_t remove_beg(); 
        ret_t remove_end(); 
        ret_t remove_data(data_t r_data); 

        // Misc routines in C 
        bool find_list(data_t f_data); 
        len_t get_length() const; 
        bool is_empty() const; 
        friend std::ostream& operator<<(std::ostream&, const list& list_object); 
}; 

#endif _LIST_H 


