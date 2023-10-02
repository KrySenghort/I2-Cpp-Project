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
char load=219;
int i=0;
int m = -1;
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
    void connection1();
    void menu1();
    void load_data();
    void insert_record();
    void search_record();
    void edit_record();
    void del();
    void show_record();
    void timetable();
};
void link::connection1(){
    if(sqlite3_open("load.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS apple(pin INT,id VARCHAR(50),pass VARCHAR(50), name VARCHAR(50), father VARCHAR(50), address VARCHAR(50),phone VARCHAR(50),balance DOUBLE , balancereil DOUBLE );", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void link::load_data(){
    int pin1;
    long double balance1;
    long double balanceriel1;
    string id1,pass1,name1,fname1,mname1,suportname1,address1,phone1;
    string birday1,job1,plan_load1;
    int n1;
    
            node *new_node = new node;
            new_node->id = id1;
            new_node->pass = pass1;
            new_node->name = name1;
            new_node->fname = fname1;
            new_node->mname = mname1;
            new_node->suportname = suportname1;
            new_node->address = address1;
            new_node->pin = pin1;
            new_node->birday = birday1;
            new_node->job = job1;
            new_node->plan_load = plan_load1;
            new_node->phone = phone1;
            new_node->balance = balance1;
            new_node->balanceriel = balanceriel1;
            new_node->n = n1;
            new_node->pre = NULL;
            new_node->next = NULL;
		    if(head == NULL){
			    head = new_node;
			    tail = new_node;
		    }else{
			    tail -> next = new_node;
			    new_node -> pre = tail;
			    tail = new_node;
		    }
      }
}
int main(){
    link l1;
    l1.connection1();
    l1.load_data();

    return 0;
}










