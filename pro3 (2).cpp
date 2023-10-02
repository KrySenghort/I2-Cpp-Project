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
sqlite3 *db;
sqlite3_stmt *stmt;
int result,result1;
string query,query1;
char load = 220;
class link{
protected:
    struct node{
        int pin;
        double balance;
        double balanceriel;
        string id,pass,name,fname,address,phone;
        node *next_add;
    };
    node *head = NULL;
public:
    void menu1();
    void connection1();
    void insertInformation();
    void insertToLink(int pin,string id,string pass,string name,string father,string address,string phone,double balance,double balancereil);
    void login();
    void searchInformation();
    void show_record();
    void setting();
    void saving();
    void withdraw();
    void transfer();
    void payment();
    void connection2();
    void sortList();
};
void link::connection1(){
    if(sqlite3_open("oppa.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS apple(pin INT,id VARCHAR(50),pass VARCHAR(50), name VARCHAR(50), father VARCHAR(50), address VARCHAR(50),phone VARCHAR(50),balance DOUBLE , balancereil DOUBLE );", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void link::connection2(){
    if(sqlite3_open("oppi.db",&db) == SQLITE_OK){
        result1 = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS banana(id VARCHAR(50),name VARCHAR(50),service VARCHAR(200),day INT,month INT,year INT,money DOUBLE,reil DOUBLE);", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result1 != SQLITE_OK){
            cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
        }
    }
}
void link::insertInformation(){
    int pin;
    string id,pass,name,father,address,phone;
    double balance,balancereil;
    cout<<"\n\n Input PIN : ";    cin>>pin;
    cout<<"\n\n Input ID : ";          fflush(stdin);    getline(cin,id);
    cout<<"\n\n Input PASSWORD : ";    fflush(stdin);    getline(cin,pass);
    cout<<"\n\n Input NAME : ";        fflush(stdin);    getline(cin,name);
    cout<<"\n\n Input FATHER NAME : "; fflush(stdin);    getline(cin,father);
    cout<<"\n\n Input ADDRESS : ";     fflush(stdin);    getline(cin,address);
    cout<<"\n\n Input PHONE NUMBER : ";fflush(stdin);    getline(cin,phone);
    cout<<"\n\n Input BALANCE DOLA : ";cin>>balance;
    cout<<"\n\n Input BALANCE REIL : ";cin>>balancereil;
    string quary = "INSERT INTO apple(pin, id, pass, name, father, address, phone, balance, balancereil ) VALUES(?,?,?,?,?,?,?,?,?);" ;
    result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, pin);
    sqlite3_bind_text(stmt, 2, id.c_str(), id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pass.c_str(), pass.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, father.c_str(), father.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, address.c_str(), address.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, phone.c_str(), phone.length(), SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 8, balance);
    sqlite3_bind_double(stmt, 9, balancereil);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }
    else{
        cout<<" Data Successfully \n";
    }
}
void link::login(){
    sqlite3_open("oppa.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        int pin = (sqlite3_column_int(stmt,0));
        string id = (const char *) (sqlite3_column_text(stmt,1));
        string pass = (const char*) (sqlite3_column_text(stmt,2));
        string name = (const char* ) (sqlite3_column_text(stmt,3));
        string father = (const char* ) (sqlite3_column_text(stmt,4));
        string address = (const char* ) (sqlite3_column_text(stmt,5));
        string phone = (const char* ) (sqlite3_column_text(stmt,6));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        insertToLink(pin,id,pass,name,father,address,phone,balance,balancereil);

    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
void link::insertToLink(int pin,string id,string pass,string name,string father,string address,string phone,double balance,double balancereil){
    node *new_node = new node;
    new_node->pin = pin;
    new_node->id = id;
    new_node->pass = pass;
    new_node->name = name;
    new_node->fname = father;
    new_node->address = address;
    new_node->phone = phone;
    new_node->balance = balance;
    new_node->balanceriel = balancereil;
    new_node->next_add = NULL;
    if(head == NULL){
        head = new_node;
    }else{
        node *ptr = head;
        while(ptr->next_add != NULL){
            ptr = ptr->next_add;
        }
        ptr->next_add = new_node;
    }
}
void link::searchInformation(){
    system("cls");
    SYSTEMTIME x;
    string e_id;
    int found = 0;
    cout<<"===================================\n";
    cout<<"  2. Search  Record      "<<endl;
    cout<<"===================================\n";
    if(head == NULL){
        cout<<" No Record .... \n";
    }else{
        cout<<"\n\n User ID: ";
        cin>>e_id;
        node *ptr = head;
        while( ptr != NULL){
            if(ptr->id == e_id){
                 system("cls");
                 GetSystemTime(&x);
                 system("color 0B");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
                 cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
                 cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
                 cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
                 cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 found++;
            }
            ptr = ptr->next_add;
        }
        if(found == 0){
            cout<<"\n Search not Found...."<<endl;
        }
    }
}
void link::show_record(){
    system("cls");
    SYSTEMTIME x;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  5. Show ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
         cout<<"\n\n\t\t\t No Record...";
    }else{
        node *ptr = head;
        while(ptr != NULL){
            GetSystemTime(&x);
            system("color 0B");
            cout<<"\n\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
            cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
            cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
            cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
            cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
            cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
            cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
            cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
            cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
            cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            ptr = ptr->next_add;
        }
    }
}
void link::setting(){
    string pass;
    int pin,id;
    string again;
    p:
    cout<<"\n\n Input ID :";
    cin>>id;
    cout<<"\n\n Input PIN : ";
    cin>>pin;
    cout<<"\n\n Input PASSWORD : ";
    fflush(stdin);
    getline(cin,pass);

    cout<<"\n DO YOU WANT TO UPDATE INFORMATION ?(YES/NO) : ";
    fflush(stdin);
    cin>>again;
    if(again == "YES" || again == "yes"){
        query = "UPDATE apple SET pin = ?, pass = ? WHERE rowid = ?;";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_bind_int(stmt, 1, pin);
        sqlite3_bind_text(stmt, 2, pass.c_str(), pass.length(), SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 3, id);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
            cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<"Successfully "<<endl;
        }
    }else if(again == "NO" || again == "no"){
       menu1();
    }else{
        goto p;
    }

}
void link::saving(){
    string searchid;
    int id;
    double savingDOLA,savingReil;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;

    sqlite3_open("oppa.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        if(searchid == Id){
            cout<<"\n\n Input Number of ID :";
            cin>>id;

            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>savingDOLA;

            cout<<"\n\n Currant REIL BALANCE : ";
            cin>>savingReil;

            cout<<"\n DO YOU WANT TO SAVING MONEY ?(YES/NO) : ";
            fflush(stdin);
            cin>>again;
            if(again =="YES" || again == "�es"){
                 balance += savingDOLA;
                 balancereil += savingReil;
                 query = "UPDATE apple SET balance = ?, balancereil = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt, 2, balancereil);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu1();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
void link::withdraw(){
    string searchid;
    int id;
    double withdarwDOLA,withdrawReil;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;
    sqlite3_open("oppa.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        if(searchid == Id){
            cout<<"\n\n Input Number of ID :";
            cin>>id;
            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>withdarwDOLA;
            cout<<"\n\n Currant REIL BALANCE : ";
            cin>>withdrawReil;
            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 balance -= withdarwDOLA;
                 balancereil -= withdrawReil;
                 query = "UPDATE apple SET balance = ?, balancereil = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt, 2, balancereil);
                 sqlite3_bind_int(stmt, 3, id);
                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else
                 {
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu1();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
void link::transfer(){
    string searchid,searchid1;
    int id,found = 0;
    double withdarwDOLA,withdrawReil;
    string again;
    p:
    cout<<"\n\n Enter ID FOR TRANSFER MONEY :";
    fflush(stdin);
    cin>>searchid;

    cout<<"\n\n Enter ID FOR EXCEPT MONEY :";
    fflush(stdin);
    cin>>searchid1;

     cout<<"\n\n Currant DOLA BALANCE : ";
    cin>>withdarwDOLA;

    cout<<"\n\n Currant REIL BALANCE : ";
    cin>>withdrawReil;

    sqlite3_open("oppa.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        if(searchid == Id){
            cout<<"\n\n Input Number of ID : ";
            cin>>id;
            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 balance -= withdarwDOLA;
                 balancereil -= withdrawReil;
                 query = "UPDATE apple SET balance = ?, balancereil = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt, 2, balancereil);
                 sqlite3_bind_int(stmt, 3, id);
                 found++;
                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }
                 else{
                     cout<<"Successfully "<<endl;
                 }

            }else if(again == "NO" || again == "no"){
                menu1();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }
    }
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        if(searchid1 == Id){
            cout<<"\n\n Input Number of ID for Except Money : ";
            cin>>id;
            cout<<"\n DO YOU WANT TO SAVING MONEY ?(YES/NO) : ";
            fflush(stdin);
            cin>>again;
            if(again =="YES" || again == "�es"){
                 balance += withdarwDOLA;
                 balancereil += withdrawReil;
                 query = "UPDATE apple SET balance = ?, balancereil = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt, 2, balancereil);
                 sqlite3_bind_int(stmt, 3, id);
                 found++;
                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu1();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }
    }
    if(found == 2){
        cout<<"\n\n TRANSFER SUCCESSFULLY  "<<endl;
    }else{
        cout<<"\n\n TRANSFER NOTE SUCCESSFULLY  "<<endl;
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}
void link::payment(){
    string searchid;
    int id;
    double withdarwDOLA,withdrawReil;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;

    sqlite3_open("oppa.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double balancereil = (sqlite3_column_double(stmt,8));
        if(searchid == Id){
            cout<<"\n\n Input Number of ID :";
            cin>>id;

            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>withdarwDOLA;

            cout<<"\n\n Currant REIL BALANCE : ";
            cin>>withdrawReil;
            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 balance -= withdarwDOLA;
                 balancereil -= withdrawReil;
                 query = "UPDATE apple SET balance = ?, balancereil = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt, 2, balancereil);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu1();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }

    }

    string iid,name,service;
    int day,month,year;
    double money,reil;
    SYSTEMTIME x;
    iid = searchid;

    cout<<"\n\n Enter NAME : ";
    fflush(stdin);
    getline(cin,name);

    cout<<"\n\n Enter SERVICE : ";
    fflush(stdin);
    getline(cin,service);

    money = withdarwDOLA;
    reil = withdrawReil;
    GetSystemTime(&x);
    day = x.wDay;
    month = x.wMonth;
    year = x.wYear;

    cout<<" "<<iid<<" "<<money<<" "<<day<<endl;

    string quary1 = "INSERT INTO banana(id, name, service, day, month, year, money, reil) VALUES(?,?,?,?,?,?,?,?);" ;
    result1 = sqlite3_prepare_v2(db, quary1.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, iid.c_str(), iid.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, service.c_str(), service.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, day);
    sqlite3_bind_int(stmt, 5, month);
    sqlite3_bind_int(stmt, 6, year);
    sqlite3_bind_double(stmt, 7, money);
    sqlite3_bind_double(stmt, 8, reil);

    if(result1 != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }
    else{
        cout<<" Data Successfully \n";
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}
void link::sortList(){
    node *ptr1,*ptr2;
    ptr2 = NULL;
    int swap;
    do{
            ptr1 = head;
            swap = 0;
            while(ptr1->next_add != ptr2){
                if(ptr1->pin > ptr1->next_add->pin){
                    int temp;
                    temp = ptr1->pin;
                    ptr1->pin = ptr1->next_add->pin;
                    ptr1->next_add->pin = temp;
                }
                ptr1 = ptr1->next_add;
            }
            ptr2 = ptr1;

    }while(swap);

}
void link::menu1(){
    connection1();
    int choice;
    p:
    cout<<"\n\n\t\t\t       MENU        "<<endl;
    cout<<"\n\n 1 . Insert Information  "<<endl;
    cout<<"\n\n 2 . Search Information  "<<endl;
    cout<<"\n\n 3 . Setting Information "<<endl;
    cout<<"\n\n 4 . Saving Money        "<<endl;
    cout<<"\n\n 5 . Withdraw Money      "<<endl;
    cout<<"\n\n 6.  Transfer Money      "<<endl;
    cout<<"\n\n 7.  Show Record         "<<endl;
    cout<<"\n\n 8.  Payment Service     "<<endl;
    cout<<"\n\n Select Your Option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            insertInformation();
        }break;
        case 2:{
            login();
            searchInformation();
        }break;
        case 3:{
            setting();
        }break;
        case 4:{
            saving();
        }break;
        case 5:{
            withdraw();
        }break;
        case 6:{
            transfer();
        }break;
        case 7:{
            login();
            sortList();
            show_record();
        }break;
        case 8:{
            connection2();
            payment();
        }break;
        case 9:{
            exit(0);
        }break;
        default :{
            cout<<"\n\n\t\t\t Invalid Choice ...."<<endl;
        }
    }
    goto p;
    getch();
}
int main(){
    link l;
    l.menu1();
}












