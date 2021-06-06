#ifndef _LIST_H
#define _LIST_H

#define SUCCESS           1
#define FAILURE           0
#define EMPTY_LIST        2
#define DATA_NOT_FOUND    3


typedef int data_t;
typedef int return_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;


struct node
{
	int data;
	struct node *next;
	struct node *previous;
};

/* Interface Routine */

list_t* create_list(void);

//Insertion Routine:
return_t insert_beg(list_t* p_list, data_t data);
return_t insert_end(list_t* p_list, data_t);
return_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
return_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

//Delete Routines:
return_t remove_beg(list_t* p_list);
return_t remove_end(list_t* p_list);
return_t remove_data(list_t* p_list, data_t r_data);

/* Interface Routine -> get / pop routines */ 
return_t get_start(list_t* p_list, data_t* p_start_data); 
return_t get_end(list_t* p_list, data_t* p_end_data); 
return_t pop_start(list_t* p_list, data_t* p_start_data); 
return_t pop_end(list_t* p_list, data_t* p_end_data); 


//Misc Routines:
return_t find_list(list_t* p_list, data_t f_data);
len_t length_t(list_t* p_list);
return_t is_empty_list(list_t* p_list);
void show(list_t* p_list);

//Interface routines destroy routines
return_t destroy_list(list_t* p_list);

/*Helper Routines */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* get_node(data_t new_data);
static node_t* search_node(node_t* p_list, data_t data);

#endif _LIST_H

