#include "product.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include<cstring>
#include<string>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include <sstream>
using namespace std;
product::product()
{
	
}
void product:: add()
{
	fstream data;
	int c;
	float p;
	float d;
	string n;
	y:
	int token =0;
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product:";
	cin>>pcode;
	cout<<"\n\n\t Name of the product:";
	cin>>pname;
	cin.clear();
	cout<<"\n\n\t price of the product:";
	cin>>price;
	cout<<"\n\n\t Discount on product:";
	cin>>dis;
	data.open("database.txt", ios::in);
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	if(token==1)
	goto y;
	else {
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
}

}
void product::show()//displays a single product
{
		cout<<endl<<"Product #: "<<pcode;
		cout<<endl<<"Product Name: "<<pname;
		cout<<endl<<"Product Price: "<<price;
		cout<<endl<<"Discount : "<<dis;
}



void product::modify()
{
	fstream data, data1;
	int c;
	float p;
	float d;
	string n;
	int pkey;
	int token=0;
	cout<<"\n\t\t\t Modify Product";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\nFile does not exist";
	}
	else
	{
		data1.open("edit.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				show();
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;	
				data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<" \n";
				cout<<"\n\n\t\t Record Successfully Updated!"; 
				token++;
			}
			else
			{
			   data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("edit.txt", "database.txt");
	if(token==0)
	{
		cout<<"\n\n Record not Found";
	}
	}
}
	
void product::rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t\t Delete Product";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\nFile does not exist";
	}
	else
	{
		data1.open("delete.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
			cout<<"\n\n\t Product deleted succesfully";
		
			token++;
			}
			else
			{
			   data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("delete.txt", "database.txt");
	if(token==0)
	{
		cout<<"\n\n Record not Found";
	}
}

}

void product::list()
{
	fstream data;
	data.open("database.txt", ios::in);
		if(!data)
	{
		cout<<"\n\nFile does not exist";
	}
	else
	{

	cout<<"\n\n\n\t\t\t\t*************ITEM LIST*************\n\n";
	cout<<"***************************************************************************************************************\n";  
  	cout<<"\n\n\n\t\t\t\tProduct No.\t\tName\t\tPrice\t\tDiscount\n";
  	cout<<"________________________________________________________________________________________________________________\n";
  	data>>pcode>>pname>>price>>dis;
  	while(!data.eof())
  	{
  		cout<<"\n\n\n\t\t\t\t"<<pcode<<"  \t\t\t"<<pname<<" \t\t"<<price<<"\t\t"<<dis<<"\n";
  		data>>pcode>>pname>>price>>dis;
  		
	}
	data.close();
		}
}
void product::purchase()
{
	fstream data, data1;
	int arrc[100];
	int arrq[100];
	int c=0;
	float amount;
	float dis=0;
	float total=0;
	char ch;
	cout<<"\n\n\t\t\t\t\t     Receipt ";
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		
		
		list();
		k:
		cout<<"\n________________________________________________________________________________________________________________\n";
		cout<<"\n                                          Please place your order        \n";
		cout<<"\n________________________________________________________________________________________________________________\n";
		cout<<"\n\n\n Enter transaction ID:";
		cin>>id;
		do 
		{
			cout<<"\n\n Product code :";
			cin>>arrc[c];
			cout<<"\n\n Enter Quantity :";
			cin>>arrq[c];
			c++;
			for(int i=0; i<c; i++)
			{
				if(arrc[c]==arrc[i])// this is to avoid duplication of product
				{
					cout<<"\n\n This item has already been added to the cart";
					goto k;
				}
			}
			cout<<"\n\n Do you want to buy another product?(y/n)";
			cin>>ch;
		}
		while(ch=='y'||ch=='Y');
		system("cls");
		cout<<"\n\n\t\t\t\t\tThank You for purchasing!";
		getch();
	system("cls");
	data1.open("transaction.txt", ios::app|ios::out);
	cout<<"\n\n********************************INVOICE************************\n";
	cout<<"\nPr No.\tProduct Name\tQuantity\tPrice\tAmount\tAmount after discount\n";
	
	for(int i=0; i<=c; i++)
	{
	
		data.open("database.txt", ios::in);
		data>>pcode>>pname>>price>>dis;
		while (!data.eof())
		{
			if(pcode==arrc[i])
			{
				amount=price*arrq[i];
				dis=amount-(amount*dis/100);
				total=total+dis;
				cout<<"\n"<<pcode<<"\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
				qty=arrq[i];
				data1<<id<<"\t"<<pcode<<"\t"<<pname<<"\t"<<qty<<"\t"<<price<<"\t"<<amount<<"\t"<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
	 data1.close();
	}
	 
	}
	cout<<"\n\n______________________________________";
	cout<<"\n Total Amount : "<<total;
}


void product::search_product()
{
	fstream data;
	int key;
	int token=0;
	cout<<"Please enter product code :";
	cin>>key;
	data.open("database.txt", ios::in);
		if(!data)
	{
		cout<<"\n\nFile does not exist";
	}
	else
	{
	system("cls");
	cout<<"\n\n\n\t\t\t\t************SEARCH  RECORD************\n";
	cout<<"***************************************************************************************************************\n";  
  	cout<<"________________________________________________________________________________________________________________\n";
  	
  	while(data>>pcode>>pname>>price>>dis)
  	{
  		if(key==pcode)
  		{
  		show(); 	/*it may sometimes not read #1 and may not wwork*/
  			token++;
		}
  		data>>pcode>>pname>>price>>dis;
	}
	data.close();
	if(token==0)
	{
		cout<<"\n\n Record not Found";
	}
		}
}
void product::transaction_report()
{
	string file, line;
	fstream indata;
	string ext = ".txt"; //file extension
	cout<<"Enter text filename to read:";
	cin.ignore();
	getline(cin,file);
	file += ext;//appends ext to file  
	cout<<"\n\n\n\n\n\t\t\t\t\t\tReading from file.";
                				for(int x=0;x<6;x++)
               					 {
                   					 Sleep(500);
                   					 cout<<".";
                			   	 }//  t<<"Reading from file...";
    cout<<"\n\n\n";
    indata.open(file.c_str());//opens file	
	if (indata.is_open())
  {
  	cout<<"\nTransaction ID\tProduct #\tProduct Name\tPurchased\tPrice\tAmount\tTotal (with Discount)\n";
    while ( getline (indata,line) )
    {
      cout << line << '\n';//displayed the contents of the text to the console
    }
    indata.close();
}
}

void product::search_transaction() 
{
	ifstream data;
	int id2;
	int token=0;
	cout<<"Please enter transaction ID :";
	cin>>id2;
	data.open("transaction.txt", ios::in);
	if(!data)
	{
		cout<<"\n\nFile does not exist";
	}
	else
	{
	system("cls");
	cout<<"\n\n\n\t\t\t\t************SEARCH  RECORD************\n";
	cout<<"***************************************************************************************************************\n";  
  	cout<<"________________________________________________________________________________________________________________\n";
  	cout<<"\nTransaction ID\tProduct #\t\t\tProduct Name\tPurchased\tPrice\tAmount\tTotal (with Discount)\n";
  	string record, field;
    // while there are records in the file
    while(getline(data, record)) {
        istringstream ss(record);
        ss >> id;
        // Check to see if target id equals record id
        if(id2 == id) {
           
            // It does, so let's print the rest of the fields
            while(getline(ss, field, ',')) {
                cout<< id<<field <<endl;
                token++;
            }
            cout << endl;
        }
    }
	data.close();
	if(token==0)
	{
		cout<<"\n\n Record not Found";
	}
		}
}
