#ifndef _ICIRCULARLINKEDLIST_H
#define _ICIRCULARLINKEDLIST_H

//*Symbolic constants */ 
const int null  = -2;
const int FAIL    = 1;
const int SUCCESS = 2;
const int EMPTY_LIST = -3 ;//If list is empty the function returns.
const int INVALID_LOCATION = 4;
const int DATA_NOT_FOUND = 5;

class ICircular
{
  public:
   //Count the number of nodes in the list.
   virtual int LengthOfList() = 0;

   //Display all Nodes in List.
   virtual int DisplayList(int param, int location) = 0;

   //Insert Node In Linked List
   virtual int InsertInLinkedList(int data, int position) = 0;

   //Delete node from linked list .
   virtual int DeleteNodeFromLinkedList(int data, int position) = 0; //You can pass value either 2nd paramerter or  3rd parameter at a time while Invoking the function and make another parameter null.

   //Delete Whole Linked List.
   virtual int DeleteLinkedList() = 0;

   static ICircular* get_list_instance();

};

#endif _ICIRCULARLINKEDLIST_H


