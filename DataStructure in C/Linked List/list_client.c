#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

int main()
{
	list_t* p_list = NULL;
	data_t n_data = 0,choice = 0,ex_data = 0;
    char str[5] = {0};
     
     printf("\n=================================Linked List =================================\n");
	do
	{
      printf("\n1.Create List. \n2.Insert. \n3.Get & Pop. \n4.Find & Count. \n5.Remove. \n6.Show List. \n7.Destory List. \n8.Exit \nEnter Your Choice =  ");
      scanf("%d",&choice);

      if((choice <= 7 && choice >= 2) && p_list == NULL)
      {
      	printf("\nList is Not Created First Create List..\n");
      	continue;
      }
      	
        
        switch(choice)
        {
        	
        	case 1:
        	    if(p_list == NULL)
        	    {
                    p_list = create_list();
                    printf("\nList is Created Successfully...\n");
        	    }
                else
                {
                	printf("\nList is already Created..\n");
                }
        	break;


        	case 2:
        	    printf("\n1.Insert Beginning. \n2.Insert Last. \n3.Insert After. \n4.Insert Before. \nEnter Your Choice = ");
        	    scanf("%d",&choice);
                
                printf("\nEnter New Data = ");
                scanf("%d",&n_data);

                switch(choice)
                {
                	case 1:
                       if(insert_beg(p_list,n_data))
                       {
                       	 printf("\nData Inserted Successfully....\n");
                       }
                       else
                       {
                       	 printf("\nData is not inserted.....\n");
                       }
                	break;

                	case 2:
                	    if(insert_end(p_list,n_data))
                	    {
                       	  printf("\nData Inserted Successfully....\n");
                	    }
                       else
                       {
                       	  printf("\nData is not inserted.....\n");
                       }
                	break;

                	case 3:
                	     printf("\nEnter Existing Data that New Data is Inserted After  = ");
                	     scanf("%d",&ex_data);

                	     if(insert_after(p_list,ex_data,n_data) == SUCCESS)
                	     {
                	     	printf("\nData Inserted Successfully....\n");
                	     }                       	   
                         else
                         {
                         	printf("\nData is not Found in List.....\n");
                         }
                       	   
                	break;

                	case 4:
                	      printf("\nEnter Existing Data that New Data is Inserted After  = ");
                	      scanf("%d",&ex_data);

                	      if(insert_before(p_list,ex_data,n_data) == SUCCESS)
                       	  {
                	     	    printf("\nData Inserted Successfully....\n");
                	      }                       	   
                          else
                          {
                              	printf("\nData is not Found in List.....\n");
                          }
                	break;

                	default:
                	  printf("\nYou Entered Wrong Choice, Please Enter correct choice..\n");
                	break;
                }
        	break;
  
            case 3:        
                 printf("\n1.Get Start. \n2.Get End. \n3.Pop Start. \n4.Pop End. \nEnter your choice = ");
                 scanf("%d",&choice);

                 switch(choice)
                 {
                 	case 1:
                 	    if(get_start(p_list,&ex_data))
                 	    	printf("\nStarting Data = %d\n",ex_data);
                 	    else
                 	    	printf("\nList is Empty.....\n");
                 	break;

                 	case 2:
                 	     if(get_end(p_list,&ex_data))
                 	     	printf("\nLast Data = %d\n",ex_data);
                 	     else
                 	    	printf("\nList is Empty.....\n");
                 	break;

                 	case 3:
                 	     if(pop_start(p_list,&ex_data))
                 	     	printf("\nDeleted Data = %d\n",ex_data);
                 	     else
                 	    	printf("\nList is Empty.....\n");
                 	break;

                 	case 4:
                 	     if(pop_end(p_list,&ex_data))
                 	     	printf("\nDeleted Data = %d\n",ex_data);
                 	     else
                 	    	printf("\nList is Empty.....\n");
                 	break;

                 	default:
                 	   printf("\nYou Entered Wrong Choice, Please Enter correct choice..\n");
                 	break;
                 }
            break;

            case 4:
                  printf("\n1.Find. \n2.Count \n3.Enter your choice = ");
                  scanf("%d",&choice);

                  switch(choice)
                  {
                  	case 1:
                         printf("\nEnter data  =  ");
                         scanf("%d",&ex_data);

                         if(find_list(p_list,ex_data))
                         	printf("\n%d is present in list\n",ex_data);
                         else
                         	printf("\n%d is not present in list\n",ex_data);
                  	break;

                  	case 2:
                  	     ex_data = length_t(p_list);
                  	     printf("\nTotal Number of data is present in list is = %d\n",ex_data);
                  	break;

                  	default:
                  	     printf("\nYou Entered Wrong Choice, Please Enter correct choice..\n");
                  	break;
                  }
            break;

            case 5:
                printf("\n1.Remove Beginning. \n2.Remove Last. \n3.Remove Data. \nEnter Your Choice = ");
        	    scanf("%d",&choice);

        	    switch(choice)
        	    {
        	    	case 1:
        	    	     if(remove_beg(p_list))
        	    	     	printf("\nData Removed at Beginning Successfully.....\n");
        	    	     else
        	    	     	printf("\nLise is Empty.....\n");
        	    	break;

        	    	case 2:
        	    	     if(remove_end(p_list))
        	    	     	printf("\nData Removed at Last Successfully.....\n");
        	    	     else
        	    	     	printf("\nLise is Empty.....\n");
        	    	break;

        	    	case 3:
        	    	     printf("\nEnter Data = ");
        	    	     scanf("%d",&ex_data);

        	    	     if(remove_data(p_list,ex_data))
        	    	     	printf("\n%d is Removed Successfully.....\n",ex_data);
        	    	     else
        	    	     	printf("\nLise is Empty.....\n");
        	    	break;

        	    	default:
                  	    printf("\nYou Entered Wrong Choice, Please Enter correct choice..\n");
                 	break;
        	    }
            break;
            

            case 6:
                 show(p_list);
            break;

            case 7:
                 printf("\nAre you sure to Delete a Complete List[Yes/No] = ");
                 scanf("%s",str);

                 if(strcmp(str,"Yes") == 0 ||strcmp(str,"YES") == 0 || strcmp(str,"yes") == 0)
                 {
                      if(destroy_list(p_list))
                      	printf("\nList is Destroyed Successfully.....\n");
                 }
                 else if(strcmp(str,"No") == 0 ||strcmp(str,"NO") == 0 || strcmp(str,"no") == 0)
                 {
                       printf("\nOk....\n");
                 }
                 else
                 {
                 	printf("\nPlease Enter Correct Choice\n");
                 }
            break;

            case 8:
                 if(p_list != NULL)
                    destroy_list(p_list);

                
                 printf("\nThank You.....\n\n");
            break;

        	default:
        	    printf("\nYou Entered Wrong Choice, Please Enter correct choice..\n");
        	break;
        }

	}while(choice != 8);

	return 0;
}

