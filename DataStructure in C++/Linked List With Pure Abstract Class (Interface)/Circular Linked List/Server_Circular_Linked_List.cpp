#include<iostream>
#include "ICircular_linked_list.h"
#include "circular_linked_list.h"

Circular::Circular():data(NULL),next(this),previous(this){}

//Display all Nodes in List.
int Circular::DisplayList(int param,int location)
{
     int n = 1;
    Circular* p,*q;
    if(this->next == this)
    {
      return EMPTY_LIST;
    }

    p = this->next;

    std::cout<<"\n[Start]<->";

    if(param == 1)
    {
          while(p->next != this)
          {
               std::cout<<"["<<p->data<<"]<->";
               p = p->next;
          }

    } 
    else if(param == 2)
    {
    	p = this->previous;

    	while(p->previous != this)
    	{
    		   std::cout<<"["<<p->data<<"]<->";
           p = p->previous;
    	}

    }  
    else if(param == 3)
    {
        while(n != location)
        {
            p = p->next;
            n++;
        }
      
         q = p;

        while(p != q->previous)
        {
          if(p != this)
          {
            std::cout<<"["<<p->data<<"]<->";
          }

          p = p->next;
        }
    }
    else if(param == 4)
    {
        while(n != location)
        {
            p = p->next;
            n++;
        }
      
         q = p;

        while(p != q->next)
        {
           if(p != this)
           {
              std::cout<<"["<<p->data<<"]<->";
           }
            p = p->previous;
        }
    }

    std::cout<<"["<<p->data<<"]";
    std::cout<<"<->[End]"<<std::endl;

    return SUCCESS;
}


//total Nodes in list starting from head
int Circular::LengthOfList()
{
      
      int count = 0;

      if(this->next == this)
      {
         return EMPTY_LIST;
      }

      Circular* p = this->next;

      while(p != this){
        count++;
        p = p->next;
      } 
     
      return count;
}


//Insert Node In Linked List
int Circular::InsertInLinkedList(int data, int position)
{
  if(position <= 0 || (LengthOfList() + 1  < position && LengthOfList() != EMPTY_LIST) || (LengthOfList() == EMPTY_LIST && position > 1))
    {
         return INVALID_LOCATION;
    }

    int k=1;
    Circular* new_node, *p ,*q;

    //memory created in Heap section.
     new_node = new Circular();
   
     if(!new_node)
     {
       std::cout<<std::endl<<"Memory Error" <<std::endl;
        return FAIL;
     }
    

    new_node->data = data;
    p = this;

    //Inserting at the beginning
    if(position == 1)
    {
        new_node->next = this->next;
        new_node->previous = this;
        (this->next)->previous = new_node;
        this->next = new_node ;
    }
    //Inserting at the last
    else if(position == LengthOfList() + 1)
    {
          while(p->next != this)
          {
            p = p->next;
          }

          p->next = new_node;
          new_node->previous = p;
          new_node->next = this;
          this->previous = new_node;
    }
    else
    {
        //Traverse the list until the position where we want to insert
        p = this->next;
        while((p!=this) && (k<position))
        {
            k++;
            q = p;
            p = p->next;
        }

        new_node->next = p;
        new_node->previous = q;
        q->next = new_node; //more optimum way to do this
        p->previous = new_node;
    }
    return SUCCESS;
}


int Circular::DeleteNodeFromLinkedList(int data, int position)
{
   
    int k = 1;
    Circular *p = NULL, *q = NULL;

    if(this->next == this)
    {
        return EMPTY_LIST;
    }

    p = this;
    q = this;
     /*Delete Node by using Data*/
     if(position == null)
     {
        while(p->next != this && p->data != data)
        {
            q = p;
            p = p->next;
        }

        if(p->data == data)
        {
            if(p->next == this) 
            {
                 q->next = p->next;
                 this->previous = q;
            }
            else
            {
                q->next = p->next;
                (p->next)->previous = q;
            }

            delete p;
            return SUCCESS;
        }

        return DATA_NOT_FOUND;
     }
     else if(data == null) //Delete Node by Position.
     {

            //Traverse the list until arriving at the position from which we want to delete.
            p = this->next;
            while((p!=this) && (k < position))
            {
                k++;
                q = p;
                p = p->next;
            }

            if(p == this || position <= 0 || (LengthOfList()  < position ))   //At the end.
            {
                return INVALID_LOCATION;
            }
            else
            {
                 q->next = p->next; 
                 (p->next)->previous = q;
            }
                delete p;
                return SUCCESS;
     }
     else
     {
            std::cout<<std::endl<<"Syntax error......."<<std::endl;
     }
}



//Delete all nodes in linked list.
int Circular::DeleteLinkedList()
{
     Circular* p;

    p = this->next;

    while(p->next != this)
    {
         this->next = p->next;
         (p->next)->previous = this;
         delete p;
         p = this->next;
    }
    
    this->next = p->next;
    this->previous = this;
    delete p;
    return SUCCESS;
}


ICircular* ICircular::get_list_instance()
{
     return new Circular();
}

