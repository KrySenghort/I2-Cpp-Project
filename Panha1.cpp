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
