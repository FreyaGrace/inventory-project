#ifndef MENU_H
#define MENU_H
//**********************************************************
// CLASS NAME : Menu
// DETAILS : THIS IS THE FIRST CLASS TO BE CALLED IN THE MAIN PROGRAM
//**********************************************************
#include "product.h"
class menu
{
   	public: 
   	   void  main_menu();//displays main menu
       void edit_menu(void) ;//displays the edit menu to mdify product
       void admin1(void);//displays the admin control panel
    private:
       product ad;//I created the object ad for class product in class menu to access attributes
} ;
#endif
