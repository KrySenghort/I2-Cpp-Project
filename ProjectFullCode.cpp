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
int i=0;
int m = -1;
int Size = 0;
sqlite3 *db;
sqlite3_stmt *stmt;
int result,result1;
string query,query1;
char load = 220;
struct Student{
public:
    int pin;
    double balance;
    double balanceriel;
    string id,pass,name,fname,address,phone;
};
class MyHashTable{

    Student **arr;
    int size;
    int count;
public:

    MyHashTable(){
        count = 0;
        size = 5;
        arr = new Student*[size];

        for (int i = 0; i<size; i++)
            arr[i] = nullptr;
    }

    int hashIt(int pin){
        return pin%size;
    }

    void insertItem(int pin, string id, string pass, string name, string fname, string address, string phone, double balance, double balancereil){
        if (count == size){
            cout<<"Hash is full\n";
            return;

        }
        int hashIndex = hashIt(pin);
        while (arr[hashIndex] != nullptr){
            hashIndex = (hashIndex + 1)%size;
        }
        arr[hashIndex] = new Student();
        arr[hashIndex]->pin = pin;//access member(rollNo) to class student
        arr[hashIndex]->id = id;
        arr[hashIndex]->pass = pass;
        arr[hashIndex]->name = name;
        arr[hashIndex]->fname = fname;
        arr[hashIndex]->address = address;
        arr[hashIndex]->phone = phone;
        arr[hashIndex]->balance = balance;
        arr[hashIndex]->balanceriel = balancereil;
        count++;
    }

    void getItem(int key){
        SYSTEMTIME x;
        if (count == 0){
            cout<<"Empty"<<endl;
        }
        int hashIndex = hashIt(key);
        int temp = hashIndex;
        while(true){
            if (arr[hashIndex] == nullptr)
                hashIndex = (hashIndex+1)%size;
            else if (arr[hashIndex]->pin != key)
                hashIndex = (hashIndex+1)%size;
            else
                break;

            if (hashIndex == temp){
                temp = -1;
                break;
            }
        }

        if (temp == -1){
            cout<<"Not found..."<<endl;
        }else{
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
            cout<<"\t\t\t\t\t"<<"    ID : "<< arr[hashIndex]->id <<endl;
            cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< arr[hashIndex]->pass <<endl;
            cout<<"\t\t\t\t\t"<<"    PIN : "<< arr[hashIndex]->pin <<endl;
            cout<<"\t\t\t\t\t"<<"    NAME : "<< arr[hashIndex]->name <<endl;
            cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< arr[hashIndex]->fname <<endl;
            cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< arr[hashIndex]->address <<endl;
            cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< arr[hashIndex]->phone <<endl;
            cout<<"\t\t\t\t\t"<<"    BALANCE : "<< arr[hashIndex]->balance <<endl;
            cout<<"\t\t\t\t\t"<<"REIL BALANCE : "<< arr[hashIndex]->balanceriel <<endl;
            cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
        }
    }
    void deleteItem(int key){
        int hashIndex;
        int temp = hashIndex;
        while (true){
            if (arr[hashIndex] == nullptr)
                hashIndex = (hashIndex+1)%size;
            else if (arr[hashIndex]->pin != key)
                hashIndex = (hashIndex+1)%size;
            else
                break;
            if (hashIndex == temp){
                temp = -1;
                break;
            }
        }
        if (temp == -1)
            cout<<"Notfound";
        else{
            delete arr[hashIndex];
            arr[hashIndex] = nullptr;
        }
    }

    void displayAll(){
        for (int i=0; i<size; i++){
            if (arr[i] != nullptr)
                cout<<"HASH_TABLE["<<i<<"]: key=> "<<" Value => "<<arr[i]->pin<<"\t"<<arr[i]->id<<"\t"<<arr[i]->pass<<"\t"<<arr[i]->name<<"\t"<<arr[i]->fname<<"\t"<<arr[i]->address<<"\t"<<arr[i]->phone<<"\t"<<arr[i]->balance<<"\t"<<arr[i]->balanceriel<<endl;
        }
    }
};
class link:public MyHashTable{
protected:
    struct node{
        int pin;
        double balance;
        double balanceriel;
        string id,pass,name,fname,address,phone;
        double eletricity,wather,buying,taxes,hopital,another;
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
    void sortList();
};
void link::connection1(){
    if(sqlite3_open("yanut.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS apple(pin INT,id VARCHAR(50),pass VARCHAR(50), name VARCHAR(50), father VARCHAR(50), address VARCHAR(50),phone VARCHAR(50),balance DOUBLE , balancereil DOUBLE, eletricity DOUBLE,wather DOUBLE,taxes DOUBLE,hopital DOUBLE,buying DOUBLE,another DOUBLE );", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void link::insertInformation(){
    int pin;
    string id,pass,name,father,address,phone;
    double balance,balancereil;
    double eletricity,wather,buying,taxes,hopital,another;
    eletricity = 0;
    wather = 0;
    buying = 0;
    taxes = 0;
    hopital = 0;
    another = 0;
    cout<<"\n\n Input PIN : ";
    cin>>pin;
    cout<<"\n\n Input ID : ";
    fflush(stdin);
    getline(cin,id);

    cout<<"\n\n Input PASSWORD : ";
    fflush(stdin);
    getline(cin,pass);

    cout<<"\n\n Input NAME : ";
    fflush(stdin);
    getline(cin,name);

    cout<<"\n\n Input FATHER NAME : ";
    fflush(stdin);
    getline(cin,father);

    cout<<"\n\n Input ADDRESS : ";
    fflush(stdin);
    getline(cin,address);

    cout<<"\n\n Input PHONE NUMBER : ";
    fflush(stdin);
    getline(cin,phone);

    cout<<"\n\n Input BALANCE DOLA : ";
    cin>>balance;

    cout<<"\n\n Input BALANCE REIL : ";
    cin>>balancereil;

    string quary = "INSERT INTO apple(pin, id, pass, name, father, address, phone, balance, balancereil, eletricity, wather, taxes, hopital, buying, another ) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);" ;
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
    sqlite3_bind_double(stmt, 10, eletricity);
    sqlite3_bind_double(stmt, 11, wather);
    sqlite3_bind_double(stmt, 12, taxes);
    sqlite3_bind_double(stmt, 13, hopital);
    sqlite3_bind_double(stmt, 14, buying);
    sqlite3_bind_double(stmt, 15, another);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<" Data Successfully \n";
    }
}
void link::login(){
    sqlite3_open("yanut.db",&db);
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
        MyHashTable::insertItem(pin,id,pass,name,father,address,phone,balance,balancereil);

    }
    sqlite3_finalize(stmt);
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
                 cout<<"\t\t\t\t\t"<<"REIL BALANCE : "<< ptr->balanceriel <<endl;
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
            cout<<"\t\t\t\t\t"<<"REIL BALANCE : "<< ptr->balanceriel <<endl;
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
    cout<<"\n\n Input Number of ID :";
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

    sqlite3_open("yanut.db",&db);
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
            if(again =="YES" || again == "ýes"){
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
}
void link::withdraw(){
    string searchid;
    int id;
    double withdarwDOLA,withdrawReil;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;

    sqlite3_open("yanut.db",&db);
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
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
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

    sqlite3_open("yanut.db",&db);
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
            if(again =="YES" || again == "ýes"){
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

}
void link::payment(){
    string searchid;
    int id;
    double withdarwDOLA;
    string again;
    int option;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;
    sqlite3_open("yanut.db",&db);
    query = "SELECT * FROM apple";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,7));
        double eletricity  = (sqlite3_column_double(stmt,9));
        double wather      = (sqlite3_column_double(stmt, 10));
        double taxes       =  (sqlite3_column_double(stmt, 11));
        double hopital     =  (sqlite3_column_double(stmt, 12));
        double buying     =  (sqlite3_column_double(stmt, 13));
        double another    =   (sqlite3_column_double(stmt, 14));
        if(searchid == Id){
            cout<<"\n\n Input Number of ID :";
            cin>>id;

            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>withdarwDOLA;

            cout<<"\n\n [1]. Eletricity ";
            cout<<"\n\n [2]. Wather     ";
            cout<<"\n\n [3]. Taxes      ";
            cout<<"\n\n [4]. Hopital     ";
            cout<<"\n\n [5]. Buying     ";
            cout<<"\n\n [6]. Another     ";
            cout<<" \n\n Select Option : ";
            cin>>option;

            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 if(option == 1){
                    balance -= withdarwDOLA;
                    eletricity += withdarwDOLA;
                    wather += 0;
                    taxes += 0;
                    hopital +=0;
                    buying += 0;
                    another +=0;
                 }else if(option == 2){
                    balance -= withdarwDOLA;
                    eletricity += 0;
                    wather += withdarwDOLA;
                    taxes += 0;
                    hopital +=0;
                    buying += 0;
                    another +=0;
                 }else if(option == 3){
                    balance -= withdarwDOLA;
                    eletricity += 0;
                    wather += 0;
                    taxes += withdarwDOLA;
                    hopital +=0;
                    buying += 0;
                    another +=0;
                 }else if(option == 4){
                    balance -= withdarwDOLA;
                    eletricity += 0;
                    wather += 0;
                    taxes += 0;
                    hopital += withdarwDOLA;
                    buying += 0;
                    another +=0;
                 }else if(option == 5){
                    balance -= withdarwDOLA;
                    eletricity += 0;
                    wather += 0;
                    taxes += 0;
                    hopital +=0;
                    buying += withdarwDOLA;
                    another +=0;
                 }else if(option == 6){
                    balance -= withdarwDOLA;
                    eletricity += 0;
                    wather += 0;
                    taxes += 0;
                    hopital +=0;
                    buying += 0;
                    another += withdarwDOLA;
                 }else{
                     cout<<"\n\n Invalid ..."<<endl;
                 }
                 query = "UPDATE apple SET balance = ? ,eletricity = ?,wather = ?,taxes = ?,hopital = ?,buying = ?,another = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_double(stmt,2,eletricity);
                 sqlite3_bind_double(stmt,3,wather);
                 sqlite3_bind_double(stmt,4,taxes);
                 sqlite3_bind_double(stmt,5,hopital);
                 sqlite3_bind_double(stmt,6,buying);
                 sqlite3_bind_double(stmt,7,another);
                 sqlite3_bind_int(stmt, 8, id);

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
                    int pin1;
                    double balance1;
                    double balanceriel1;
                    string id1,pass1,name1,fname1,address1,phone1;
                    double eletricity1,wather1,buying1,taxes1,hopital1,another1;

                    pin1 = ptr1->pin;
                    ptr1->pin = ptr1->next_add->pin;
                    ptr1->next_add->pin = pin1;

                    balance1 = ptr1->balance;
                    ptr1->balance = ptr1->next_add->balance;
                    ptr1->next_add->balance = balance1;

                    balanceriel1 = ptr1->balanceriel;
                    ptr1->balanceriel = ptr1->next_add->balanceriel;
                    ptr1->next_add->balanceriel = ptr1->balanceriel;

                    id1 = ptr1->id;
                    ptr1->id = ptr1->next_add->id;
                    ptr1->next_add->id = id1;

                    pass1 = ptr1->pass;
                    ptr1->pass = ptr1->next_add->pass;
                    ptr1->next_add->pass = pass1;

                    name1 = ptr1->name;
                    ptr1->name = ptr1->next_add->name;
                    ptr1->next_add->name = name1;

                    fname1 = ptr1->fname;
                    ptr1->fname = ptr1->next_add->name;
                    ptr1->next_add->name = fname1;

                    address1 = ptr1->address;
                    ptr1->address = ptr1->next_add->address;
                    ptr1->next_add->address = address1;

                    phone1 = ptr1->phone;
                    ptr1->phone = ptr1->next_add->phone;
                    ptr1->next_add->phone = phone1;
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
            int pinn;
            cout<<"\n\n Enter Your pin :";
            cin>>pinn;
            login();
            MyHashTable::getItem(pinn);
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
class pay:public link{
protected:
    struct node{
        int pin;
        double balance;
        double payment,credit;
        string id,pass,name,fname,mname,suportname,address,phone;
        string job,plan_load;
        int n;
        node *pre,*next;
    };
    node *head = NULL;
    node *tail = NULL;
public:
    void menu2();
    void load_data1();
    void information();
    void insertInformation(int pin1,string id1,string pass1,string name1,string fname1,string mname1,string suportname1,string address1,string phone1,string job1,string plan_load1,double balance1,double payment1,double credit,int n1);
    void load_in();
    void show_Record();
    void search();
    void payment();
    void deleteInformation();

};
void pay::menu2(){
    load_data1();
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t Load Bank Management System    ";
    cout<<"\n\n\t\t\t 1. Information customer Load ";
    cout<<"\n\n\t\t\t 2. Show Record all customer ";
    cout<<"\n\n\t\t\t 3. Search Record all customer ";
    cout<<"\n\n\t\t\t 4. Update Record all customer ";
    cout<<"\n\n\t\t\t 5. Payment Back ";
    cout<<"\n\n\t\t\t 6. Show All Day To Payment ";
    cout<<"\n\n--------------------------------\n";
    cout<<"\n\n Please Select option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            information();
        }break;
        case 2:{
            show_Record();
        }break;
        case 3:{
            load_in();
            search();
        }break;
        case 4:{
            payment();
        }break;
        case 5:{
            deleteInformation();
        }break;
        case 6:{
        }break;
        case 7:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n\t\t\t Invalid choice ...";
        }
    }
    getch();
    goto p;

}
void pay::load_data1(){
     if(sqlite3_open("itc.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS banana(pin INT,id VARCHAR(50),pass VARCHAR(50), name VARCHAR(50), father VARCHAR(50), mother VARCHAR(50),support VARCHAR(50),address VARCHAR(50) , phone VARCHAR(50), job VARCHAR(50),plan VARCHAR(50) ,balance DOUBLE,payment DOUBLE,credit DOUBLE,time INT );", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        ;
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void pay::information(){
    int pin;
    string id,pass,name,father,mother,address,phone,job,plan;
    double balance,balance1,payment,credit;
    string support;
    int year,time;
    float rate;
    cout<<"\n\n Input PIN : ";
    cin>>pin;

    cout<<"\n\n Input ID : ";
    fflush(stdin);
    getline(cin,id);

    cout<<"\n\n Input PASSWORD : ";
    fflush(stdin);
    getline(cin,pass);

    cout<<"\n\n Input NAME : ";
    fflush(stdin);
    getline(cin,name);

    cout<<"\n\n Input FATHER NAME : ";
    fflush(stdin);
    getline(cin,father);

    cout<<"\n\n Input Mother Name : ";
    fflush(stdin);
    getline(cin,mother);

    cout<<"\n\n Input Support Name : ";
    fflush(stdin);
    getline(cin,support);

    cout<<"\n\n Input ADDRESS : ";
    fflush(stdin);
    getline(cin,address);

    cout<<"\n\n Input PHONE NUMBER : ";
    fflush(stdin);
    getline(cin,phone);

    cout<<"\n\n Input JOB : ";
    fflush(stdin);
    getline(cin,job);

    cout<<"\n\n Input PLAN : ";
    fflush(stdin);
    getline(cin,plan);

    cout<<"\n\n Input BALANCE DOLA : ";
    cin>>balance1;

    cout<<"\n\n Number of year payback :";
    cin>>year;

    if(balance1 >0 && balance1 <=10000){
        rate = 8;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else if(balance1 >10000 && balance1 <=50000){
        rate = 7;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else if(balance1 >50000 && balance1 <=100000){
        rate = 6;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else{
        rate = 5;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }
    credit = balance - balance1;
    time = year *12;

    string quary = "INSERT INTO banana(pin, id, pass, name, father, mother, support,address, phone, job, plan, balance, payment, credit, time) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);" ;
    result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, pin);
    sqlite3_bind_text(stmt, 2, id.c_str(), id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pass.c_str(), pass.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, father.c_str(), father.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, mother.c_str(), mother.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, support.c_str(), support.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, address.c_str(), address.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 9, phone.c_str(), phone.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 10, job.c_str(), job.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 11, plan.c_str(), plan.length(), SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 12, balance);
    sqlite3_bind_double(stmt, 13, payment);
    sqlite3_bind_double(stmt, 14, credit);
    sqlite3_bind_int(stmt, 15, time);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<" Data Successfully \n";
    }
}
void pay::load_in(){
    result = sqlite3_open("itc.db",&db);
    query = "SELECT * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        int pin = (sqlite3_column_int(stmt,0));
        string id = (const char *) (sqlite3_column_text(stmt,1));
        string pass = (const char*) (sqlite3_column_text(stmt,2));
        string name = (const char* ) (sqlite3_column_text(stmt,3));
        string father = (const char* ) (sqlite3_column_text(stmt,4));
        string mother = (const char* ) (sqlite3_column_text(stmt,5));
        string support = (const char* ) (sqlite3_column_text(stmt,6));
        string address = (const char* ) (sqlite3_column_text(stmt,7));
        string phone = (const char* ) (sqlite3_column_text(stmt,8));
        string job = (const char* ) (sqlite3_column_text(stmt,9));
        string plan = (const char* ) (sqlite3_column_text(stmt,10));
        double balance = (sqlite3_column_double(stmt,11));
        double payment = (sqlite3_column_double(stmt,12));
        double credit = (sqlite3_column_double(stmt,13));
        double time = (sqlite3_column_double(stmt,14));
        insertInformation(pin,id,pass,name,father,mother,support,address,phone,job,plan,balance,payment,credit,time);

    }
    sqlite3_finalize(stmt);
}
void pay::insertInformation(int pin1,string id1,string pass1,string name1,string fname1,string mname1,string suportname1,string address1,string phone1,string job1,string plan_load1,double balance1,double payment1,double credit,int n1){
    node *new_node = new node;
    new_node->id = id1;
    new_node->pass = pass1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->mname = mname1;
    new_node->suportname = suportname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->job = job1;
    new_node->plan_load = plan_load1;
    new_node->phone = phone1;
    new_node->balance = balance1;
    new_node->payment = payment1;
    new_node->credit = credit ;
    new_node->n = n1;
    new_node->pre = NULL;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        new_node -> pre = tail;
        tail = new_node;
    }
}
void pay::show_Record(){
    system("cls");
    SYSTEMTIME x;
    sqlite3_open("itc.db",&db);
    query = "SELECT rowid, * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<" ERROR "<<sqlite3_errmsg<<endl;
    }else{
        while((result = sqlite3_step(stmt)) == SQLITE_ROW){
                system("color 0A");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	             cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 system(" color 0A");
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	             cout<<"\t\t\t\t\t";
	             for(int j=0;j<=31;j++)
	             cout<<load;
	             cout<<"\n";
	             cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	             cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<"    POSITION : "<< sqlite3_column_text(stmt, 0) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PIN : "<< sqlite3_column_text(stmt, 1) <<endl;
                 cout<<"\t\t\t\t\t"<<"    ID : "<< sqlite3_column_text(stmt, 2) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< sqlite3_column_text(stmt, 3) <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME : "<< sqlite3_column_text(stmt, 4) <<endl;
                 cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< sqlite3_column_text(stmt, 5) <<endl;
                 cout<<"\t\t\t\t\t"<<"    MOTHER NAME : "<< sqlite3_column_text(stmt, 6) <<endl;
                 cout<<"\t\t\t\t\t"<<"    SUPORT NAME : "<< sqlite3_column_text(stmt, 7) <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< sqlite3_column_text(stmt, 8) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE : "<< sqlite3_column_text(stmt, 9) <<endl;
                 cout<<"\t\t\t\t\t"<<"    JOB : "<< sqlite3_column_text(stmt, 10) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PLAN : "<< sqlite3_column_text(stmt, 11)<<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< sqlite3_column_text(stmt, 12) <<endl;
                 cout<<"\t\t\t\t\t"<<"    CREDIT : "<< sqlite3_column_text(stmt, 14) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< sqlite3_column_text(stmt, 13) <<endl;
                 cout<<"\t\t\t\t\t"<<"    NUMBER PAYBACK : "<< sqlite3_column_text(stmt, 15) <<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	             cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
	             cout<<load;
	             cout<<"\n";
        }
        if(result != SQLITE_OK){
            cout<<" Error : "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<"\n\n Search Successfully ... "<<endl;
        }
        cout<<"\n--------------------------------------------------------------------------------------------\n";
    }
}
void pay::search(){
    system("cls");
    string  emp_id;
    int count=0;
    SYSTEMTIME x;
    cout<<"\n\n\t\t\t\t Search Record";
    if(head == NULL){
        cout<<"\n\n Linked List is Empty...";
    }else{

        cout<<"\n\n Enter ID to search  : ";
        cin>>emp_id;
        node *ptr = head;
        while(ptr != NULL){
            if(emp_id == ptr ->id){
                 GetSystemTime(&x);
                 system("color 0A");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	             cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 system(" color 0A");
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
                 cout<<"\t\t\t\t\t"<<"    MOTHER NAME : "<< ptr->mname <<endl;
                 cout<<"\t\t\t\t\t"<<"    SUPORT NAME : "<< ptr->suportname <<endl;
                 cout<<"\t\t\t\t\t"<<"    JOB : "<< ptr->job <<endl;
                 cout<<"\t\t\t\t\t"<<"    PLAN : "<< ptr->plan_load <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
                 cout<<"\t\t\t\t\t"<<"    CREDIT : "<< ptr->credit <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->payment <<endl;
                 cout<<"\t\t\t\t\t"<<"    NUMBER PAYBACK : "<< ptr->n <<endl;
                 cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	             cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
	             cout<<load;
	             cout<<"\n";
                 count++;
                 break;
            }
            ptr = ptr -> next;
        }
        if(count == 0)
        cout<<"\n\n ID : "<<emp_id<<" Can't Found...";
    }

}
void pay::payment(){
    string searchid;
    int id;
    const int timhe = 1 ;
    double withdarwDOLA;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;

    result = sqlite3_open("itc.db",&db);
    query = "SELECT * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,11));
        double payment = (sqlite3_column_double(stmt,12));
        int time = (sqlite3_column_int(stmt,14));
        if(searchid == Id){
            cout<<"\n\n Input Position of ID :";
            cin>>id;

            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>withdarwDOLA;

            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 if(withdarwDOLA >= payment){
                    balance -= withdarwDOLA;
                    time -= timhe;
                 }else{
                     cout<<"\n\n Payment is not Successfully "<<endl;
                     exit(0);
                 }
                 query = "UPDATE banana SET balance = ?, time = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_int(stmt, 2, time);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu2();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }

    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void pay::deleteInformation(){
    int id;
    string again;
    SYSTEMTIME x;
    p:
    cout<<"\n Enter the [POSITION] of ID : ";
    cin>>id;
    getchar();
    GetSystemTime(&x);
    system("color 0B");
    cout<<"\n\t\t\t\t\t";
    for(int j=0;j<=36;j++)
    cout<<load;
    cout<<"\n";
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"  DO YOU WANT TO DELETE THAT [ID]  "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"           (YES/NO)                "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=36;j++)
    cout<<load;
    cout<<"\n";
    cin>>again;
    if( again == "YES"){
        result = sqlite3_open("itc.db",&db);
        query = "DELETE FROM banana WHERE rowid = ?";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_bind_int(stmt, 1,id);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result == SQLITE_OK){
            cout<<" Delete Successfully ....\n";
        }else{
            cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
        }
        cout<<"\t\t\t\t"<<load<<" Time : "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
    }else if(again == "NO"){
        cout<<"\n\n I DON'T WANT .....\n";
    }else{
        goto p;
    }
}
class complate:public pay{
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
    void addToTree(string Id,string Service,string Stuff,string Another);
    void search();
};
void complate::addToTree(string Id,string Service,string Stuff,string Another){
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
    }else{
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
            }
            else{
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
        cout<<"\n\t||--------------------------------------------------------------------------------------------||"<<endl;
        cout<< left <<"\t\t"<<setw(15)<<" ID "<<setw(25)<<" Service "<<setw(25)<<" Stuff "<<setw(10)<<" Anther ";
        cout<<"\n\t||--------------------------------------------------------------------------------------------||"<<endl;
        node *ptr = root;
        while(ptr !=NULL){
            if(Id == ptr->id){
                cout<<"\t\t "<<setw(15)<<ptr->id<<setw(25)<<ptr->service<<setw(25)<<ptr->stuff<<setw(25)<<ptr->another<<endl;
                cout<<"\n\t||--------------------------------------------------------------------------------------------||\n";
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
     Size++;
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
    }
    else{
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
        cout<<"\n\t--------------------------------------------------------------------------------------------\n";
        cout<< left <<setw(15)<<"\tNo "<<setw(25)<<" ID "<<setw(25)<<" Service "<<setw(15)<<" Stuff "<<setw(15)<<" Anther ";
        cout<<"\n\t--------------------------------------------------------------------------------------------\n";
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
        cout<<"\n\t--------------------------------------------------------------------------------------------\n";
    }
}
void complate::search_guest(){
    sqlite3_open("complate.db",&db);
    query = "SELECT * FROM Complate";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        //int id = sqlite3_column_int(stmt,0);
        string id = (const char *) (sqlite3_column_text(stmt,0));
        string service = (const char*) (sqlite3_column_text(stmt,1));
        string stuff = (const char* ) (sqlite3_column_text(stmt,2));
        string another = (const char* ) (sqlite3_column_text(stmt,3));
        addToTree(id,service,stuff,another);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
void complate::displayData(){
    system("cls");
    cout<<"\n\n\t\t\t Display Record ";
    int c = 0;
    if(head == NULL){
        cout<<"\n\nCircular is empty...";
    }
    else{
        node *ptr = head;
        while(c != Size){
            cout<<"\n\n Value : "<<ptr->id<<" \t"<<ptr->service<<"\t "<<ptr->stuff<<"\t "<<ptr->another;
            ptr = ptr->next;
            c++;
        }

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
    cout<<"\n\n 4. Connection  Record   ";
    cout<<"\n\n 5. Quiz Program   ";
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
            search_guest();
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
    getch();

}
class manage:public complate{
public:
    void menu();

};
void manage::menu(){
    p:
    system("cls");
    int choice;
    string ch;
    string pin,pass,email;
    cout<<"\n\n\t\t\t Control Panel ";
    cout<<"\n\n 1.Bank Management ";
    cout<<"\n\n 2.LOAD Management ";
    cout<<"\n\n 3.Customer Coplate ";
    cout<<"\n\n 4. Exit ";
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
                link::menu1();
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
            pay::menu2();
        }break;
        case 3:{
            complate::man();
        }break;
        case 4:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
class staff:public manage{
protected:
    struct node{
        string id;
        string name;
        string position;
        double day_salary;
        double monther_salary;
        int costomer;
        string time;
        string timeStarWork;
        string work;
    };
public:
    void conData();
    void conInsert();
    void conSalary();
    void man1();
};
void staff::conData(){
    if(sqlite3_open("phanha.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Staff(id VARCHAR(50),name VARCHAR(50),position VARCHAR(50),day_salary DOUBLE,monther_salary DOUBLE,costomer INT,timeStarWork VARCHAR(80),work VARCHAR(80),time VARCHAR(80));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void staff::conInsert(){
        string id;
        string name;
        string position;
        double day_salary;
        double monther_salary;
        int costomer;
        string time;
        string timeStarWork;
        string work;

        cout<<"\n\n Input ID : ";
        fflush(stdin);
        getline(cin,id);

        cout<<"\n\n Input Name : ";
        fflush(stdin);
        getline(cin,name);

        cout<<"\n\n Input Position : ";
        fflush(stdin);
        getline(cin,position);

        cout<<"\n\n Input Day Salary : ";
        cin>>day_salary;

        cout<<"\n\n Input Monther Salary : ";
        cin>>monther_salary;

        costomer = 0;

        cout<<"\n\n Input Time to Work : ";
        fflush(stdin);
        getline(cin,timeStarWork);

        cout<<"\n\n Input Work : ";
        fflush(stdin);
        getline(cin,work);

        cout<<"\n\n Time start Work : ";
        fflush(stdin);
        getline(cin,time);

        result = sqlite3_open("phanha.db",&db);
        string quary = "INSERT INTO Staff(id, name, position, day_salary, monther_salary, costomer, timeStarWork, work, time ) VALUES(?,?,?,?,?,?,?,?,?);" ;
        result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, id.c_str(), id.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, position.c_str(), position.length(), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 4, day_salary);
        sqlite3_bind_double(stmt, 5, monther_salary);
        sqlite3_bind_int(stmt, 6, costomer);
        sqlite3_bind_text(stmt, 7, timeStarWork.c_str(), timeStarWork.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 8, work.c_str(), work.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 9, time.c_str(), time.length(), SQLITE_TRANSIENT);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);

        if(result != SQLITE_OK){
            cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<" Data Successfully \n";
        }
}
void staff::conSalary(){
    result = sqlite3_open("phanha.db",&db);
    query = "SELECT rowid, * FROM Staff";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<" ERROR "<<sqlite3_errmsg<<endl;
    }else{
        while((result = sqlite3_step(stmt)) == SQLITE_ROW){
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<< " "
            <<setw(25)<<sqlite3_column_text(stmt, 1)<<" \t"
            <<setw(25)<<sqlite3_column_text(stmt, 2)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 3)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 4)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 5)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 6)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 7)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 8)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 9)<<" \t"<<endl;
        }
        if(result != SQLITE_OK){
            cout<<" Error : "<<sqlite3_errmsg(db)<<endl;
        }
        cout<<"\n--------------------------------------------------------------------------------------------\n";
    }
}
void staff::man1(){
    conData();
    system("cls");
    int option;
    p:
    cout<<"\n\n 1. Insert Information Staff "<<endl;
    cout<<"\n\n 2. Display Information Staff "<<endl;
    cout<<"\n\n Select Option : ";
    cin>>option;
    switch(option){
        case 1:{
            conInsert();
        }break;
        case 2:{
            conSalary();
        }break;
        case 3:{
        }break;
        default:{
            cout<<"\n\n Invalid Choice ..."<<endl;
        }
    }
    goto p;
    getch();

}
class queue:public staff{
protected:
      struct node//  queue linked list
      {
          string id;
          int arr[20];
          string data;
          string name;
          string gender;
          int x,x1,x2;
          node *next;
      };
      string stk[10];//stack array
      node *head = NULL;
      node *tail = NULL;
public:
    void menu3();
    void menu4();
    void color(int color);
    void gotoxy(int x, int y);
    void load_data3();
    void push();
    void display();
    void pop();
    void push1();
    void push2(string searchid,int id,int number);
    void pop1();
    void display1();
};
void queue::color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void queue::gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void queue::push2(string searchid,int id,int number){
    string again;
    p:

    result = sqlite3_open("phanha.db",&db);
    query = "SELECT * FROM Staff";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,0));
        double day_salary = (sqlite3_column_double(stmt,3));
        int costomer = (sqlite3_column_double(stmt,5));
        if(searchid == Id){
                cout<<Id;

            cout<<"\n DO YOU WANT TO SAVING MONEY ?(YES/NO) : ";
            fflush(stdin);
            cin>>again;
            if(again =="YES" || again == "ýes"){
                 costomer += number;
                 day_salary += 3 * number;
                 query = "UPDATE Staff SET day_salary = ?, costomer = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, day_salary);
                 sqlite3_bind_double(stmt, 2, costomer);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu3();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }

    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void queue::push1(){
    system("cls");
    string idl,name;
    int id,option;
    int number;
    p:
    if(m > 9){
        cout<<"\n\n\t\t\t Stuff is full ...";
    }else{
        cout<<"\n\n Name OF Staff "<<endl;
        cout<<"\n\n 1. Phanha     "<<endl;
        cout<<"\n\n 2. Kaa        "<<endl;
        cout<<"\n\n 3. Makara     "<<endl;
        cout<<"\n\n 4.  Visal     "<<endl;
        cout<<"\n\n 5.  Yanut     "<<endl;
        cout<<"\n\n Who do you want to meet with ? : ";
        cin>>option;
        if(option == 1){
            name = "Phanha";
            idl = "e20200836";
            id = 1;
            number = 1;
        }else if(option == 2){
            name = "Kaa";
            idl = "e20200837";
            id = 2;
            number = 1;
        }else if(option == 3){
            name = "Makara";
            idl = "e20200838";
            id = 3;
            number = 1;
        }else if(option == 4){
            name = "Visal";
            idl = "e20200839";
            id = 4;
            number = 1;
        }else if(option == 5){
            name = "Yanut";
            idl = "e20200840";
            id = 5;
            number = 1;
        }else{
            cout<<"\n\n Invalid Choice ..."<<endl;
            goto p;
            getch();
        }
        cout<<idl<<"\t"<<id<<"\t"<<number<<endl;
        push2(idl,id,number);
        stk[++m] = name;
        cout<<"\n\n\t\t\t Name : "<<name<<" Successfully ....";
    }
}
void queue::pop1(){
    system("cls");
    if(m < 0){
        cout<<"\n\n\t\t\t Empty ...";
    }else{
        cout<<"\n\n "<<stk[m--]<<"Delete Successful ...";
    }
}
void queue::display1(){
    system("cls");
    cout<<endl;
    if(m < 0){
        cout<<"\n\n\t\t\t No Stuff ...";
    }else{
        for(int a=m; a>=0; a--){
            cout<<"\n\n\t\t\t Name :  "<<stk[a]<<endl;
        }
    }
}
void queue::load_data3(){
    fstream file;
    string emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    file.open("table.txt",ios::in);
    if(file){
        file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        while(!file.eof()){
            node *new_node = new node;
            new_node->id = emp_id;
            new_node->data = emp_data;
            new_node->name = emp_name;
            new_node->gender = emp_gender;
            new_node->x = emp_x;
            new_node->x1 = emp_x1;
            new_node->x2 = emp_x2;
            new_node->next = NULL;
            if(head == NULL){
                head = new_node;
                tail = new_node;
            }else{
                tail -> next = new_node;
                tail = new_node;
            }
            file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        }
        file.close();
    }
}
void queue::push()
{
    fstream file;
    SYSTEMTIME x;
    system("cls");
    string emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    cout<<"\n\n\t\t\t\t Push Record";
    cout<<"\n\n\t\t\t Enter ID : ";
    cin>>emp_id;
    cout<<"\n\n\t\t\t Your Function : ";
    cin>>emp_data;
    cout<<"\n\n\t\t\t Your Name : ";
    cin>>emp_name;
    cout<<"\n\n\t\t\t Your Gender : ";
    cin>>emp_gender;
    GetSystemTime(&x);
    emp_x = x.wHour;
    emp_x1 = x.wSecond;
    emp_x2 = x.wMilliseconds;
    node *new_node = new node;
    new_node->id = emp_id;
    new_node->data = emp_data;
    new_node->name = emp_name;
    new_node->gender = emp_gender;
    new_node->x = emp_x;
    new_node->x1 = emp_x1;
    new_node->x2 = emp_x2;
    new_node -> next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }else{
        tail -> next = new_node;
        tail = new_node;
    }
    file.open("table.txt",ios::app|ios::out);
    file<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<" \n";
    file.close();
}
void queue::display()
{
    system("cls");
    SYSTEMTIME x;
    int k = 0;
    cout<<"\n\n\t\t\t\tDisplay Record"<<endl;
    if(head == NULL){
        cout<<"\n\n Queue is Empty..."<<endl;
    }else{
        node *ptr = head;
        while(ptr != NULL){
                 GetSystemTime(&x);
                 int n = sizeof(ptr->arr)/sizeof(ptr->arr[0]) - ++i;
                 system("color 0B");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  TABLE PLEASE SITDOWN  :    "<<++k<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<"    ID       : "<< ptr->id <<endl;
                 cout<<"\t\t\t\t\t"<<"    FUNCTION : "<< ptr->data <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME     : "<< ptr->name <<endl;
                 cout<<"\t\t\t\t\t"<<"    GENDER   : "<< ptr->gender <<endl;
                 cout<<"\t\t\t\t\t"<<"   TABLE FREE: "<< n<<endl;
                 cout<<"\t\t\t\t\t"<<"    TIME     : "<< ptr->x<<":"<<ptr->x1<<":"<<ptr->x2<<endl;
                 cout<<"\t\t\t\t\t"<<"    DATE     : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 ptr=ptr -> next;
        }
    }
}
void queue::pop(){
    system("cls");
    fstream file,file1;
    string t_id,emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    int found = 0;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  4. Delete ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("table.txt",ios::in);
        file1.open("table1.txt",ios::app|ios::out);
        file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        while(!file.eof()){
            if(t_id == emp_id){
                system("color 0C");
                cout<<"\t\t\t\t\t";
                for(int j=0;j<=31;j++)
                cout<<load;
                cout<<"\n";
                cout<<"\t\t\t\t\t"<<load<<"----------------------------  "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"      Delete ALL  Record      "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<" ---------------------------  "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"  Delete Record Successfully.."<<load<<endl;
                cout<<"\t\t\t\t\t";
                for(int j=0;j<=31;j++)
                cout<<load;
                cout<<"\n";
                found++;

            }
            else{
                file1<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<"\n";
            }
            file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        }
        file.close();
        file1.close();
        remove("table.txt");
        rename("table1.txt","table.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void queue::menu4(){
    staff::conData();
    int choice;
    p:
    system("cls");
    cout<<"\n\n\t\t\t Control Panel ";
    cout<<"\n\n 1. Push Record ";
    cout<<"\n\n 2. Pop Record ";
    cout<<"\n\n 3. Display Record ";
    cout<<"\n\n 4. Back ";
    cout<<"\n\n 5. Staff Information ";
    cout<<"\n\n 6. Exit ";
    cout<<"\n\n Select Option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            push1();
        }break;
        case 2:{
            pop1();
        }break;
        case 3:{
            display1();
        }break;
        case 4:{
            menu3();
        }break;
        case 5:{
            staff::man1();
        }break;
        case 6:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n\t\t\t Invalid ...";
        }
    }
    getch();
    goto p;
}
void queue::menu3(){
    system("cls");
    int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
    int counter = 3;
    char key;
    cout<<"\n\n";
    for(int i=0;;)
    {
        gotoxy(10,5);
        color(Set[0]);
        cout<<"\n1. Menu Stuff ";

        gotoxy(10,6);
        color(Set[1]);
        cout<<"\n2. Login ";

        gotoxy(10,7);
        color(Set[2]);
        cout<<"\n3. Service Back ";

        gotoxy(10,8);
        color(Set[3]);
        cout<<"\n4. Go to Service";

        gotoxy(10,9);
        color(Set[4]);
        cout<<"\n5. Extra_2";

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 5))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 4))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                cout<<"\nMenu 1 is Open";
            }
            if(counter == 2)
            {
                cout<<"Menu 2 is Open";
                push();
            }
            if(counter == 3)
            {
                cout<<"Menu 3 is Open";
                head = NULL;
                load_data3();
                display();
            }
            if(counter == 4)
            {
                cout<<"Menu 4 is Open\n";
                head = NULL;
                load_data3();
                pop();
                menu4();
            }
            if(counter == 5)
            {
                cout<<"Menu 5 is Open";
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if(counter == 1)
        {
            Set[0] = 12;
        }
        if(counter == 2)
        {
            Set[1] = 12;
        }
        if(counter == 3)
        {
            Set[2] = 12;
        }
        if(counter == 4)
        {
            Set[3] = 12;
        }
        if(counter == 5)
        {
            Set[4] = 12;
        }
    }
}
int main(){
    queue q;
    q.menu3();
    sqlite3_close(db);
}


