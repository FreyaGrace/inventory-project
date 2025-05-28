#include "menu.h"
#include "product.h"
#include <iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
//**********************************************************
// THIS FUNCTION SHOWS THE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************
void menu::main_menu()
{ 	int choice;
string email, password;
m:
	system("cls");
	system("color 0A");
	 cout<<"\n\n\n\t\t\t\t**************************************************";
        cout<<"\n\t\t\t\t* WELCOME TO THE INVENTORY SYSTEM MANAGEMENT *";
        cout<<"\n\t\t\t\t**************************************************";    
        cout<<"\n\n\n\t\t\t\t************CONTROL PANEL************\n\n\n\n";
        cout<<"\t\t\t\t [1]Administration\n";
        cout<<"\t\t\t\t [2]Customer\n";
        cout<<"\t\t\t\t [0]Exit\n";
        
 cout<<"\n\n\t\t\t\t\t\tEnter Your Choice : ";
 cin>>choice;	
 switch(choice)
		{
			case 1: 
					l:
					system("cls");
					cout<<"\n\n\n\t\t\t\t\t\t\tLOGIN PAGE";
                	cout<<"\n\n\n\n\t\t\tEmail: ";
                	cin>>email;
                	cout<<"\n\n\n\n\t\t\tPASSWORD: ";
               	 	cin>>password;
               	 	
               	 	if(email=="wvsu25@gmail.com" && password=="wvsu25")
               	 	{
               	 		admin1();
					}
					else
					{   system("cls");
						cout<<"\n\n\n\n\t\t\tIncorrect..please try again..";
						cout<<"\n\n\n\t\t\tPress any key to continue";
						getch();
						goto l;//if incorrect, it will go to l which is the login page
						
					}
					break;
					
			case 2: 
					
					system("cls");
					ad.purchase();
					cout<<"\n\n\n\t\t\tPress any key to continue";
					getch();
					main_menu();
					break;
					
			case 0: 
					system("cls");
					cout<<"\n\t\t\t\t\t\tGood Bye!";
					exit(0);
			
			default :
					cout<<"Please select from the given option...\n";
					goto m;//goes back to main 
 }
    }


//**********************************************************
// THIS FUNCTION SHOWS THE EDIT MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: edit_menu(void)
{
	system("cls");
    int ch ;
        cout <<"\n\n\n\n\n\t\t\t\t[1: ADD PRODUCTS\n" ;
        cout <<"\n\t\t\t\t[2: MODIFY PRODUCTS\n" ;
        cout <<"\n\t\t\t\t[3: DELETE PRODUCTS\n" ;
        cout <<"\n\t\t\t\t[0: EXIT\n" ;
        cout <<"\n\t\t\t\t[Enter Choice : " ;        
        cin>>ch;
      switch(ch)
      {
        case 1:
        {
          system("cls");
          ad.add();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			edit_menu();
          break;
        }
        case 2:
        {
         system("cls");
          ad.modify();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			edit_menu();
          break;
        }
        case 3:
        {
         system("cls");
          ad.rem();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			edit_menu();
          break;
        }

           case 0:
        {
         system("cls");
          admin1();
          break;
        }
        default :
					cout<<"Please select from the given option...\n";
					main_menu();//goes back to main 
      }
    }
//**********************************************************
// THIS FUNCTION SHOWS THE ADMIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************
void menu :: admin1(void)
{
	system("cls");
    int ch ;
        cout <<"\n\n\n\n\n\t\t\t\t[1: LIST OF PRODUCTS\n" ;
        cout <<"\n\t\t\t\t[2: SEARCH PRODUCT\n" ;
        cout <<"\n\t\t\t\t[3: EDIT PRODUCTS FILE\n" ;
        cout <<"\n\t\t\t\t[4: TRANSACTIONS REPORT\n" ;
		cout <<"\n\t\t\t\t[5: SEARCH TRANSACTION\n" ;
        cout <<"\n\t\t\t\t[0: LOGOUT\n" ;
        cout <<"\n\t\t\t\t[Enter Your Choice : " ;
	    cin>>ch;
	    switch(ch)
      {
        case 1:
        {
          system("cls");
    	  ad.list();
    	  cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			admin1();
          break;
        }
        case 2:
        {
        system("cls");
         ad.search_product();
         cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			admin1();
          break;
        }
        case 3:
        {
        system("cls");
         edit_menu();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			admin1();
          break;
        }
        case 4:
        {
          system("cls");
          ad.transaction_report();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			admin1();
          break;
        }
     	 case 5:
        {
          system("cls");
          ad.search_transaction();
          cout<<"\n\n\t\t\t                PRESS ANY KEY TO CONTINUE...";
  			getch();
   			admin1();
          break;
        }

           case 0:
        {
        system("cls");
         main_menu();
          break;
        }
        default :
					cout<<"Please select from the given option...\n";
					main_menu();//goes back to main 
      }
  }
