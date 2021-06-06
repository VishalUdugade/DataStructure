#include "ICircular_linked_list.h"

class Circular:public ICircular
{
  private:
	int data; 
	Circular* next;
	Circular* previous;
  public:
  	//Constructor
  	Circular();

   //Count the number of nodes in the list.
   int LengthOfList();

   //Display all Nodes in List.
   int DisplayList(int param, int location);

   //Insert Node In Linked List
   int InsertInLinkedList(int data, int position);

   //Delete node from linked list .
   int DeleteNodeFromLinkedList(int data, int position); //You can pass value either 2nd paramerter or  3rd parameter at a time while Invoking the function and make another parameter null.

   //Delete Whole Linked List.
   int DeleteLinkedList();

};



