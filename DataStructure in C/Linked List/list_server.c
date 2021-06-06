#include<stdio.h>
#include<stdlib.h>
#include"list.h"

list_t* create_list(void)
{
	 node_t* p_dummy_node = get_node(0);
	 p_dummy_node->next = p_dummy_node;
	 p_dummy_node->previous = p_dummy_node;
	 return p_dummy_node;
}

return_t insert_beg(list_t* p_list, data_t data)
{
     generic_insert(p_list,get_node(data),p_list->next);
     return(SUCCESS);
}

return_t insert_end(list_t* p_list, data_t data)
{
	generic_insert(p_list->previous,get_node(data),p_list);
	return(SUCCESS);
}

return_t insert_after(list_t* p_list,data_t e_data,data_t new_data)
{
	node_t* p_ext_node = search_node(p_list,e_data);
	if(p_ext_node == NULL)
       return DATA_NOT_FOUND;

    generic_insert(p_ext_node,get_node(new_data),p_ext_node->next);
    return SUCCESS;
}

return_t insert_before(list_t* p_list,data_t e_data,data_t new_data)
{
	node_t* p_ext_node = search_node(p_list,e_data);
	if(p_ext_node == NULL)
		return DATA_NOT_FOUND;

	generic_insert(p_ext_node->previous,get_node(new_data),p_ext_node);
	return SUCCESS;
}

return_t remove_beg(list_t* p_list)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;

	generic_delete(p_list->next);
	return SUCCESS;
}

return_t remove_end(list_t* p_list)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;

	generic_delete(p_list->previous);
	return SUCCESS;
}

return_t remove_data(list_t* p_list,data_t r_data)
{
	node_t* p_ext_node = search_node(p_list,r_data);
	if(p_ext_node == NULL)
		return DATA_NOT_FOUND;

	generic_delete(p_ext_node);
	return SUCCESS;
}

//Interface routines get/ pop

return_t get_start(list_t* p_list,data_t* p_start_data)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;
    
     *p_start_data = p_list->next->data;
	return (SUCCESS);
}

return_t get_end(list_t* p_list, data_t* p_end_data)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;

	*p_end_data = p_list->previous->data;
	  return(SUCCESS);
}

return_t pop_start(list_t* p_list, data_t* p_start_data)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;

	*p_start_data = p_list->next->data;
	generic_delete(p_list->next);
	return SUCCESS;
}

return_t pop_end(list_t* p_list, data_t* p_end_data)
{
	if(is_empty_list(p_list))
		return EMPTY_LIST;

	*p_end_data = p_list->previous->data;
	generic_delete(p_list->previous);
	return SUCCESS;
}

return_t find_list(list_t* p_list,data_t f_data)
{
      node_t* p_ext_node = search_node(p_list,f_data);
      return (p_ext_node != NULL);
}

return_t length_t(list_t* p_list)
{
	node_t* p_run;
	len_t r_length;

	for(p_run = p_list->next , r_length = 0; p_run != p_list ; p_run = p_run->next , ++r_length)
         ;
	return (r_length);
}


return_t is_empty_list(list_t* p_list)
{
	return ((p_list->next == p_list) && (p_list->previous == p_list));
}

void show(list_t* p_list)
{
      node_t* p_run;
      p_run = p_list->next;
      printf("\n[Start]<->");
      while(p_run != p_list)
      {
      	printf("[%d]<->",p_run->data);
      	p_run = p_run->next;
      }
      printf("[End]\n");
}

return_t destroy_list(node_t* p_list)
{
	node_t* p_run;
	node_t* p_tmp;

	p_run = p_list->next;

	while(p_run != p_list)
	{
		p_tmp = p_run->next;
		free(p_run);
		p_run = p_tmp;
	}

	
	free(p_list);
	return(SUCCESS);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->next       = p_end;
	p_mid->previous   = p_beg;
	p_beg->next       = p_mid;
	p_end->previous   = p_mid;
}

static void generic_delete(node_t* p_delete_node)
{
	p_delete_node->previous->next = p_delete_node->next;
	p_delete_node->next->previous = p_delete_node->previous;
	free(p_delete_node);
}

static node_t* get_node(data_t new_data)
{
    node_t* p_new_node = (node_t*)malloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->previous = NULL; 
    p_new_node->next = NULL; 
    return (p_new_node);
}

static node_t* search_node(node_t* p_list, data_t data)
{
	node_t* p_node;

    p_node = p_list->next;
	while(p_node != p_list)
	{
		if(p_node->data == data)
			return p_node;

		p_node = p_node->next;
	}
	return(NULL);
}

