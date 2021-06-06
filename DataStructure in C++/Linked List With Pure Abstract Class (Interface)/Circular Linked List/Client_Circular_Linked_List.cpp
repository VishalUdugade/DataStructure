#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "ICircular_linked_list.h"


int main()
{
  int choice = 0, data = 0, location = 0, return_value = 0 ;
  char str[5] = {0};

   ICircular *Head = ICircular::get_list_instance();

  printf("||||||||||||||||||||||||||||||||||||||||||||||||||||| Circular Linked List |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");

  do
  {
    printf("\n1.Insert a Node \n2.Delete a node \n3.Total Node in List \n4.Display All Nodes in List \n5.Delete a Complete List \n6.Exit \n7.Enter your choice = ");
    scanf("%d",&choice);

    switch(choice)
    {
              case 1:
                  printf("\nEnter Location You want to insert a node = ");
                  scanf("%d",&location);
                  

                      printf("\n\nEnter Your data = ");
                      scanf("%d",&data);

                       return_value = Head->InsertInLinkedList(data,location);

                      if(return_value == SUCCESS)
                      {
                          printf("\n\nNode Inserted Successfully...... \n"); 
                      }
                      else if(return_value == INVALID_LOCATION)
                      {
                          printf("\n\nInvalid Location, Location is not present in list\n");
                      }
                      else
                      {
                           printf("\n\nNode is Not Inserted Successfully....! \n"); 
                      }

                break;
                  

              case 2:
                  printf("\n1.Delete Node by using Data \n2.Delete Node by using location. \n3.Enter your choice = ");
                  scanf("%d",&choice);
                      
                 
                  switch(choice)
                  {
                       

                    case 1:
                         printf("\n\nEnter data You Want to Delete = ");
                         scanf("%d",&data);

                         return_value = Head->DeleteNodeFromLinkedList(data,null);

                       if(return_value == SUCCESS)
                       {
                           printf("\n\n\nNode is Successfully  Deleted \n");
                       }
                       else if(return_value == EMPTY_LIST)
                       {
                            printf("\n\n\nList is Empty.....\n");
                       }
                       else if(return_value == DATA_NOT_FOUND)
                       {
                            printf("\n\nData NOT Found you entered Wrong data...\n");
                       }
                    break;

                    case 2:

                       printf("\n\n\nEnter location you want to Delete  = ");
                       scanf("%d",&location);

                      
                      return_value = Head->DeleteNodeFromLinkedList(null,location);
                      
                           if(return_value == SUCCESS)
                           {
                                printf("\n\n\nNode is Successfully  Deleted \n");
                           }
                           else if(return_value == EMPTY_LIST)
                           {
                               printf("\n\n\nList is Empty.....\n");
                           }
                           else if(return_value == INVALID_LOCATION)
                           {
                               printf("\n\nInvalid Location, Please enter valid location.....\n");
                           }
                      
                    break;

                     default:
                          printf("\n\n\nPlease enter a valid choice.......!\n");
                     break; 
                 }

                break; 


              case 3:
                  if(Head->LengthOfList() == EMPTY_LIST)
                  {
                     printf("\n\n\nList is Empty.....\n");
                  }
                  else
                  {
                     printf("\n\n\nTotal Number of nodes is present in list is = %d\n",Head->LengthOfList());
                  }
              break;


              case 4:
                  if((Head->LengthOfList()) == EMPTY_LIST)
                  {
                     printf("\n\n\nList is Empty.....\n");
                  }
                  else
                  {

                    printf("\n\n\n1.Display from first to last.  \n2.Display from last to first. \n3.Display from any location you want. \n4.Enter your choice = ");
                    scanf("%d",&choice);

                   switch(choice)
                   {
                         case 1:
                             Head->DisplayList(1, 0);
                         break;

                         case 2:
                             Head->DisplayList(2, 0);
                         break;

                         case 3:
                             printf("\n\n\nEnter your location to print list =  ");
                             scanf("%d",&location);

                             if(Head->LengthOfList() >= location && 0 < location)
                             {
                                   printf("\n\n\n1.Display forward List from your location.  \n2.Display Backward List from your location.. \n3.Enter your choice = ");
                                   scanf("%d",&choice);

                                   switch(choice)
                                   {
                                       case 1:
                                           Head->DisplayList(3, location);
                                       break;

                                       case 2:
                                           Head->DisplayList(4, location);
                                       break;

                                       default:
                                              printf("\n\n\nPlease enter a valid choice.......!\n");
                                        break;
                                   }

                             }
                             else
                             {
                                    printf("\n\n\nYou Entered Wrong location , location not present in list\n");
                             }

                         break;

                         default:
                              printf("\n\n\nPlease enter a valid choice.......!\n");
                         break;
                   }
                  }
              break;


              case 5:

                  if(Head->LengthOfList() == 0)
                  {
                       printf("\n\n\nList is Empty.....\n");
                  }
                  else
                  {
                        printf("\nAre you sure to Delete a Complete List [Yes/No] = ");
                        scanf("%s",str);

                        if( strcmp(str,"Yes") == 0 || strcmp(str,"yes") == 0 || strcmp(str,"YES") == 0 )
                        {

                            if (Head->DeleteLinkedList() == SUCCESS)
                            {
                                printf("\n\n\nList Deleted Successfully.......\n");
                            }
                            else
                            {
                                 printf("\n\n\nList not Deleted....\n");
                            }
                        }
                       else if(strcmp(str,"No") == 0 || strcmp(str,"NO") == 0 || strcmp(str,"no") == 0)
                        {
                            printf("\n\n\nOK...........\n");
                        }
                        else
                        {
                            printf("\n\n\nPlease enter a valid choice.......!\n");
                        }

                  }

              break;


              case 6:
                   Head->DeleteLinkedList();
                   free(Head);
                   return 0;
              break;


              default:
                 printf("\n\n\nPlease enter a valid choice.......!\n");
              break;

    }

  }while(choice != 6);

return 0;

}




