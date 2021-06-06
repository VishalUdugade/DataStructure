#include <iostream>
#include "list.h"
#include <stdexcept>
#include <cstring>

using namespace std;


int main()
{
    list* p_list = NULL;
    data_t n_data = 0,choice = 0,ex_data = 0;
    string str;

    cout <<"\n================================= Linked List =================================\n" << endl;
    do
    {
               cout << "\n1.Create List. \n2.Insert. \n3.Get & Pop. \n4.Find & Count. \n5.Remove. \n6.Show List. \n7.Destory List. \n8.Exit \n\nEnter Your Choice =  ";
               cin >> choice;

               if(p_list == NULL && (choice <= 7 && choice >= 2))
               {
                  cout << "\nList is Not Created First Create a List\n" << endl;
                  continue;
               }

               switch(choice)
               {
                      case 1:
        	               if(p_list == NULL)
        	               {
                                p_list = new list;
                                cout << "\nList is Created Successfully...\n" << endl;
        	               }
                           else
                           {
                               	cout << "\nList is already Created..\n" << endl;
                           }
        	          break;


        	          case 2:
        	                 cout <<"\n1.Insert Beginning. \n2.Insert Last. \n3.Insert After. \n4.Insert Before. \nEnter Your Choice = ";
        	                 cin >> choice;
                
                             cout << "\nEnter New Data = ";
                             cin >> n_data;

                             switch(choice)
                             {
                                	case 1:
                                         if(p_list->insert_start(n_data))
                                         {
                       	                        cout <<"\nData Inserted Successfully....\n" << endl;
                                         } 
                                         
                	                break;

                	                case 2:
                	                    if(p_list->insert_end(n_data))
                	                    {
                                          	  cout <<"\nData Inserted Successfully....\n" << endl;
                	                    }
                                       
                	                break;

                	                case 3:
                	                     cout <<"\nEnter Existing Data that New Data is Inserted After  = " ;
                	                     cin >> ex_data;

                	                      try
                	                      {
                	                      	  p_list->insert_after(ex_data,n_data);
                	                      	      cout << "\nData Inserted Successfully....\n" << endl;

                	                      }catch(list_data_not_found& e)
                	                      {
                	                      	  cout << e.what() << endl;
                	                      }                	                    
                	                break;


                	                case 4:
                	                      cout <<"\nEnter Existing Data that New Data is Inserted After  = " ;
                	                      cin >> ex_data;

                	                      try
                	                      {
                                               p_list->insert_before(ex_data,n_data);
                                                  cout << "\nData Inserted Successfully....\n" << endl;

                	                      }catch(list_data_not_found& e)
                	                      {
                	                      	 cout << e.what() << endl;
                	                      }
                	                 break;


                	                  default:
                	                         cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
                	                  break;
                             }
        	            break;


        	            case 3:        
                                cout <<"\n1.Get Start. \n2.Get End. \n3.Pop Start. \n4.Pop End. \nEnter your choice = ";
                                cin >> choice;

                                switch(choice)
                                {
                                     	case 1:
                                     	    try
                                     	    {
                                                p_list->get_start(&ex_data);
                                                   cout << "\nStarting Data = " << ex_data << endl;
                                     	    }catch(list_empty& e)
                                     	    {
                                                 cout << e.what() << endl;
                                     	    }
                 	                    break;

                                        case 2:
                                            try
                                     	    {
                                                p_list->get_end(&ex_data);
                                                   cout << "\nLast Data = " << ex_data << endl;
                                     	    }catch(list_empty& e)
                                     	    {
                                                 cout << e.what() << endl;
                                     	    }               	                         
                                         break;

                                      	case 3:
                                      	    try
                                     	    {
                                                p_list->pop_start(&ex_data);
                                                   cout << "\nDeleted Data = " << ex_data << endl; 
                                     	    }catch(list_empty& e)
                                     	    {
                                                 cout << e.what() << endl;
                                     	    }                   	                         
                 	                    break;

                 	                    case 4:
                 	                         try
                                     	    {
                                               p_list->pop_end(&ex_data);
                                                   cout << "\nDeleted Data = " << ex_data << endl; 
                                     	    }catch(list_empty& e)
                                     	    {
                                                 cout << e.what() << endl;
                                     	    } 
                                     	break; 


                 	                   default:
                 	                         cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
                 	                   break;
                        }
                        break;


                        case 4:
                             cout <<"\n1.Find. \n2.Count \n3.Enter your choice = " ;
                             cin >> choice;

                            switch(choice)
                            {
                             	case 1:
                                    cout <<"\nEnter data  =  ";
                                    cin >> ex_data;
                                     
                                    try
                                    {
                                         p_list->find_list(ex_data);
                                          cout << ex_data <<  "\n is present in list" << endl;
                                    }catch(list_data_not_found& e)
                                    {
                                    	cout << e.what() << endl;
                                    }                                 
                               	break;

                  	            case 2:
                  	                 ex_data = p_list->get_length();
                  	                 cout <<"\nTotal Number of data is present in list is = " << ex_data << endl;
                            	break;

                            	default:
                  	                 cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
                  	            break;
                            }
                        break;

                        
                        case 5:
                              cout <<"\n1.Remove Beginning. \n2.Remove Last. \n3.Remove Data. \nEnter Your Choice = " ;
        	                  cin >> choice;

        	                 switch(choice)
        	                 {
        	                      	case 1:
        	                      	      try
        	                      	      {
                                               p_list->remove_beg();
                                                  cout << "\nData Removed at Beginning Successfully.....\n" << endl;
        	                      	      }catch(list_empty& e)
        	                      	      {
                                               cout << e.what() << endl;
        	                      	      }
        	    	                break;

        	    	                case 2:
        	    	                      try
        	                      	      {
                                               p_list->remove_end();
                                                  cout << "\nData Removed at Last Successfully.....\n" << endl;
        	                      	      }catch(list_empty& e)
        	                      	      {
                                               cout << e.what() << endl;
        	                      	      }       	    	                   
        	    	                break;

        	                    	case 3:
        	    	                    cout <<"\nEnter Data = ";
        	    	                    cin >> ex_data;


                                          try
        	                      	      {
                                               p_list->remove_data(ex_data);
                                                  cout << "\nis Removed Successfully.....\n" << endl;
        	                      	      }catch(list_empty& e)
        	                      	      {
                                               cout << e.what() << endl;
        	                      	      }       	    	                    
        	    	                break;

        	    	                default:
                  	                     cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
                 	                break;
        	                 }
                        break;



                        case 6:                             
                                 cout << *p_list;     
                        break;

                        
                        case 7:
                             cout <<"\nAre you sure to Delete a Complete List[Yes/No] = ";
                             cin >> str;
     
                             if(str.compare("Yes") == 0 || str.compare("YES") == 0 || str.compare("yes") == 0)
                             {
                                delete p_list;
                                p_list = NULL;
                             	   cout <<"\nList is Destroyed Successfully.....\n" << endl;
                             }
                             else if(str.compare("No") == 0 || str.compare("NO") == 0 || str.compare("no") == 0)
                             {
                                   cout <<"\nOk....\n" << endl;
                             }
                             else
                             {
                                	cout <<"\nPlease Enter Correct Choice\n" << endl;
                             }
                        break;


                        case 8:
                            if(p_list != NULL)
                                p_list->~list();

                             delete (p_list);
                             p_list = NULL;
                             cout << "\nThank You.....\n\n" << endl;
                             return (0);
                        break;


                        default:
        	                cout << "\nYou Entered Wrong Choice, Please Enter correct choice..\n" << endl;
        	            break;
  
                }

    }while(1);

	return(0);
}
