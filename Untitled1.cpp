#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include <time.h>
#include <string.h>
#include <ctime>
#include<cmath>
#include<sqlite3.h>
#include "sqlite3.h"
using namespace std;
char load=222;
int size = 0;
sqlite3 *db;
sqlite3_stmt *stmt;
int result;
string query,name,email;
class complate{
protected:
    struct node{
        string id;
        string service;
        string stuff;
        string another;
        node *next;
    };
    node *head = NULL;
    node *tail = NULL;
    struct bstNode{
         string customerid;
         string service;
         string stuff;
         string another;
         bstNode *right, *left;

         void setLeft(bstNode *left){
             left = left;
         }
         void setRight(bstNode *right){
             right = right;
         }
         bstNode *getLeft(){
             return left;
         }
         bstNode *getRight(){
             return right;
         }
         string getorderID(){
             return customerid;
         }
         bstNode( string Id,string Service,string Stuff,string Another){
             customerid = Id;
             service = Service;
             stuff = Stuff;
             another = Another;
         }

    };
    bstNode *root;
    bstNode *temp;
public:
    void connection();
    void insertRecord();
    void display();
    void deleteRecord();
    void edite();
    void man();
    void insertData();
    void displayData();
    void customer();
    void add(string Id,string Service,string Stuff,string Another);
    complate(){
        root = NULL;
        temp = NULL;
    }
    void search(){
       string Id;
       bstNode *l = root;
       cout<<"Please enter item id : ";
       fflush(stdin);
       getline(cin,Id);
        while(l != NULL){
            if(Id == l->getorderID()){
                cout<<" ID : "<<l->customerid<<endl
                    <<"Service : "<<l->service<<endl
                    <<"Stuff : "<<l->stuff<<endl
                    <<"Another : "<<l->another<<endl;
                    break;
            }else if(Id < l->getorderID()){
                l = l->getLeft();
            }else if(Id > l->getorderID()){
                l = l->getRight();
            }
        }
    }

};
void complate::add(string Id,string Service,string Stuff,string Another){
        if(root == NULL){
            bstNode *newnode = new bstNode(Id,Service,Stuff,Another);
            root = newnode;
            temp = root;
            return;
        }else{
            while(temp != NULL){
                if(Id < temp->getorderID()){
                    if(temp->getLeft() == NULL){
                        bstNode *newNode = new bstNode(Id,Service,Stuff,Another);
                        temp->setLeft(newNode);
                        temp = root;
                        break;
                    }else{
                        temp = temp->getLeft();
                    }
                }else if(Id > temp->getorderID()){
                    if(temp->getRight() == NULL){
                        bstNode *newNode = new bstNode(Id,Service,Stuff,Another);
                        temp->setRight(newNode);
                        temp = root;
                        break;
                    }
                }else{
                    temp = temp->getRight();
                }
            }
        }
    }
void complate::connection(){
    if(sqlite3_open("complate.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Complate(id VARCHAR(50), service VARCHAR(50), stuff VARCHAR(50),another VARCHAR(50));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void complate::display(){
    string a,b,c,d;
    query = "SELECT rowid, * FROM Complate";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<" ERROR "<<sqlite3_errmsg<<endl;
    }else{
        cout<<"\n--------------------------------------------------------------------------------------------\n";
        cout<< left <<setw(15)<<"\tNo "<<setw(25)<<" ID "<<setw(25)<<" Service "<<setw(25)<<" Stuff "<<setw(10)<<" Anther ";
        cout<<"\n--------------------------------------------------------------------------------------------\n";
        while((result = sqlite3_step(stmt)) == SQLITE_ROW){
            const unsigned char *a = sqlite3_column_text(stmt, 1);
            const unsigned char *b = sqlite3_column_text(stmt, 2);
            const unsigned char *c = sqlite3_column_text(stmt, 3);
            const unsigned char *d = sqlite3_column_text(stmt, 4);
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<<" "
            <<setw(25)<<a<<" "
            <<setw(25)<<b<<" "
            <<setw(15)<<c<<" "
            <<setw(15)<<d<<"\n";

        }
        add(a,b,c,d);
        cout<<"\n--------------------------------------------------------------------------------------------\n";
    }
}
void complate::insertData(){
     string id,service,stuff,another;
     cout<<"\n\n\t\t\t    Please Write Idea  ";
     cout<<"\n\n Enter ID : ";
     cin>>id;
     cout<<"\n\n Complan Service : ";
     fflush(stdin);
     getline(cin,service);
     cout<<"\n\n Complan Stuff ";
     fflush(stdin);
     getline(cin,stuff);
     cout<<"\n\n Complan Another :";
     fflush(stdin);
     getline(cin,another);
     node *new_ptr = new node;
     new_ptr->id = id;
     new_ptr->service = service;
     new_ptr->stuff = stuff;
     new_ptr->another = another;
     new_ptr->next = NULL;
     size++;
     if(head == NULL){
         head = new_ptr;
         tail = new_ptr;
         new_ptr->next = head;
     }else{
         tail->next = new_ptr;
         tail = new_ptr;
         tail->next = head;

     }
    string quary = "INSERT INTO Complate(id, service, stuff, another) VALUES(?,?,?,?);" ;
    result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, id.c_str(), id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, service.c_str(), service.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, stuff.c_str(), stuff.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, another.c_str(), another.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<" Data Successfully \n";
    }
}
void complate::displayData(){
    system("cls");
    cout<<"\n\n\t\t\t Display Record ";
    int c = 0;
    if(head == NULL){
        cout<<"\n\nCircular is empty...";
    }else{
        node *ptr = head;
        while(c != size){
            cout<<"\n\n Value : "<<ptr->id<<" \t"<<ptr->service<<"\t "<<ptr->stuff<<"\t "<<ptr->another;
            ptr = ptr->next;
            c++;
        }

    }
}
void complate::customer(){
     node list_customer;
     ifstream File("complate.txt",ios::in);
     int index = 0;
     if(File.is_open()){
        while(!File.eof()){
            File>>list_customer.id;
            File>>list_customer.service;
            File>>list_customer.stuff;
            File>>list_customer.another;
        }

        cout<<list_customer.id<<" ";
        cout<<list_customer.service<<" ";
        cout<<list_customer.stuff<<" ";
        cout<<list_customer.another<<"\n ";
        add(list_customer.id,list_customer.service,list_customer.stuff,list_customer.another);
        File.close();
     }

}
void complate::man(){
    p:
    connection();
    int choice,n;
    cout<<"\n\n\t\t\t Control Panel";
    cout<<"\n\n 1. Insert Record   ";
    cout<<"\n\n 2. Display Record   ";
    cout<<"\n\n 3. Search  Record   ";
    cout<<"\n\n 4. Quiz Program   ";
    cout<<"\n\n Your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            insertData();
        }break;
        case 2:{
            display();
        }break;
        case 3:{
            customer();
        }break;
        case 4:{
            add("123","kaa","male","female");
        }break;
        case 5:{
            search();
        }break;
        case 6:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid Choice...";
        }
    }
    goto p;
    getch();
}
int main(){
    complate bl;
    bl.man();
    return 0;
}
