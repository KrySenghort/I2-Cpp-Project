

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include <time.h>
#include <string.h>
#include <ctime>
using namespace std;
char load=219;
int size = 0;
class node{
public:
    int pin;
    float balance;
    double balanceriel;
    string id,pass,name,fname,address,phone;
    node *next,*pre,*left,*right;
    node(){
        id = "NULL";
        balance = 0;
        pin = 0;
        pass = "NULL";
        name = "NULL";
        fname = "NULL";
        address = "NULL";
        phone = "NULL";
    }
    node(string id,string pass,string name,string fname,string address,string phone,int pin,float balance){
        this->id = id;
        this->pass = pass;
        this->name = name;
        this->fname = fname;
        this->address = address;
        this->phone = phone;
        this->pin = pin;
        this->balance = balance;
    }
};
class manage : public node{
protected:
    node *root = NULL;
    node *head = NULL;
    node *tail = NULL;
public:
    void menu();
    void bank();
    void atm();
    void load_data();
    void load_data1();
    void load_data2();
    void New_user();
    void createNewaccount();
    void createReilaccount();
    void createSavingaccount();
    void editRecord();
    void updateNewaccount();
    void update();
    void saving();
    void withdraw();
    void transfer();
};
void manage::menu(){
    p:
    system("cls");
    int choice;
    string ch;
    string pin,pass,email;
    cout<<"\n\n\t\t\t Control Panel ";
    cout<<"\n\n 1.Bank Management ";
    cout<<"\n\n 2.ATM Management ";
    cout<<"\n\n 3. Exit ";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            system("cls");
            system("color 0A");
	        cout<<"\n\n\n\n\n\n";
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      |      Detail     |     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int i=0;i<=31;i++)
	        cout<<load;
	        cout<<"\n";
            cout<<"\n\n\t\t\t Login Account ";
            cout<<"\n\n\t\t\t Email : ";
            cin>>email;
            cout<<"\n\n\t\t\t Pin code :";
            for(int i=1; i<=5; i++){
                ch = getch();
                pin += ch;
                cout<<"*";
            }
            cout<<"\n\n\t\t\t PassWord : ";
            for(int i=1; i<=5; i++){
                ch = getch();
                pass += ch;
                cout<<"*";
            }
            if(email == "ngimpanha@gmail.com"  && pin == "11111" && pass == "11111"){
                bank();
            }else{
                	system("cls");
                	system("color 0C");
		            cout<<"\n\n\n\n\n\n";
	                cout<<"\t\t\t\t\t";
	                for(int i=0;i<=31;i++)
	                cout<<load;
                    cout<<"\n";
	                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                    cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	                cout<<"\t\t\t\t\t";
	                for(int j=0;j<=31;j++)
	                cout<<load;
	                cout<<"\n";
                    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	                cout<<"\t\t\t\t\tPlease Enter Correct ID and PIN\n";
	                cout<<"\t\t\t\t\t Your E-mail,Pin,Password is Wrong";
     	            cout<<"\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     	            _getch();

            }

        }break;
        case 2:{
            atm();
        }break;
        case 3:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
void manage::bank(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t Management System ";
    cout<<"\n\n\t\t\t 1. Create New Account  ";
    cout<<"\n\n 2. Already User  ";
    cout<<"\n\n 3. Deposit option ";
    cout<<"\n\n 4 . Withdraw option ";
    cout<<"\n\n 5 . Transfer option ";
    cout<<"\n\n 6 . payment option ";
    cout<<"\n\n 7 . Search User Record ";
    cout<<"\n\n 8 . Edit User Record ";
    cout<<"\n\n 9 . Delete User Record ";
    cout<<"\n\n 10 . Show User Records ";
    cout<<"\n\n 11 . Payment All Records ";
    cout<<"\n\n 12 . Go Back ";
    cout<<"\n\n  Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            New_user();
        }break;
        case 2:{
            saving();
        }break;
        case 3:{
            withdraw();
        }break;
        case 4:{
            transfer();
        }break;
        case 5:{

        }break;
        case 6:{
        }break;
        case 7:{
        }break;
        case 8:{
        }break;
        case 9:{
        }break;
        case 10:{
        }break;
        case 11:{
        }break;
        case 12:{
            menu();
        }break;
        default:{
            cout<<"\n\n\t\t\t Invalid value ... Please Try Again "<<endl;;
        }
    }
    getch();
    goto p;

}
void manage::atm(){
}
void manage::New_user(){
    p:
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=31;j++)
    cout<<load;
    cout<<"\n";
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=31;j++)
    cout<<load;
    cout<<"\n";
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"      |      Detail     |     "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"   Create Saving account      "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"   Create Reil account        "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"   Create daily lift account  "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"   Setting account            "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t";
    for(int i=0;i<=31;i++)
	cout<<load;
	cout<<"\n";
	getch();
	system("cls");


    system("color 0A");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
	cout<<load;
	cout<<"\n\n\n";
	cout<<"\t\t\t      Loading ";

	for(int i=0; i<35; i++)
	{
		cout<<load;
		if(i<10)
		Sleep(300);
		if(i>=10 && i<20)
		Sleep(150);
		if(i>=10)
		Sleep(25);
	}
    int choice;
    cout<<"\n\n\t\t\t 1. Account for Daily Life "<<endl;
    cout<<"\n\n\t\t\t 2. Account for Rail       "<<endl;
    cout<<"\n\n\t\t\t 3. Account for Saving     "<<endl;
    cout<<"\n\n\t\t\t 4. Edit     "<<endl;
    cout<<"\n\n\t\t\t 5. Back to Many function   "<<endl;
    cout<<"\n\n\t\t\tSelect your option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            createNewaccount();
        }break;
        case 2:{
            createReilaccount();
        }break;
        case 3:{
            createSavingaccount();
        }break;
        case 4:{
            editRecord();
        }break;
        case 5:{
            bank();
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again "<<endl;
        }
    }
    getch();
    goto p;
}
void manage::load_data(){
    fstream file;
    int e_pin;
    float e_balance;
    string e_id,e_pass,e_name,e_fname,e_address,e_phone;
    file.open("kaa.txt",ios::in);
    if(file){
        file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance;
        while(!file.eof()){
            node *new_node = new node;
		    new_node->id = e_id;
            new_node->name = e_name;
            new_node->fname = e_fname;
            new_node->address = e_address;
            new_node->phone = e_phone;
            new_node->pass = e_pass;
            new_node->pin = e_pin;
            new_node->pass = e_pass;
            new_node->balance = e_balance;
		    new_node -> left = NULL;
		    new_node -> right = NULL;
		    if(root == NULL){
			    root = new_node;
		    }
		    else{
			    node *ptr = root;
			    node *pre = NULL;
			    while(ptr != NULL){
				   if(e_id > ptr->id){
					   pre = ptr;
					   ptr = ptr -> right;
					  if(ptr == NULL){
						pre -> right = new_node;
					  }
				   }else if(e_id < ptr->id){
					   pre = ptr;
					   ptr = ptr -> left;
					   if(ptr == NULL){
						   pre -> left = new_node;
					   }
				   }
				   else{
					   delete new_node;
					   break;
				   }
			    }
            }
            file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance;
        }
        file.close();
    }
}
void manage::createNewaccount(){
    fstream file;
    manage l;
    system("cls");
    int pin1;
    float balance1;
    string id1,pass1,name1,fname1,address1,phone1;
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id1;
    cout<<"\n\n\t\t Name : ";
    cin>>name1;
    cout<<"\n\n Father Name :";
    cin>>fname1;
    cout<<"\n\n Address :";
    cin>>address1;
    cout<<"\n\n Pin code (5 digit):";
    cin>>pin1;
    cout<<"\n\n Password :";
    cin>>pass1;
    cout<<"\n\n Phone Number :";
    cin>>phone1;
    cout<<"\n\n Current Balance :";
    cin>>balance1;
    node *new_node = new node;
    new_node->id = id1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->pass = pass1;
    new_node->phone = phone1;
    new_node->balance = balance1;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL){
        root = new_node;
    }else{
        node *ptr = root;
        node *pre = NULL;
        while(ptr != NULL){
            if(id1 > ptr->id){
                pre = ptr;
                ptr = ptr->right;
                if(ptr == NULL){
                    pre->right = new_node;
                }
            }else if(id1 < ptr->id){
                pre = ptr;
                ptr = ptr->left;
                if(ptr == NULL){
                    pre->left = new_node;
                }
            }else{
                delete new_node;
                break;
            }
        }
    }
    file.open("kaa.txt",ios::app|ios::out);
    file<<id1<<" "<<name1<<" "<<fname1<<" "<<pass1<<" "<<pin1<<" "<<address1<<" "<<phone1<<" "<<balance1<<" \n";
    file.close();
    cout<<"\n\n Add New User Account create Successfully...";
}
void manage::load_data1(){
    fstream file;
    int pin1;
    double balance1;
    string id1,pass1,name1,fname1,address1,phone1;
    file.open("yaa.txt",ios::in);
    if(file){
        file>>id1>>pass1>>pin1>>name1>>fname1>>address1>>phone1>>balance1;
        while(!file.eof()){
            node *new_node = new node;
            new_node->id = id1;
            new_node->name = name1;
            new_node->fname = fname1;
            new_node->address = address1;
            new_node->pin = pin1;
            new_node->pass = pass1;
            new_node->phone = phone1;
            new_node->balanceriel = balance1;
            new_node->pre = NULL;
            new_node->next = NULL;
		    if(head == NULL){
			    head = new_node;
			    tail = new_node;
		    }
            else{
			    tail -> next = new_node;
			    new_node -> pre = tail;
			    tail = new_node;
		    }
            file>>id1>>pass1>>pin1>>name1>>fname1>>address1>>phone1>>balance1;
        }
        file.close();
    }
}
void manage::createReilaccount(){
    fstream file;
    manage l;
    system("cls");
    int pin1;
    double balance1;
    string id1,pass1,name1,fname1,address1,phone1;
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id1;
    cout<<"\n\n\t\t Name : ";
    cin>>name1;
    cout<<"\n\n Father Name :";
    cin>>fname1;
    cout<<"\n\n Address :";
    cin>>address1;
    cout<<"\n\n Pin code (5 digit):";
    cin>>pin1;
    cout<<"\n\n Password :";
    cin>>pass1;
    cout<<"\n\n Phone Number :";
    cin>>phone1;
    cout<<"\n\n Current Balance :";
    cin>>balance1;
    node *new_node = new node;
    new_node->id = id1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->pass = pass1;
    new_node->phone = phone1;
    new_node->balanceriel = balance1;
    new_node->pre = NULL;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        new_node -> pre = tail;
        tail = new_node;
    }
    file.open("yaa.txt",ios::app|ios::out);
    file<<id1<<" "<<name1<<" "<<fname1<<" "<<pass1<<" "<<pin1<<" "<<address1<<" "<<phone1<<" "<<balance1<<" \n";
    file.close();
    cout<<"\n\n Add New User Account create Successfully...";
}
void manage::load_data2(){
    fstream file;
    manage l;
    int pin1;
    float balance1;
    double balanceriel1;
    string id1,pass1,name1,fname1,address1,phone1;
    file.open("jaa.txt",ios::in);
    if(file){
        file>>id1>>pass1>>pin1>>name1>>fname1>>address1>>phone1>>balance1>>balanceriel1;
        while(!file.eof()){
             node *new_node = new node;
             new_node->id = id1;
             new_node->name = name1;
             new_node->fname = fname1;
             new_node->address = address1;
             new_node->pin = pin1;
             new_node->pass = pass1;
             new_node->phone = phone1;
             new_node->balance = balance1;
             new_node->balanceriel = balanceriel1;
             new_node->next = NULL;
    //         size++;
             if(head == NULL){
                head = new_node;
                tail = new_node;
                new_node->next = head;
             }
             else{
                tail->next = new_node;
                tail = new_node;
                tail->next = head;
             }
            file>>id1>>pass1>>pin1>>name1>>fname1>>address1>>phone1>>balance1>>balanceriel1;
        }
        file.close();
    }
}
void manage::createSavingaccount(){
    fstream file;
    manage l;
    int pin1;
    float balance1;
    double balanceriel1;
    string id1,pass1,name1,fname1,address1,phone1;
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id1;
    cout<<"\n\n\t\t Name : ";
    cin>>name1;
    cout<<"\n\n Father Name :";
    cin>>fname1;
    cout<<"\n\n Address :";
    cin>>address1;
    cout<<"\n\n Pin code (5 digit):";
    cin>>pin1;
    cout<<"\n\n Password :";
    cin>>pass1;
    cout<<"\n\n Phone Number :";
    cin>>phone1;
    cout<<"\n\n Current Balance :";
    cin>>balance1;
    cout<<"\n\n Current Balance :";
    cin>>balanceriel1;
    node *new_node = new node;
    new_node->id = id1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->pass = pass1;
    new_node->phone = phone1;
    new_node->balance = balance1;
    new_node->balanceriel = balanceriel1;
    new_node->next = NULL;
  //  size++;
    if(head == NULL){
        head = new_node;
        tail = new_node;
        new_node->next = head;
    }else{
        tail->next = new_node;
        tail = new_node;
        tail->next = head;
    }
    file.open("jaa.txt",ios::app|ios::out);
    file<<id1<<" "<<name1<<" "<<fname1<<" "<<pass1<<" "<<pin1<<" "<<address1<<" "<<phone1<<" "<<balance1<<balanceriel1<<" \n";
    file.close();
    cout<<"\n\n Node is Inserted Successfully...";
}
void manage::editRecord(){
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=31;j++)
    cout<<load;
    cout<<"\n";
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=31;j++)
    cout<<load;
    cout<<"\n";
	int choice;
	cout<<"\n\n\t\t\t 1. Update Daily lift account ";
	cout<<"\n\n\t\t\t 2. Update Riel account ";
	cout<<"\n\n\t\t\t 3. Update Saving account ";
	cout<<"\n\n\t\t\t 4.  Back to Many function ";
	cout<<"\n\n\t\t\t Select  Your Option : ";
	cin>>choice;
	switch(choice){
	    case 1:{
	        root = NULL;
	        load_data1();
	        updateNewaccount();
	    }break;
	    case 2:{
	    }break;
	    case 3:{
	    }break;
	    case 4:{
	    }break;
	    default:{
	        cout<<"\n\n\t\t\t Invalid choice ....";
	    }
	}
}
void manage::updateNewaccount(){
    system("cls");
    fstream file,file1;
    int t_pin,pin1,pin,found = 0;
    string t_id,id1,id;
    float balance1;
    string pass1,name1,fname1,address1,phone1;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(root == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }
    else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("kaa.txt",ios::in);
        file1.open("kaa2.txt",ios::app|ios::out);
        file>>id1>>name1>>fname1>>pass1>>pin1>>address1>>phone1>>balance1;
        while(!file.eof()){
            if(t_id == id1){
                cout<<"\t\t\t===================================\n";
                cout<<"\t\t\t   Setting ALL  Record      "<<endl;
                cout<<"\t\t\t===================================\n";
                cout<<"\n\n\t\t\t Employee New ID :";
                cin>>id;
                cout<<"\n\n\t\t\t Employee New PIN :";
                cin>>pin;
                file1<<id1<<" "<<name1<<" "<<fname1<<" "<<pass1<<" "<<pin1<<" "<<address1<<" "<<phone1<<" "<<balance1<<"\n";
                cout<<"\n\n\t\t\t Adit Record Successfully....";
                found++;
            }
            else{
                file1<<id1<<" "<<name1<<" "<<fname1<<" "<<pass1<<" "<<pin1<<" "<<address1<<" "<<phone1<<" "<<balance1<<"\n";
            }
            file>>id1>>name1>>fname1>>pass1>>pin1>>address1>>phone1>>balance1;
        }
        file.close();
        file1.close();
        remove("kaa.txt");
        rename("kaa2.txt","kaa.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void manage::update(){
}
void manage::saving(){
}
void manage::withdraw(){
}
void manage::transfer(){
}
int main(){
    manage m;
    m.menu();

}



