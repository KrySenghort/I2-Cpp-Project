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
#include <stdlib.h>
#include <windows.h>
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
        node *right,*left;
    };
    node *head = NULL;
    node *tail = NULL;
    node *root = NULL;
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
    void search_guest();
    void add(string Id,string Service,string Stuff,string Another);
    void search();
};
void complate::add(string Id,string Service,string Stuff,string Another){
    node *new_node = new node();
    new_node->id = Id;
    new_node->service = Service;
    new_node->stuff = Stuff;
    new_node->another = Another;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL){
        root = new_node;
        cout<<" \n\n "<<Id<<setw(15)<<Service<<setw(15)<<Stuff<<setw(15)<<Another<<"  Value Insert Successfully ";
    }
    else{
        node *ptr = root;
        node *pre = NULL;
        while(ptr != NULL){
            if(Id > ptr->id){
                pre = ptr;
                ptr = ptr->right;
                if(ptr == NULL){
                    pre->right = new_node;
                    cout<<" \n\n "<<Id<<setw(15)<<Service<<setw(15)<<Stuff<<setw(15)<<Another<<"  Value Insert Successfully ";
                }
            }else if(Id < ptr->id){
                pre = ptr;
                ptr = ptr->left;
                if(ptr == NULL){
                    pre->left = new_node;
                    cout<<" \n\n "<<Id<<setw(15)<<Service<<setw(15)<<Stuff<<setw(15)<<Another<<"  Value Insert Successfully ";

                }
            }else{
                cout<<" \n\n "<<Id<<setw(15)<<Service<<setw(15)<<Stuff<<setw(15)<<Another<<"  Value Insert Successfully ";
                delete new_node;
                break;
            }
        }
    }
}
void complate::search(){
    system("cls");
    string Id;
    int found=0;
    cout<<"\n\n\t\t\t Search Record ";
    if(root == NULL){
        cout<<"\n\n Tree is Empty...";
    }else{
        cout<<"\n\n\t\t\t Enter Id: ";
        cin>>Id;
        node *ptr = root;
        while(ptr !=NULL){
            if(Id == ptr->id){
                cout<<" \n\n "<<ptr->id<<setw(15)<<ptr->service<<setw(15)<<ptr->stuff<<setw(15)<<ptr->another<<endl;
                found++;
                break;
            }else if(Id > ptr->id){
                ptr = ptr->right;

            }else{
                ptr = ptr->left;
            }
        }
    }
     if(found == 0){
        cout<<" \n\n "<<Id<<"  Data Not Found "<<endl;
     }else{
        cout<<"\n\n "<<Id<<"  Data found.."<<endl;
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
    sqlite3_close(db);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<" Data Successfully \n";
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
void complate::search_guest(){
    sqlite3_open("complate.db",&db);
    string sql1 = "SELECT * FROM Complate;";
    result = sqlite3_prepare_v2(db, sql1.c_str(), -1, &stmt, NULL);
    while ((result=sqlite3_step(stmt)) == SQLITE_ROW){
        int id1 = sqlite3_column_int(stmt,0);
        string id = (const char*) sqlite3_column_text(stmt, 1);
        string service = (const char*) sqlite3_column_text(stmt, 2);
        string stuff = (const char*) sqlite3_column_text(stmt, 3);
        string another = (const char*) sqlite3_column_text(stmt, 4);
        add(id,service,stuff,another);
    }
    if(result != SQLITE_OK){
        cout<<"Error "<<sqlite3_errmsg(db);
        sqlite3_free(stmt);
    }else{
        cout<<" Successfully ..."<<endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    search();
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
void complate::man(){
   /* p:
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
            search();
        }break;
        case 4:{
            search_guest();
        }break;
        case 5:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid Choice...";
        }
    }
    goto p;
    getch();*/
    p:
    /*string id,service,stuff,another;
    cout<<"ID: ";
    fflush(stdin);
    cin>>id;
    cout<<"Service: ";
    fflush(stdin);
    cin>>service;
    cout<<"Stuff: ";
    fflush(stdin);
    cin>>stuff;
    cout<<"Another : ";
    fflush(stdin);
    cin>>another;
    add(id,service,stuff,another);*/
    connection();
    search_guest();
    getch();
    goto p;
}
int main(){
    complate bl;
    bl.man();
    return 0;
}
